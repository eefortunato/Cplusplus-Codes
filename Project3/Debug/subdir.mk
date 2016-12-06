################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../noneobservationsexception.cpp \
../observationsoverflowexception.cpp \
../time.cpp \
../weather.cpp \
../weatherstation.cpp \
../weatherstationwithrain.cpp \
../weatherstationwithwind.cpp \
../weatherstationwithwindandrain.cpp 

OBJS += \
./noneobservationsexception.o \
./observationsoverflowexception.o \
./time.o \
./weather.o \
./weatherstation.o \
./weatherstationwithrain.o \
./weatherstationwithwind.o \
./weatherstationwithwindandrain.o 

CPP_DEPS += \
./noneobservationsexception.d \
./observationsoverflowexception.d \
./time.d \
./weather.d \
./weatherstation.d \
./weatherstationwithrain.d \
./weatherstationwithwind.d \
./weatherstationwithwindandrain.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


