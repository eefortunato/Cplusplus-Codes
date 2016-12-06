/**
 * @file
 * @author Eric Fortunato
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This weatherstationwithwind derived class declaration handles the wind speed and wind direction.
 */

#ifndef WEATHERSTATIONWITHWIND_H_
#define WEATHERSTATIONWITHWIND_H_

#include "weatherstation.h"

class WeatherStationWithWind: public virtual WeatherStation{

public:
	/**
	 * Constructor that sets the Station name, latitude and longitude and initializes direction and speed counter
	 *
	 * @param name Station name
	 * @param latitude SStation latitude
	 * @param longitudde Station longitude
	 */
	WeatherStationWithWind(const std::string &name="McMurdo Station",  const double &latitude=-77.85, const double &longitude=166.667):WeatherStation(name, latitude, longitude), directionCounter(0), speedCounter(0){}
	/**
	 * Virtual destructor
	 */
	virtual ~WeatherStationWithWind() {}
	/**
	 * This methods records the time, temperature, wind speed andd wind direction
	 *
	 * @param timeOfObservation the time recorded
	 * @param temperature the temperature recorded
	 * @param windSpeed the wind speeed recorded
	 * @param windDirection the wind direction recorded
	 */
	void record(Time timeOfObservation, float temperature, float windSpeed, float windDirection);
	/**
	 * This method gets the average wind speed
	 *
	 * @return The average wind speed
	 */
	float getAverageWindSpeed();
	/**
	 * This method gets the average wind direction
	 *
	 * @return The average wind direction
	 */
	float getAverageWindDirection();
	/**
	 * This method convert from degrees to radians
	 *
	 * @param degrees The degrees entered
	 * @return radians obtained
	 */
	float degToRads(float degrees); //this functions converts from degrees to radians
	/**
	 * This method converts from radians to degrees
	 *
	 * @param the radians received
	 * @return the degrees obtained
	 */
	float radsToDeg(float radians);
	/**
	 * This method sets the wind speed
	 *
	 * @param windSpeed the wind speed to record
	 */
	void setWindSpeed(float windSpeed);
	/**
	 * Thiss method sets the wind direction
	 *
	 * @param windDirection the wind ddirection to record
	 */
	void setWindDirection(float windDirection);

protected:
	float windSpeed[maxObservations]; //array of float to store wind speed
	float windDirection[maxObservations]; //array of float to store wind direction
	int speedCounter; //speed counter
	int directionCounter; //direction counter


};



#endif /* WEATHERSTATIONWITHWIND_H_ */
