################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../src/ \
../src/ASF/ \
../src/ASF/avr32/ \
../src/ASF/avr32/drivers/ \
../src/ASF/avr32/drivers/gpio/ \
../src/ASF/avr32/drivers/intc/ \
../src/ASF/avr32/drivers/twim/ \
../src/ASF/avr32/utils/ \
../src/ASF/avr32/utils/header_files/ \
../src/ASF/avr32/utils/make/ \
../src/ASF/avr32/utils/preprocessor/ \
../src/ASF/avr32/utils/startup/ \
../src/ASF/common/ \
../src/ASF/common/boards/ \
../src/ASF/common/boards/user_board/ \
../src/ASF/common/utils/ \
../src/ASF/common/utils/interrupt/ \
../src/config/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../src/ASF/avr32/drivers/gpio/gpio.c \
../src/ASF/avr32/drivers/intc/intc.c \
../src/ASF/avr32/drivers/twim/twim.c \
../src/ASF/common/boards/user_board/init.c \
../src/main.c


PREPROCESSING_SRCS +=  \
../src/ASF/avr32/drivers/intc/exception.S \
../src/ASF/avr32/utils/startup/startup_uc3.S \
../src/ASF/avr32/utils/startup/trampoline_uc3.S


ASM_SRCS += 


OBJS +=  \
src/ASF/avr32/drivers/gpio/gpio.o \
src/ASF/avr32/drivers/intc/exception.o \
src/ASF/avr32/drivers/intc/intc.o \
src/ASF/avr32/drivers/twim/twim.o \
src/ASF/avr32/utils/startup/startup_uc3.o \
src/ASF/avr32/utils/startup/trampoline_uc3.o \
src/ASF/common/boards/user_board/init.o \
src/main.o

OBJS_AS_ARGS +=  \
src/ASF/avr32/drivers/gpio/gpio.o \
src/ASF/avr32/drivers/intc/exception.o \
src/ASF/avr32/drivers/intc/intc.o \
src/ASF/avr32/drivers/twim/twim.o \
src/ASF/avr32/utils/startup/startup_uc3.o \
src/ASF/avr32/utils/startup/trampoline_uc3.o \
src/ASF/common/boards/user_board/init.o \
src/main.o

C_DEPS +=  \
src/ASF/avr32/drivers/gpio/gpio.d \
src/ASF/avr32/drivers/intc/exception.d \
src/ASF/avr32/drivers/intc/intc.d \
src/ASF/avr32/drivers/twim/twim.d \
src/ASF/avr32/utils/startup/startup_uc3.d \
src/ASF/avr32/utils/startup/trampoline_uc3.d \
src/ASF/common/boards/user_board/init.d \
src/main.d

C_DEPS_AS_ARGS +=  \
src/ASF/avr32/drivers/gpio/gpio.d \
src/ASF/avr32/drivers/intc/exception.d \
src/ASF/avr32/drivers/intc/intc.d \
src/ASF/avr32/drivers/twim/twim.d \
src/ASF/avr32/utils/startup/startup_uc3.d \
src/ASF/avr32/utils/startup/trampoline_uc3.d \
src/ASF/common/boards/user_board/init.d \
src/main.d

OUTPUT_FILE_PATH +=Regler.elf

OUTPUT_FILE_PATH_AS_ARGS +=Regler.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler











