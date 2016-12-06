/**
 * @file
 * @author Eric Fortunato
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is the weatherstationwithrain derived class implementation.
 */
#include <exception>
#include "weatherstationwithrain.h"
#include "observationsoverflowexception.h"
#include "noneobservationsexception.h"

using namespace std;
/**
 * This method calculates and gets the total rain inches fallen
 *
 * @return The total amount of rain inches
 */
float WeatherStationWithRain::getTotalRain(){
	float rainSum=0;
	for(int i=0; i < getRecords(); i++){
		rainSum+=rainInches[i];
	}

	return rainSum/=100;

}
/**
 * This method sets the rain drops by 1/100 of an inch
 *
 * @param rainDrop the rain in 1/100 of inches
 */
void WeatherStationWithRain::setRain(float rainDrop){
	rainInches[rainCounter]=rainDrop;
	rainCounter++;
}
/**
 * This method records time temperature and rain drops
 *
 * @param timeOfObservation the time recorded
 * @param temperature the temperature recorded
 * @param rainDrop the rain in 1/100 of inches
 */
void WeatherStationWithRain::record(Time timeOfObservation, float temperature, float rainDrop){

			WeatherStation::record(timeOfObservation, temperature);
			setRain(rainDrop);
}
