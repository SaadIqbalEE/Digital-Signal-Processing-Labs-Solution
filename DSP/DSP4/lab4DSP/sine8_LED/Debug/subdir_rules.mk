################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Sine8_LED.obj: ../Sine8_LED.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"c:/ti/ccsv6/tools/compiler/c6000_7.4.8/bin/cl6x" -mv6713 --abi=coffabi -g --include_path="c:/ti/ccsv6/tools/compiler/c6000_7.4.8/include" --include_path="C:/ti/Support" --include_path="C:/ti/DSK6713/DSK6713/c6000/dsk6713/include" --include_path="C:/ti/C6xCSL/include" --define=CHIP_6713 --display_error_number --diag_warning=225 --diag_wrap=off --mem_model:const=far --mem_model:data=far --preproc_with_compile --preproc_dependency="Sine8_LED.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Vectors_poll.obj: ../Vectors_poll.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"c:/ti/ccsv6/tools/compiler/c6000_7.4.8/bin/cl6x" -mv6713 --abi=coffabi -g --include_path="c:/ti/ccsv6/tools/compiler/c6000_7.4.8/include" --include_path="C:/ti/Support" --include_path="C:/ti/DSK6713/DSK6713/c6000/dsk6713/include" --include_path="C:/ti/C6xCSL/include" --define=CHIP_6713 --display_error_number --diag_warning=225 --diag_wrap=off --mem_model:const=far --mem_model:data=far --preproc_with_compile --preproc_dependency="Vectors_poll.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

c6713dskinit.obj: ../c6713dskinit.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"c:/ti/ccsv6/tools/compiler/c6000_7.4.8/bin/cl6x" -mv6713 --abi=coffabi -g --include_path="c:/ti/ccsv6/tools/compiler/c6000_7.4.8/include" --include_path="C:/ti/Support" --include_path="C:/ti/DSK6713/DSK6713/c6000/dsk6713/include" --include_path="C:/ti/C6xCSL/include" --define=CHIP_6713 --display_error_number --diag_warning=225 --diag_wrap=off --mem_model:const=far --mem_model:data=far --preproc_with_compile --preproc_dependency="c6713dskinit.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


