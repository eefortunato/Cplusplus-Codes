################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../projectile.cpp \
../projectilehelper.cpp \
../tree.cpp \
../treehelper.cpp 

OBJS += \
./projectile.o \
./projectilehelper.o \
./tree.o \
./treehelper.o 

CPP_DEPS += \
./projectile.d \
./projectilehelper.d \
./tree.d \
./treehelper.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


