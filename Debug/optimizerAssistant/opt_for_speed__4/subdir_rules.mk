################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
FlameSensor_Main.obj: ../FlameSensor_Main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.6/bin/cl430" -vmspx --abi=eabi --code_model=large --data_model=restricted --near_data=none --opt_for_speed=4 --use_hw_mpy=F5 --include_path="C:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/CCS/Flame_Sensor/Source" --include_path="D:/CCS/Flame_Sensor/driverlib/MSP430FR5xx_6xx" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.6/include" --advice:power="1,2,3,5,6,7,8,9,10,11,12,13,14,15" --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_MPU_ENABLE --display_error_number --diag_wrap=off --diag_warning=225 --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="FlameSensor_Main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


