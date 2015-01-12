################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../FinalFiles/projectile.o \
../FinalFiles/tree.o 

CPP_SRCS += \
../FinalFiles/projectile.cpp \
../FinalFiles/tree.cpp 

OBJS += \
./FinalFiles/projectile.o \
./FinalFiles/tree.o 

CPP_DEPS += \
./FinalFiles/projectile.d \
./FinalFiles/tree.d 


# Each subdirectory must supply rules for building sources it contributes
FinalFiles/%.o: ../FinalFiles/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


