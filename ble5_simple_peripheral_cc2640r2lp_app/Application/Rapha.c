/******************************************************************************

 @file       Rapha.c

 @brief This file contains RAPHA apps

 Group: CMCU, SCS
 Target Device: CC2640R2

 ******************************************************************************/
/*This file is part of RTOS-RAPHA-DEV.

    RTOS-RAPHA-DEV. is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    RTOS-RAPHA-DEV. is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with RTOS-RAPHA-DEV..  If not, see <https://www.gnu.org/licenses/>6.*/

#include <stdint.h>
#include <stddef.h>

/* Driver Header files */
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>
#include <ti/sysbios/knl/Queue.h>

#if !(defined __TI_COMPILER_VERSION__)
#include <intrinsics.h>
#endif

/* Example/Board Header files */
#include <board.h>
#include "Rapha.h"

#define SP_TASK_PRIORITY                     1

#ifndef SP_TASK_STACK_SIZE
#define SP_TASK_STACK_SIZE                   644
#endif

// Task configuration
Task_Struct RaphaspTask;
#if defined __TI_COMPILER_VERSION__
#pragma DATA_ALIGN(RaphaSpTaskStack, 8)
#else
#pragma data_alignment=8
#endif
uint8_t RaphaSpTaskStack[SP_TASK_STACK_SIZE];

uint16_t CurrentTimer = 0;
uint8_t CurrentState = 0;
uint8_t CurrentSetupLevel = 0;
uint16_t CurrentTimeRemaining = 0;

static void Rapha_taskFxn(UArg a0, UArg a1);

/*********************************************************************
 * @fn      Rapha_createTask
 *
 * @brief   Task creation function for Rapha
 */
void Rapha_createTask(void)
{
  Task_Params taskParams;

  // Configure task
  Task_Params_init(&taskParams);
  taskParams.stack = RaphaSpTaskStack;
  taskParams.stackSize = SP_TASK_STACK_SIZE;
  taskParams.priority = SP_TASK_PRIORITY;

  Task_construct(&RaphaspTask, Rapha_taskFxn, &taskParams, NULL);
}

/*********************************************************************
 * @fn      Rapha_taskFxn
 *
 * @brief   Application task entry point for the Simple Peripheral.
 *
 * @param   a0, a1 - not used.
 */
static void Rapha_taskFxn(UArg a0, UArg a1)
{	
    extern Queue_Handle RaphaBTQueue;

    RaphaStruct* ReceivedInfo;

	/* Call driver init functions */
	GPIO_init();
	 /* Configure the LED pin */
    GPIO_setConfig(Board_GPIO_LED0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(Board_GPIO_LED1, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    /* Turn off LEDs */
    GPIO_write(Board_GPIO_LED0, Board_GPIO_LED_OFF);
    GPIO_write(Board_GPIO_LED1, Board_GPIO_LED_OFF);

    for(;;)
    {
        if(!Queue_empty(RaphaBTQueue))
        {
            ReceivedInfo = Queue_dequeue(RaphaBTQueue);

            if(CurrentState == 0 & ReceivedInfo->State == 1)
            {
                // RAPHA is leaving IDLE and going to RUNN state
                CurrentSetupLevel = ReceivedInfo->SetupLevel;
                CurrentTimer = (ReceivedInfo->SetupTimerMinutes) * 60 ;
                CurrentState = ReceivedInfo->State;

                // Turn RedLED ON and let GreenLed be refreshed
                GPIO_write(Board_GPIO_LED0,Board_GPIO_LED_ON);
                CurrentTimeRemaining = CurrentTimer;
            }
            else if(CurrentState == 1 & ReceivedInfo->State == 2)
            {
                // Rapha was in RUNN state and user wants to Pause
                CurrentState = ReceivedInfo->State;

                // Turn RedLed OFF and Freeze greenLED in ON
                GPIO_write(Board_GPIO_LED0,Board_GPIO_LED_OFF);
                GPIO_write(Board_GPIO_LED1,Board_GPIO_LED_ON);
            }
            else if((CurrentState == 1 & ReceivedInfo->State == 0) | (CurrentState == 2 & ReceivedInfo->State == 0))
            {

                //Rapha was ON and the user wants to CANCEL the session.
                CurrentState = ReceivedInfo->State;
                // Turn RedLed and greenLED OFF
                GPIO_write(Board_GPIO_LED0,Board_GPIO_LED_OFF);
                GPIO_write(Board_GPIO_LED1,Board_GPIO_LED_OFF);
            }
            else if(CurrentState == 2 & ReceivedInfo->State == 1)
           {
               // Rapha was in PAUSE state and user wants to RUN
               CurrentState = ReceivedInfo->State;
               GPIO_write(Board_GPIO_LED0,Board_GPIO_LED_ON);
           }
        }

        // This part will upgrade the counter.
        if(CurrentState == 1)
        {
            if(CurrentTimeRemaining == 0)
            {
                GPIO_write(Board_GPIO_LED1,Board_GPIO_LED_OFF);
                GPIO_write(Board_GPIO_LED0,Board_GPIO_LED_OFF);
                CurrentState = 0;
                CurrentTimer = 0;
            }
            else
            {
                GPIO_toggle(Board_GPIO_LED1);
                CurrentTimeRemaining--;
            }
        }


        // 1 second delay
        Task_sleep(1000 * (1000 / Clock_tickPeriod));
    }

}
