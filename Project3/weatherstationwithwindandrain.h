/**
 * @file
 * @author Eric Fortunato
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This weatherstationwithwindandrain derives from weatherstationwithwind and weatherstationwithrain and handles both rain inches and wind speed and direction.
 */
#ifndef WEATHERSTATIONWITHWINDANDRAIN_H_
#define WEATHERSTATIONWITHWINDANDRAIN_H_


#include "weatherstationwithwind.h"
#include "weatherstationwithrain.h"

class WeatherStationWithWindAndRain: public WeatherStationWithWind, public WeatherStationWithRain{

public:
	/**
	 * Constructor that sets Station name, latitude, longitude
	 *
	 * @param name Station name
	 * @param latitude Station latitude
	 * @param longitude Station longitude
	 */
	WeatherStationWithWindAndRain(const std::string &name="McMurdo Station",  const double &latitude=-77.85, const double &longitude=166.667):WeatherStation(name, latitude, longitude), WeatherStationWithWind(name, latitude, longitude), WeatherStationWithRain(name, latitude, longitude){}
	/**
	 * Virtual desctructor
	 */
	virtual ~WeatherStationWithWindAndRain() {}
	/**
	 * This method records time, temperature, wind speed, wind direction and rain inches
	 *
	 * @param timeOfObservation The time recorded
	 * @param temperature The temperature recorded
	 * @param windSpeed The wind speed recorded
	 * @param windDirection The wind direction recorded
	 * @param rainDrop the rain in 1/100 of inches
	 */
	void record(Time timeOfObservation, float temperature, float windSpeed, float windDirection, float rainDrop);
};


#endif /* WEATHERSTATIONWITHWINDANDRAIN_H_ */
