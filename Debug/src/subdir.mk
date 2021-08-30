################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MorseBuffer.cpp \
../src/MorseCode.cpp \
../src/MorseLetter.cpp \
../src/main.cpp 

OBJS += \
./src/MorseBuffer.o \
./src/MorseCode.o \
./src/MorseLetter.o \
./src/main.o 

CPP_DEPS += \
./src/MorseBuffer.d \
./src/MorseCode.d \
./src/MorseLetter.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