src/ASF/avr32/drivers/gpio/%.o: ../src/ASF/avr32/drivers/gpio/%.c
	@echo Building file: $<
	@echo Invoking: AVR32/GNU C Compiler : 4.4.7
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-gcc.exe$(QUOTE)  -x c -DDEBUG -DBOARD=USER_BOARD  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\UC3D_DFP\1.0.31\include\ATUC64D4" -I"../common/applications/user_application/user_board/config" -I"../src/config" -I"../src" -I"../src/ASF/common/boards/user_board" -I"../src/ASF/common/boards" -I"../src/ASF/avr32/utils/preprocessor" -I"../src/ASF/avr32/utils" -I"../src/ASF/common/utils" -I"../src/ASF/avr32/drivers/intc" -I"../src/ASF/avr32/drivers/gpio" -I"../src/ASF/avr32/drivers/twim"  -O1 -fdata-sections -ffunction-sections -masm-addr-pseudos -g3 -Wall -mpart=uc64d4 -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -mno-cond-exec-before-reload -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/avr32/drivers/intc/%.o: ../src/ASF/avr32/drivers/intc/%.c
	@echo Building file: $<
	@echo Invoking: AVR32/GNU C Compiler : 4.4.7
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-gcc.exe$(QUOTE)  -x c -DDEBUG -DBOARD=USER_BOARD  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\UC3D_DFP\1.0.31\include\ATUC64D4" -I"../common/applications/user_application/user_board/config" -I"../src/config" -I"../src" -I"../src/ASF/common/boards/user_board" -I"../src/ASF/common/boards" -I"../src/ASF/avr32/utils/preprocessor" -I"../src/ASF/avr32/utils" -I"../src/ASF/common/utils" -I"../src/ASF/avr32/drivers/intc" -I"../src/ASF/avr32/drivers/gpio" -I"../src/ASF/avr32/drivers/twim"  -O1 -fdata-sections -ffunction-sections -masm-addr-pseudos -g3 -Wall -mpart=uc64d4 -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -mno-cond-exec-before-reload -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/avr32/drivers/twim/%.o: ../src/ASF/avr32/drivers/twim/%.c
	@echo Building file: $<
	@echo Invoking: AVR32/GNU C Compiler : 4.4.7
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-gcc.exe$(QUOTE)  -x c -DDEBUG -DBOARD=USER_BOARD  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\UC3D_DFP\1.0.31\include\ATUC64D4" -I"../common/applications/user_application/user_board/config" -I"../src/config" -I"../src" -I"../src/ASF/common/boards/user_board" -I"../src/ASF/common/boards" -I"../src/ASF/avr32/utils/preprocessor" -I"../src/ASF/avr32/utils" -I"../src/ASF/common/utils" -I"../src/ASF/avr32/drivers/intc" -I"../src/ASF/avr32/drivers/gpio" -I"../src/ASF/avr32/drivers/twim"  -O1 -fdata-sections -ffunction-sections -masm-addr-pseudos -g3 -Wall -mpart=uc64d4 -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -mno-cond-exec-before-reload -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/common/boards/user_board/%.o: ../src/ASF/common/boards/user_board/%.c
	@echo Building file: $<
	@echo Invoking: AVR32/GNU C Compiler : 4.4.7
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-gcc.exe$(QUOTE)  -x c -DDEBUG -DBOARD=USER_BOARD  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\UC3D_DFP\1.0.31\include\ATUC64D4" -I"../common/applications/user_application/user_board/config" -I"../src/config" -I"../src" -I"../src/ASF/common/boards/user_board" -I"../src/ASF/common/boards" -I"../src/ASF/avr32/utils/preprocessor" -I"../src/ASF/avr32/utils" -I"../src/ASF/common/utils" -I"../src/ASF/avr32/drivers/intc" -I"../src/ASF/avr32/drivers/gpio" -I"../src/ASF/avr32/drivers/twim"  -O1 -fdata-sections -ffunction-sections -masm-addr-pseudos -g3 -Wall -mpart=uc64d4 -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -mno-cond-exec-before-reload -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: AVR32/GNU C Compiler : 4.4.7
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-gcc.exe$(QUOTE)  -x c -DDEBUG -DBOARD=USER_BOARD  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\UC3D_DFP\1.0.31\include\ATUC64D4" -I"../common/applications/user_application/user_board/config" -I"../src/config" -I"../src" -I"../src/ASF/common/boards/user_board" -I"../src/ASF/common/boards" -I"../src/ASF/avr32/utils/preprocessor" -I"../src/ASF/avr32/utils" -I"../src/ASF/common/utils" -I"../src/ASF/avr32/drivers/intc" -I"../src/ASF/avr32/drivers/gpio" -I"../src/ASF/avr32/drivers/twim"  -O1 -fdata-sections -ffunction-sections -masm-addr-pseudos -g3 -Wall -mpart=uc64d4 -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -mno-cond-exec-before-reload -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler

