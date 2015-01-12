/*
 * projectile.cpp
 *
 * Created on: Jan 31, 2014
 *      Author: Eric Fortunato
 *
 * Decription: this program calculates the distance traveled by a projectile given the velocity and angle
 */

#include <iostream>
#include "projectile.h"

using namespace std;


/*
 * Name: main
 *
 * Description: this is the main function in which me test our functions to calculate distance and make the convertions
 * the user will write the velocity and the angle
 *
 * Arguments: it receives nothing from the command line
 *
 * Returns: it returns 0 if everthing worked correctly
 */

int main(){

	double initialVelocity;
	double elevationAngle;
	cout << "Enter initial velocity (m/s): ";
	cin >> initialVelocity;
	cout << "Enter elevation angle (degrees): ";
	cin >> elevationAngle;
	cout << degToRads(elevationAngle) << endl;
	cout << "The projectile travelled " << calculateDistance(initialVelocity, elevationAngle) << " meters, or " << metersToFeet(calculateDistance(initialVelocity, elevationAngle)) << " feet." << endl;


	return 0;

}
