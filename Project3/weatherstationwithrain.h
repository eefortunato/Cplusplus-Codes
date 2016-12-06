/**
 * @file
 * @author Eric Fortunato
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is the weatherstationwithrain derived class declaration to handle the rain inches.
 */

#ifndef WEATHERSTATIONWITHRAIN_H_
#define WEATHERSTATIONWITHRAIN_H_

#include "weatherstation.h"

class WeatherStationWithRain: public virtual WeatherStation{

public:
	/**
	 * Constructor that sets Station name, latitude andd longitude andd initializes rain counter
	 *
	 * @param name Station name
	 * @param latitude Station latitude
	 * @param longitude Station longitude
	 */
	WeatherStationWithRain(const std::string &name="McMurdo Station",  const double &latitude=-77.85, const double &longitude=166.667):WeatherStation(name, latitude, longitude), rainCounter(0){}
	/**
	 * Virtual destructor
	 */
	virtual ~WeatherStationWithRain() {}
	/**
	 * This method records time temperature and rain drops
	 *
	 * @param timeOfObservation the time recorded
	 * @param temperature the temperature recorded
	 * @param rainDrop the rain in 1/100 of inches
	 */
	void record(Time timeOfObservation, float temperature , float rainDrop);
	/**
	 * This method calculates and gets the total rain inches fallen
	 *
	 * @return The total amount of rain inches
	 */
	float getTotalRain();
	/**
	 * This method sets the rain drops by 1/100 of an inch
	 *
	 * @param rainDrop the rain in 1/100 of inches
	 */
	void setRain(float rainDrop);

protected:
	float rainInches[maxObservations];
	int rainCounter;


};



#endif /* WEATHERSTATIONWITHRAIN_H_ */