src/ASF/avr32/drivers/intc/%.o: ../src/ASF/avr32/drivers/intc/%.S
	@echo Building file: $<
	@echo Invoking: AVR32/GNU Preprocessing Assembler : 4.4.7
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-gcc.exe$(QUOTE) -x assembler-with-cpp -c -mpart=uc64d4 -mrelax -DBOARD=USER_BOARD -I "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\UC3D_DFP\1.0.31\include\ATUC64D4" -I "../common/applications/user_application/user_board/config" -I "../src/config" -I "../src" -I "../src/ASF/common/boards/user_board" -I "../src/ASF/common/boards" -I "../src/ASF/avr32/utils/preprocessor" -I "../src/ASF/avr32/utils" -I "../src/ASF/common/utils" -I "../src/ASF/avr32/drivers/intc" -I "../src/ASF/avr32/drivers/gpio" -I "../src/ASF/avr32/drivers/twim"  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -Wa,-g   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/avr32/drivers/intc/%.o: ../src/ASF/avr32/drivers/intc/%.x
	@echo Building file: $<
	@echo Invoking: AVR32/GNU Preprocessing Assembler : 4.4.7
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-gcc.exe$(QUOTE) -x assembler-with-cpp -c -mpart=uc64d4 -mrelax -DBOARD=USER_BOARD -I "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\UC3D_DFP\1.0.31\include\ATUC64D4" -I "../common/applications/user_application/user_board/config" -I "../src/config" -I "../src" -I "../src/ASF/common/boards/user_board" -I "../src/ASF/common/boards" -I "../src/ASF/avr32/utils/preprocessor" -I "../src/ASF/avr32/utils" -I "../src/ASF/common/utils" -I "../src/ASF/avr32/drivers/intc" -I "../src/ASF/avr32/drivers/gpio" -I "../src/ASF/avr32/drivers/twim"  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -Wa,-g   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/avr32/drivers/intc/%.o: ../src/ASF/avr32/drivers/intc/%.X
	@echo Building file: $<
	@echo Invoking: AVR32/GNU Preprocessing Assembler : 4.4.7
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-gcc.exe$(QUOTE) -x assembler-with-cpp -c -mpart=uc64d4 -mrelax -DBOARD=USER_BOARD -I "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\UC3D_DFP\1.0.31\include\ATUC64D4" -I "../common/applications/user_application/user_board/config" -I "../src/config" -I "../src" -I "../src/ASF/common/boards/user_board" -I "../src/ASF/common/boards" -I "../src/ASF/avr32/utils/preprocessor" -I "../src/ASF/avr32/utils" -I "../src/ASF/common/utils" -I "../src/ASF/avr32/drivers/intc" -I "../src/ASF/avr32/drivers/gpio" -I "../src/ASF/avr32/drivers/twim"  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -Wa,-g   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/avr32/drivers/intc/%.o: ../src/ASF/avr32/drivers/intc/%.sx
	@echo Building file: $<
	@echo Invoking: AVR32/GNU Preprocessing Assembler : 4.4.7
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-gcc.exe$(QUOTE) -x assembler-with-cpp -c -mpart=uc64d4 -mrelax -DBOARD=USER_BOARD -I "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\UC3D_DFP\1.0.31\include\ATUC64D4" -I "../common/applications/user_application/user_board/config" -I "../src/config" -I "../src" -I "../src/ASF/common/boards/user_board" -I "../src/ASF/common/boards" -I "../src/ASF/avr32/utils/preprocessor" -I "../src/ASF/avr32/utils" -I "../src/ASF/common/utils" -I "../src/ASF/avr32/drivers/intc" -I "../src/ASF/avr32/drivers/gpio" -I "../src/ASF/avr32/drivers/twim"  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -Wa,-g   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/avr32/utils/startup/%.o: ../src/ASF/avr32/utils/startup/%.S
	@echo Building file: $<
	@echo Invoking: AVR32/GNU Preprocessing Assembler : 4.4.7
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-gcc.exe$(QUOTE) -x assembler-with-cpp -c -mpart=uc64d4 -mrelax -DBOARD=USER_BOARD -I "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\UC3D_DFP\1.0.31\include\ATUC64D4" -I "../common/applications/user_application/user_board/config" -I "../src/config" -I "../src" -I "../src/ASF/common/boards/user_board" -I "../src/ASF/common/boards" -I "../src/ASF/avr32/utils/preprocessor" -I "../src/ASF/avr32/utils" -I "../src/ASF/common/utils" -I "../src/ASF/avr32/drivers/intc" -I "../src/ASF/avr32/drivers/gpio" -I "../src/ASF/avr32/drivers/twim"  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -Wa,-g   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/avr32/utils/startup/%.o: ../src/ASF/avr32/utils/startup/%.x
	@echo Building file: $<
	@echo Invoking: AVR32/GNU Preprocessing Assembler : 4.4.7
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-gcc.exe$(QUOTE) -x assembler-with-cpp -c -mpart=uc64d4 -mrelax -DBOARD=USER_BOARD -I "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\UC3D_DFP\1.0.31\include\ATUC64D4" -I "../common/applications/user_application/user_board/config" -I "../src/config" -I "../src" -I "../src/ASF/common/boards/user_board" -I "../src/ASF/common/boards" -I "../src/ASF/avr32/utils/preprocessor" -I "../src/ASF/avr32/utils" -I "../src/ASF/common/utils" -I "../src/ASF/avr32/drivers/intc" -I "../src/ASF/avr32/drivers/gpio" -I "../src/ASF/avr32/drivers/twim"  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -Wa,-g   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/avr32/utils/startup/%.o: ../src/ASF/avr32/utils/startup/%.X
	@echo Building file: $<
	@echo Invoking: AVR32/GNU Preprocessing Assembler : 4.4.7
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-gcc.exe$(QUOTE) -x assembler-with-cpp -c -mpart=uc64d4 -mrelax -DBOARD=USER_BOARD -I "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\UC3D_DFP\1.0.31\include\ATUC64D4" -I "../common/applications/user_application/user_board/config" -I "../src/config" -I "../src" -I "../src/ASF/common/boards/user_board" -I "../src/ASF/common/boards" -I "../src/ASF/avr32/utils/preprocessor" -I "../src/ASF/avr32/utils" -I "../src/ASF/common/utils" -I "../src/ASF/avr32/drivers/intc" -I "../src/ASF/avr32/drivers/gpio" -I "../src/ASF/avr32/drivers/twim"  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -Wa,-g   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/avr32/utils/startup/%.o: ../src/ASF/avr32/utils/startup/%.sx
	@echo Building file: $<
	@echo Invoking: AVR32/GNU Preprocessing Assembler : 4.4.7
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-gcc.exe$(QUOTE) -x assembler-with-cpp -c -mpart=uc64d4 -mrelax -DBOARD=USER_BOARD -I "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\UC3D_DFP\1.0.31\include\ATUC64D4" -I "../common/applications/user_application/user_board/config" -I "../src/config" -I "../src" -I "../src/ASF/common/boards/user_board" -I "../src/ASF/common/boards" -I "../src/ASF/avr32/utils/preprocessor" -I "../src/ASF/avr32/utils" -I "../src/ASF/common/utils" -I "../src/ASF/avr32/drivers/intc" -I "../src/ASF/avr32/drivers/gpio" -I "../src/ASF/avr32/drivers/twim"  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -Wa,-g   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR32/GNU Linker : 4.4.7
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -nostartfiles -Wl,-Map="Regler.map" -Wl,--start-group -lm  -Wl,--end-group -Wl,--gc-sections --rodata-writable -Wl,--direct-data -mpart=uc64d4 -Wl,--relax -Wl,-e,_trampoline  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature "Regler.elf" "Regler.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Regler.elf" "Regler.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-objdump.exe" -h -S "Regler.elf" > "Regler.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "Regler.elf" "Regler.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr32\avr32-gnu-toolchain\bin\avr32-size.exe" "Regler.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Regler.elf" "Regler.a" "Regler.hex" "Regler.lss" "Regler.eep" "Regler.map" "Regler.srec" "Regler.usersignatures"
	