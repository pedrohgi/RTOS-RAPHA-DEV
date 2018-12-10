# RTOS-RAPHA-DEV
This is an implementation of the firmware related to the RAPHA Project.  
This software runs in a TI CC2640R2 ARM CORTEX MCU, and is compiled using Code Composer v.8.1.0

# What this project do?

This software is a bluetooth-Controlled LED timer, basically. The timer has 3 main functionalities (IDLE, RUNNING and PAUSE).

The software starts at IDLE. Then, by bluetooth , the user sets the session timer and the light power. The user changes the state of the device from IDLE to RUNNING, and the software starts the temporization. If necessary, the user can setup a PAUSE. The timer will halt until the next RUNNING or IDLE command. 

The RED LED in the device is the LED being controlled.
The GREEN LED in the device is the "Heartbeat". It will toggle on-off when the timer is running, will be ON when the device is paused, and will be OFF when the device is IDLE.

## How To...
In order to run this project, you must follow these steps:

1) Download the SDK for CC2640R2 (http://www.ti.com/tool/download/SIMPLELINK-CC2640R2-SDK) and install CCS (Code 
Composer Studio) from Texas Inc. (http://www.ti.com/tool/CCSTUDIO).

2) Extract the SDK to the directory inside CCS' ti folder (/home/<YourUserName>/ti/)

3) Clone the repo to your home git directory (/home/<YourUserName>/git/Firmware)

4) Import the project to your workspace inside CCS (File->Import->CCS Project)

5) Import the build variables file, vars.ini (Right click on project -> Import -> Search build variables)

6) Import the stack library project from the SDK folder (Files -> Import -> CCS Project -> Search the folder for blestack/(stack library))
***MAKE SURE THE STACK LIBRARY IS INSIDE YOUR WORKSPACE FOLDER!***
7) Build the stack library first, using the FlashROM_stack configuration

8) Build the ble app

9) Flash to the board. Have fun =)

## How it works...

In order to test this software, you must have a device compatible with BLE. In our case, we used an ANDROID phone with the app "BLE Scanner" (https://play.google.com/store/apps/details?id=com.macdom.ble.blescanner&hl=pt_BR)

1) After Flashing the device, you should see in you BLE scanner a device called "RaphaSaysHello". This is your target Device.

2) Click on it, and  you should see Many services. The one used to control the LED functionalities is the "CUSTOM SERVICE". 
The other ones are for device-specific features, e.g. Serial Numbers and are not useful right now. 

3) Inside this Custom Service, there is a Custom Characteristic called 'RaphaUnifiedString' (This name should be visible once you READ the descriptor of this characteristic). This contain an attribute that is an ARRAY of 5 elements. Their description is below:

| Index in Array 	| Name                        	| Requirement 	| Mandatory Proprerties 	| Security Permissions 	| Descriptions                                                                                                                                                                                                                                                                                                                                                                                                                                       	|
|----------------	|-----------------------------	|-------------	|-----------------------	|----------------------	|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	|
| 0              	| RaphaLightLevel             	| Mandatory   	| R/W                   	| None                 	| This command controls the red LED emission Power.   Operation: READ: Returns the current Light Level.            WRITE: Sets the Light level of the procedure.   Value = [0,255] Type: UINT8_t                                                                                                                                                                                                                                                     	|
| 1              	| RaphaSetupTimer             	| Mandatory   	| R/W                   	| None                 	| This value sets the full procedure time in MINUTES.   Operation: READ - Returns current Procedure duration.            WRITE - Sets the Procedure Duration.  Value = [0,255] Type: UINT8_t                                                                                                                                                                                                                                                         	|
| 2              	| RaphaCurrentState           	| Mandatory   	| R/W                   	| None                 	| This value is used to indicate and also to control the states of the device.   Operation: READ - Returns the current state            WRITE - Sets the state. Once set, a new "procedure" will begin with the configuration given in  RaphaSetupTimer and RaphaLightLevel  Values = [0 - IDLE]          [1 - RUNN (rapha is perfoming a treatment. Timer will be decreased)]          [2 - PAUSE (Rapha is paused. Timer has temporarily stopped)] 	|
| 3              	| RaphaTimeRemainingInMinutes 	| Mandatory   	| Read-only             	|  None                	| During the procedures, this value holds the time remaining to end the session. This will hold the part that accounts for more than one minute.  Operation: READ - Returns a decrescent timer (from RaphaSetupTimer to 0) that shows the remaining time to end session.  Values = [0, 255] Type: UINT8_t                                                                                                                                            	|
| 4              	| RaphaTimeRemainingInSeconds 	| Mandatory   	|  Read-only            	| None                 	| During the procedures, this value holds the time remaining to end the session. This will hold the part that accounts for more than one minute.                                                                                                                                                                                                                                                                                                     	|

# License

The authors of this code are Pedro Inazawa (https://github.com/pedrohgi) and Gabriel Williams.
This code is Licensed under GNU GPLv3 

 This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>5.

=======
