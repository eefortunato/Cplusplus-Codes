/**
 * @file
 * @author Eric Fortunato
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This weatherstationwithwind derived class implementation.
 */
#include <math.h>
#include "weatherstationwithwind.h"
#include "observationsoverflowexception.h"
#include "noneobservationsexception.h"

using namespace std;
/**
 * This methods records the time, temperature, wind speed andd wind direction
 *
 * @param timeOfObservation the time recorded
 * @param temperature the temperature recorded
 * @param windSpeed the wind speeed recorded
 * @param windDirection the wind direction recorded
 */
void WeatherStationWithWind::record(Time timeOfObservation, float temperature, float windSpeed, float windDirection){

			WeatherStation::record(timeOfObservation, temperature);
			setWindSpeed(windSpeed);
			setWindDirection(windDirection);
}

/**
 * This method gets the average wind speed
 *
 * @return The average wind speed
 */

float WeatherStationWithWind::getAverageWindSpeed(){
	float windSpeedAvg=0;
	for(int i=0; i < getRecords(); i++){
		windSpeedAvg+=windSpeed[i];
	}

	return windSpeedAvg/getRecords();

}

/**
 * This method gets the average wind direction
 *
 * @return The average wind direction
 */

float WeatherStationWithWind::getAverageWindDirection(){

	float sinSumatory=0, cosSumatory=0;
	for(int i=0; i < getRecords(); i++){
		sinSumatory+=sin(degToRads(windDirection[i]));
		cosSumatory+=cos(degToRads(windDirection[i]));
	}

	return radsToDeg(atan2( sinSumatory, cosSumatory));

}

/**
 * This method convert from degrees to radians
 *
 * @param degrees The degrees entered
 * @return radians obtained
 */

float WeatherStationWithWind::degToRads(float degrees){
	float radians = (degrees*M_PI)/180;
	return radians;
}

/**
 * This method sets the wind speed
 *
 * @param windSpeed the wind speed to record
 */

float WeatherStationWithWind::radsToDeg(float radians){
	float degrees = (radians*180)/M_PI;
	return degrees;
}

/**
 * Thiss method sets the wind direction
 *
 * @param windDirection the wind ddirection to record
 */

void WeatherStationWithWind::setWindDirection(float windDirection){
	this->windDirection[directionCounter]=windDirection;
	directionCounter++;
}
/**
 * This method sets the wind speed
 *
 * @param windSpeed the wind speed to record
 */
void WeatherStationWithWind::setWindSpeed(float windSpeed){
	this->windSpeed[speedCounter]=windSpeed;
	speedCounter++;
}
