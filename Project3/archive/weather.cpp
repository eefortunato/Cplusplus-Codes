/**
 * @file
 * @author Eric Fortunato
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is the main program where I test the weather classes and methods.
 */

#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "weatherstationwithwindandrain.h"
#include "noneobservationsexception.h"
#include "observationsoverflowexception.h"
using namespace std;

/**
 * Main method to receive by console time, temperature, and weather parameters
 *
 * @return 0 if everything worked perfectly
 */

int main(){

	WeatherStationWithWindAndRain weatherObservations("McMurdo Station", -77.85, 166.667); //instance of class
	string hoursToParse; //hours
	string minutesToParse; //minutes
	string time;

	float temperature, windSpeed, windDirection, rainAmount;

	while( !cin.eof() ){

		cout <<  "Enter time (hh:mm): " ;
		try{
			cin >> time;
			weatherObservations.validateInput(cin);
			Time timeToParse(time);
		}catch(overflow_error & e){
				cerr << "General exception occurred:" << e.what() << """\n";
				continue;
		}catch(underflow_error & e){
			cerr << "General exception occurred:" << e.what() << """\n";
			continue;
		}catch(NoneObservationsException & noe){
			cout << "" << endl;
			break;
		}
		try{
			cout <<	 "Enter temperature (deg C): ";
			cin >> temperature;
			weatherObservations.validateInput(cin);
			cout <<	 "Enter wind speed (mph): ";
			cin >> windSpeed;
			weatherObservations.validateInput(cin);
			cout <<	 "Enter wind direction (deg): ";
			cin >> windDirection;
			weatherObservations.validateInput(cin);
			cout <<	 "Enter rain (1/100th inch): ";
			cin >> rainAmount;
			weatherObservations.validateInput(cin);
			weatherObservations.record(time, temperature, windSpeed, windDirection, rainAmount);
			cout << "\n";
			continue;
		}catch(ObservationsOverFlowException & ooe){
			cerr << "\nMaximum number of observations recorded\n\n";
			cout << "Weather Data for " << weatherObservations.getStationName() << " ("<<weatherObservations.getStationLatitude()<<", "<<weatherObservations.getStationLongitude()<< ")" << endl;
			cout << "-------------------------------------------------------------";
			cout << "\nAverage Temperature: " << weatherObservations.getAverageTemp() << " degree(s) C";
			cout << "\nHigh Temperature was " << weatherObservations.getHighTemp() << " degree(s) C" << " at " << weatherObservations.getTimeOfHighTemp().getTimeInHHMM();
			cout << "\nLow Temperature was " << weatherObservations.getLowTemp()<< " degree(s) C"  << " at " << weatherObservations.getTimeOfLowTemp().getTimeInHHMM();
			cout << "\nAverage Wind Speed: " << weatherObservations.getAverageWindSpeed() <<"mph";
			cout << "\nAverage Wind Direction: " << weatherObservations.getAverageWindDirection() << " degree(s)";
			cout << "\nTotal Rain: " << weatherObservations.getTotalRain() << "\"" << endl;
			break;
		}catch(NoneObservationsException & noe){
			cout << "" << endl;
			break;
		}
	}
	if(weatherObservations.getRecords() > 0){
		cout << "Weather Data for " << weatherObservations.getStationName() << " ("<<weatherObservations.getStationLatitude()<<", "<<weatherObservations.getStationLongitude()<< ")" << endl;
		cout << "-------------------------------------------------------------";
		cout << "\nAverage Temperature: " << weatherObservations.getAverageTemp() << " degree(s) C";
		cout << "\nHigh Temperature was " << weatherObservations.getHighTemp() << " degree(s) C" << " at " << weatherObservations.getTimeOfHighTemp().getTimeInHHMM();
		cout << "\nLow Temperature was " << weatherObservations.getLowTemp()<< " degree(s) C"  << " at " << weatherObservations.getTimeOfLowTemp().getTimeInHHMM();
		cout << "\nAverage Wind Speed: " << weatherObservations.getAverageWindSpeed() <<"mph";
		cout << "\nAverage Wind Direction: " << weatherObservations.getAverageWindDirection() << " degree(s)";
		cout << "\nTotal Rain: " << weatherObservations.getTotalRain() << "\"" << endl;
		cout << "" << endl;
	}
	else {
		cout << "\nWeather Data for " << weatherObservations.getStationName() << " ("<<weatherObservations.getStationLatitude()<<", "<<weatherObservations.getStationLongitude()<< ")" << endl;
		cout << "-------------------------------------------------------------";
		cout << "\nNo data available";
		cout << ""<< endl;
	}
	return 0;
}


