################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../weather.o 

CPP_SRCS += \
../observation.cpp \
../weather.cpp 

OBJS += \
./observation.o \
./weather.o 

CPP_DEPS += \
./observation.d \
./weather.d 


# Each subdirectory must supply rules for building sources it contributes
observation.o: ../observation.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"observation.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

weather.o: ../weather.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"C:\cygwin64\lib\gcc\i686-pc-cygwin\4.7.3\include\c++" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"weather.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


