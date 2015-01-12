/*
 * observation.cpp
 *
 *  Created on: Feb 18, 2014
 *  
 *
 *  Description: This is the source file in which implementation for the observation class methods is given
 */

#include <cstdlib>
#include <stdio.h>
#include <sstream>
#include "observation.h"

using namespace std;

int indexHighTemp=0, indexLowTemp=0; //index for high and low temperature;

	/*
	 * Default constructor
	 *
	 */
 	 Observation::Observation(){
 		 recordCounter=0;
 		 average=0;
 }

 	 /*
 	  * Name: record
 	  *
 	  * Description: This method checks if the number of records are below the maximum to add them in the struct
 	  *
 	  * Returns: it returns true if the records are below 24 and the data was added
 	  *
 	  */

      bool Observation::record( string timeOfObservation, int temperature ){
    	  if(recordCounter < 24){
    		  weatherRecords[recordCounter].time=timeOfObservation;
    		  weatherRecords[recordCounter].temp=temperature;
    		  recordCounter++;
    		  return true;
    	  }
    	  return false;

      }

      /*
       * Name: getTimeOfHighTemp
       *
       * Description: this method gets the registered time for the highest temperature
       *
       * Return: it returns the time as a string
       */

      string Observation::getTimeOfHighTemp(){
    	  if(recordCounter<=0){
    		  return "";
    	  }
    	  return weatherRecords[indexHighTemp].time;
      }

      /*
       * Name: getTimeOfLowTemp
       *
       * Description: this method gets the registered time for the lowest temperature
       *
       * Return: it returns the time as a string
       */

      string Observation::getTimeOfLowTemp(){
    	  if(recordCounter<=0){
    	      return "";
    	      	  }
    	  return weatherRecords[indexLowTemp].time;
      }

      /*
       * Name: getHighTemp
       *
       * Description: this method gets the registered highest temperature
       *
       * Return: it returns the temperature as an integer
       */

      int Observation::getHighTemp(){
    	  if(recordCounter <=0){
    	      return -9999;
    	      	  }
    	  int highTemp=weatherRecords[0].temp;
    	  for(int i = 1; i < recordCounter; i++){
    	      		  if(weatherRecords[i].temp > highTemp){
    	      			  highTemp=weatherRecords[i].temp;
    	      			  indexHighTemp=i;
    	      		  }
    	      	  }
    	      	  return highTemp;
      }

      /*
       * Name: getLowTemp
       *
       * Description: this method gets the registered lowest temperature
       *
       * Return: it returns the temperature as an integer
       */

      int Observation::getLowTemp(){
    	  if(recordCounter <=0){
    		  return 9999;
    	  }
    	  int lowTemp=weatherRecords[0].temp;
    	  for(int i = 1; i < recordCounter; i++){
    		  if(weatherRecords[i].temp < lowTemp){
    			  lowTemp=weatherRecords[i].temp;
    			  indexLowTemp=i;
    		  }
    	  }
    	  return lowTemp;
      }

      /*
       * Name: getAverageTemp
       *
       * Description: this method gets the calculated average temperature
       *
       * Return: it returns the average temperature as an integer
       */

      int Observation::getAverageTemp(){
    	  if(recordCounter<=0){
    		  return 0;
    	  }
    	  for(int i=0; i < recordCounter; i++){
    		  average+=weatherRecords[i].temp;
    	  }
    	  return average/=recordCounter;
      }

      /*
       * Name: getRecords
       *
       * Description: this method gets the amount of records registered
       *
       * Return: it returns the temperature as an integer
       */

      int Observation::getRecords(){
    	  return recordCounter;
      }

      /*
       * Name: wrongTimeFormat
       *
       * Description: this method checks if the time has the correct format
       *
       * Return: it returns true if the time has wrong format
       */

      bool Observation::wrongTimeFormat(string hours, string minutes){
    	  stringstream convert;
    	  int hoursTest = 0, minutesTest=0;
    	  convert << hours;
    	  if(!(convert >> hoursTest)){
    		  return true;
    	  }
    	  convert >> hoursTest;
    	  convert.clear();
    	  convert << minutes;
    	  if( !(convert >> minutesTest) ){
    	          return true;
       	      }
    	  convert >> minutesTest;
    	  if(hours == "" || minutes == "")
    	      	{
    	    	  	return true;
    	      	}
    	      if(hoursTest == 24){
    	    	  if(minutesTest > 0 || minutesTest < 0){
    	    		  return true;
    	    	  }
    	      }
    	  return hoursTest > 24 || hoursTest < 0 || minutesTest > 59 || minutesTest < 0;
      }

