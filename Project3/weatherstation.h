/**
 * @file
 * @author Eric Fortunato
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is the weatherstation base class declaration to handle time and temperature.
 */

#ifndef WEATHERSTATION_H_
#define WEATHERSTATION_H_

#include <string>
#include "time.h"
#include <iostream>

   class WeatherStation
   {

   public:
	   /**
	    * Constructor that sets station name, latitude and longitude and initializes the counters and average variable
	    *
	    * @param name Station name
	    * @param latitude Station latitude
	    * @param longitude Station longitude
	    */
	  WeatherStation(const std::string &name, const double &latitude, const double &longitude ): name(name), latitude(latitude), longitude(longitude), recordCounter(0), average(0){} //default constructor
      /**
       * Virtual destructor
       */
	  virtual ~WeatherStation() {}
      /**
       * This method records the time and temperature
       *
       * @param timeOfObservation The time entered
       * @param temperature The temperature registered
       */
	  virtual void record( Time timeOfObservation, float temperature ); //method for recording time and temperature
      /**
       * This method checks for end of file
       *
       * @param is The user input data
       */
	  void validateInput(std::istream & is);
	  /**
	   * This method gets the time of highest temperature
	   *
	   * @return Time object of the highest temperature
	   */
      Time getTimeOfHighTemp() const; //getter method for high temperature time
      /**
       * This method gets the time of lowest temperature
       *
       * @return time object for the lowest temperature
       */
      Time getTimeOfLowTemp() const; //getter method for low temperature time
      /**
       * This method gets the highest temperature and sets the index for the time
       *
       * @return Highest temperature recorded
       */
      float getHighTemp() const; //getter method for high temperature
      /**
       * This method gets the lowest temperature and sets the index for the time
       *
       * @return Lowest temperature recorded
       */
      float getLowTemp() const; //getter method for low temperature
      /**
       * This method gets the average temperature
       *
       * @return Average temperature
       */
      float getAverageTemp(); //getter method for average temperature
      /**
       * This method gets the number of records registered
       *
       * @return Number of current records
       */
      int getRecords(); //getter method for record counter
      /**
       * This method get the station name
       *
       * @return String with the station name
       */
      std::string getStationName() const;
      /**
       * This method gets the station latitude
       *
       * @return The latitude of the station
       */
      double getStationLatitude() const;
      /**
       * This method gets the station longitude
       *
       * @return The longitude of the station
       */
      double getStationLongitude() const;
      /**
       * This method gets the maximum observations
       *
       * @return The number of maximum observations
       */
      int getMaxObservations() const;

   protected:
      /** Maximum number of observations that can be recored */
      static const int maxObservations = 24;
      //Struct for time and temperature storage
      struct Observation
               {
                  Time time; //time recorded
                  float temp; //temperature recorded
               };
      Observation weatherRecords[maxObservations]; //array of struct for recording weather time and temperature
      int recordCounter; //counter for records
      int average; //temperature average


   private:
         std::string name; //Station name
         double latitude; //Station latitude
         double longitude; //Station longitude
   };




#endif /* WEATHERSTATION_H_ */
