/**
 * @file
 * @author Eric Fortunato
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * Source file for weatherstationwithwindandrain implementation.
 */
#include "weatherstationwithwindandrain.h"
#include "noneobservationsexception.h"

using namespace std;
/**
	 * This method records time, temperature, wind speed, wind direction and rain inches
	 *
	 * @param timeOfObservation The time recorded
	 * @param temperature The temperature recorded
	 * @param windSpeed The wind speed recorded
	 * @param windDirection The wind direction recorded
	 * @param rainDrop the rain in 1/100 of inches
	 */
void WeatherStationWithWindAndRain::record(Time timeOfObservation, float temperature, float windSpeed, float windDirection, float rainDrop){
	WeatherStation::record(timeOfObservation, temperature);
	setWindSpeed(windSpeed);
	setWindDirection(windDirection);
	setRain(rainDrop);
}





