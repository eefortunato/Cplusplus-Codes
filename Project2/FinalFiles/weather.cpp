/*
 * weather.cpp
 *
 *  Created on: Feb 18, 2014
 *  
 *
 *  Description: this is the main program in which we test our Observation class and methods
 */

#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "observation.h"

using namespace std;

/*
 * Name: main
 *
 * Description: this is the main function in which me test our functions to store time and temperature of weather and print average, high and low
 * values
 *
 * Arguments: it receives nothing from the command line
 *
 * Returns: it returns 0 if everything worked correctly
 */

int main(){

	Observation weatherObservations; //instance of class
	string hoursToParse; //hours
	string minutesToParse; //minutes
	string timeToParse; //time without parsing
	string time;
	int temperature, hours, minutes, colonPosition=0;

	while(!cin.eof()){

		cout <<  "Enter time (hh:mm): " ;
		cin >> timeToParse;
		if(cin.eof()){
			cout << "" << endl;
			break;
				}
		colonPosition=timeToParse.find(":");
		if(colonPosition > 0){
			hoursToParse=timeToParse.substr(0, colonPosition);
			minutesToParse=timeToParse.substr(colonPosition+1);
			time=timeToParse;
		}
		else{
			hoursToParse=timeToParse;
			minutesToParse="0";
			time=hoursToParse;
		}
		cout <<	 "Enter temperature: " ;
		cin >> temperature;
		if(cin.eof()){
			cout << "" << endl;
			break;
		}
		if(weatherObservations.wrongTimeFormat(hoursToParse, minutesToParse)){
			cerr << "Time is out of range\n";
			continue;
		}
		else if(weatherObservations.record(time, temperature)){
			continue;
		}
		else {
			cerr << "Maximum number of observations recorded";
			cout << "\n\nAverage Temperature: " << weatherObservations.getAverageTemp();
			cout << "\nHigh temperature observed at " << weatherObservations.getTimeOfHighTemp() << " and was " << weatherObservations.getHighTemp();
			cout << "\nLow temperature observed at " << weatherObservations.getTimeOfLowTemp() << " and was " << weatherObservations.getLowTemp() << endl;
			break;
		}
	}
	if(cin.eof()){
				cout << "\nAverage Temperature: " << weatherObservations.getAverageTemp();
				cout << "\nHigh temperature observed at " << weatherObservations.getTimeOfHighTemp() << " and was " << weatherObservations.getHighTemp();
				cout << "\nLow temperature observed at " << weatherObservations.getTimeOfLowTemp() << " and was " << weatherObservations.getLowTemp();
				cout << "" << endl;
	}
	return 0;
}


