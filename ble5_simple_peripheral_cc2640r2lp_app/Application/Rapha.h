
/******************************************************************************

 @file       Rapha.c

 @brief This file contains RAPHA apps

 Group: CMCU, SCS
 Target Device: CC2640R2

 ******************************************************************************
*/

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
//
//#ifndef RAPHA_H
//#define RAPHA_H

/*********************************************************************
 * INCLUDES
 */

/*********************************************************************
*  EXTERNAL VARIABLES
*/

/*********************************************************************
 * CONSTANTS
 */

/*********************************************************************
 * MACROS
 */
typedef struct RaphaStruct{
    Queue_Elem elem;
    uint8_t SetupLevel; // IDLE = 0, Runn = 1 , Paused = 2
    uint8_t SetupTimerMinutes;
    uint8_t State;
    uint8_t TimeRemainingMinutes;
    uint8_t TimeRemainingSeconds;
}RaphaStruct;
/*********************************************************************
 * FUNCTIONS
 */

extern void Rapha_createTask(void);


//#endif /* RAPHA_H */
