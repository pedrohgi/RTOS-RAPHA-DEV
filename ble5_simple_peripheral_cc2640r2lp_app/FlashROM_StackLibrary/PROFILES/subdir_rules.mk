################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
PROFILES/%.obj: ../PROFILES/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/home/inazawalabs/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" --cmd_file="/home/inazawalabs/workspace_v8_1/ble5_simple_peripheral_cc2640r2lp_app/TOOLS/defines/ble5_simple_peripheral_cc2640r2lp_app_FlashROM_StackLibrary.opt" --cmd_file="/home/inazawalabs/ti/simplelink_cc2640r2_sdk_2_20_00_49/source/ti/ble5stack/config/build_components.opt" --cmd_file="/home/inazawalabs/ti/simplelink_cc2640r2_sdk_2_20_00_49/source/ti/ble5stack/config/factory_config.opt" --cmd_file="/home/inazawalabs/workspace_v8_1/ble5_simple_peripheral_cc2640r2lp_stack_library/TOOLS/build_config.opt"  -mv7M3 --code_state=16 -me -O4 --opt_for_speed=0 --include_path="/home/inazawalabs/workspace_v8_1/ble5_simple_peripheral_cc2640r2lp_app" --include_path="/home/inazawalabs/workspace_v8_1/ble5_simple_peripheral_cc2640r2lp_app/Application" --include_path="/home/inazawalabs/workspace_v8_1/ble5_simple_peripheral_cc2640r2lp_app/Startup" --include_path="/home/inazawalabs/workspace_v8_1/ble5_simple_peripheral_cc2640r2lp_app/PROFILES" --include_path="/home/inazawalabs/workspace_v8_1/ble5_simple_peripheral_cc2640r2lp_app/Include" --include_path="/home/inazawalabs/ti/simplelink_cc2640r2_sdk_2_20_00_49/source/ti/ble5stack/controller/cc26xx/inc" --include_path="/home/inazawalabs/ti/simplelink_cc2640r2_sdk_2_20_00_49/source/ti/ble5stack/inc" --include_path="/home/inazawalabs/ti/simplelink_cc2640r2_sdk_2_20_00_49/source/ti/ble5stack/rom" --include_path="/home/inazawalabs/ti/simplelink_cc2640r2_sdk_2_20_00_49/source/ti/ble5stack/common/cc26xx" --include_path="/home/inazawalabs/ti/simplelink_cc2640r2_sdk_2_20_00_49/source/ti/ble5stack/icall/inc" --include_path="/home/inazawalabs/ti/simplelink_cc2640r2_sdk_2_20_00_49/source/ti/ble5stack/target" --include_path="/home/inazawalabs/ti/simplelink_cc2640r2_sdk_2_20_00_49/source/ti/ble5stack/hal/src/target/_common" --include_path="/home/inazawalabs/ti/simplelink_cc2640r2_sdk_2_20_00_49/source/ti/ble5stack/hal/src/target/_common/cc26xx" --include_path="/home/inazawalabs/ti/simplelink_cc2640r2_sdk_2_20_00_49/source/ti/ble5stack/hal/src/inc" --include_path="/home/inazawalabs/ti/simplelink_cc2640r2_sdk_2_20_00_49/source/ti/ble5stack/heapmgr" --include_path="/home/inazawalabs/ti/simplelink_cc2640r2_sdk_2_20_00_49/source/ti/ble5stack/icall/src/inc" --include_path="/home/inazawalabs/ti/simplelink_cc2640r2_sdk_2_20_00_49/source/ti/ble5stack/osal/src/inc" --include_path="/home/inazawalabs/ti/simplelink_cc2640r2_sdk_2_20_00_49/source/ti/ble5stack/services/src/saddr" --include_path="/home/inazawalabs/ti/simplelink_cc2640r2_sdk_2_20_00_49/source/ti/ble5stack/services/src/sdata" --include_path="/home/inazawalabs/ti/simplelink_cc2640r2_sdk_2_20_00_49/source/ti/devices/cc26x0r2" --include_path="/home/inazawalabs/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --define=DeviceFamily_CC26X0R2 -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="PROFILES/$(basename $(<F)).d_raw" --obj_directory="PROFILES" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


