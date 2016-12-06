/**
 * @file
 * @author Eric Fortunato
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * Source fiel for weatherstation class implementation.
 */

#include <cstdlib>
#include <stdio.h>
#include <sstream>
#include <exception>
#include "weatherstation.h"
#include "observationsoverflowexception.h"
#include "noneobservationsexception.h"

using namespace std;

int indexHighTemp=0;
int indexLowTemp=0; //index for high and low temperature;

 	 /**
 	  * This method records time and temperature
 	  *
 	  * @param timeOfObservation the time recorded
 	  * @param temperature the temperature recorded
 	  */

      void WeatherStation::record( Time timeOfObservation, float temperature ){
    	  if(cin.eof()){
    		  throw NoneObservationsException("Program terminated abruptly");
    	  }
    	  else if(getRecords() < maxObservations-1){
        		  weatherRecords[recordCounter].time=timeOfObservation;
        		  weatherRecords[recordCounter].temp=temperature;
        		  recordCounter++;
    	  	  }
    	  else{
    	  		  throw ObservationsOverFlowException("Maximum number of observations recorded");
    	  	  }



      }
      /**
       * This method checks for end of file ctrl-d
       *
       * @param is input stream for the user data
       */
      void WeatherStation::validateInput(istream & is){
      	if(is.eof()){
      		throw NoneObservationsException("Program terminated abruptly");
      	}
      }

      /**
       * This method gets the time of higher temperature
       *
       * @return time object for the highest temperature
       */

      Time WeatherStation::getTimeOfHighTemp() const{

    	  float value = getHighTemp();
    	  return weatherRecords[indexHighTemp].time;
      }

      /**
       * This method gets the time of lowest temperature
       *
       * @return time object for the lowest temperature
       */

      Time WeatherStation::getTimeOfLowTemp() const{

    	  float value = getLowTemp();
    	  return weatherRecords[indexLowTemp].time;
      }

      /**
       * This method gets the highest temperature and sets the index for the time
       *
       * @return Highest temperature recorded
       */

      float WeatherStation::getHighTemp() const{
    	  float highTemp=weatherRecords[0].temp;
    	  for(int i = 1; i < recordCounter; i++){
                if(weatherRecords[i].temp > highTemp){
                    highTemp=weatherRecords[i].temp;
                    indexHighTemp=i;
    	      	}
    	  }
          return highTemp;
      }

      /**
       * This method gets the lowest temperature and sets the index for the time
       *
       * @return Lowest temperature recorded
       */

      float WeatherStation::getLowTemp() const{
    	  float lowTemp=weatherRecords[0].temp;
    	  for(int i = 1; i < recordCounter; i++){
    		  if(weatherRecords[i].temp < lowTemp){
    			  lowTemp=weatherRecords[i].temp;
    			  indexLowTemp=i;
    		  }
    	  }
    	  return lowTemp;
      }

      /**
       * This method gets the average temperature
       *
       * @return Average temperature
       */

      float WeatherStation::getAverageTemp(){

    	  for(int i=0; i < recordCounter; i++){
    		  average+=weatherRecords[i].temp;
    	  }
    	  return average/=recordCounter;
      }

      /**
       * This method gets the number of records registered
       *
       * @return Number of current records
       */

      int WeatherStation::getRecords(){
    	  return recordCounter;
      }

      /**
       * This method get the station name
       *
       * @return String with the station name
       */
      string WeatherStation::getStationName() const{
    	  return this->name;
      }
      /**
       * This method gets the station latitude
       *
       * @return The latitude of the station
       */
      double WeatherStation::getStationLatitude() const{
    	  return this->latitude;
      }
      /**
       * This method gets the station longitude
       *
       * @return The longitude of the station
       */
      double WeatherStation::getStationLongitude() const{
    	  return this->longitude;
      }
      /**
       * This method gets the maximum observations
       *
       * @return The number of maximum observations
       */
      int WeatherStation::getMaxObservations() const{
    	  return maxObservations;
      }



