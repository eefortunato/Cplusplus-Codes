/*
 * observation.h
 *
 *  Created on: Feb 18, 2014
 *  Author: Eric Fortunato
 *
 *  Description: This is the header file where we declare the functions to record the weather observations.
 */

#ifndef OBSERVATION_H_
#define OBSERVATION_H_

#include <string>
#include <iostream>

   class Observation
   {
   private:
      struct ObservationStruct
      {
         std::string time; //time recorded
         int temp; //temperature recorded
      };
      int recordCounter; //counter for records
      int average; //temperature average
      ObservationStruct weatherRecords[24]; //array of struct for recording weather time and temperature


   public:
      Observation(); //default constructor
      bool record( std::string timeOfObservation, int temperature ); //method for recording time and temperature
      std::string getTimeOfHighTemp(); //getter method for high temperature time
      std::string getTimeOfLowTemp(); //getter method for low temperature time
      int getHighTemp(); //getter method for high temperature
      int getLowTemp(); //getter method for low temperature
      int getAverageTemp(); //getter method for average temperature
      int getRecords(); //getter method for record counter
      bool wrongTimeFormat(std::string hours, std::string minutes); //method for checking time format
   };




#endif /* OBSERVATION_H_ */
