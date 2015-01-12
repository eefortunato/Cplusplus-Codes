/*
 * projectile.cpp
 *
 * Created on: Jan 31, 2014
 *      Author: Eric Fortunato
 *
 * Decription: this program calculates the distance traveled by a projectile given the velocity and angle
 */

#include <iostream>
#include <math.h>
#include "projectile.h"

using namespace std;

const float gravity = 9.8;

/*
 * Name: degToRads
 *
 * Description: this function converts from degrees to radians
 * We know that a radian is 180/pi degrees
 *
 * Arguments: it receives the degrees as a double
 *
 * Returns: it returns the radians as double
 */

double degToRads(double degrees){
	double radians = (degrees*M_PI)/180;
	return radians;
}

/*
 * Name: degToRads
 *
 * Description: this function converts from degrees to radians
 * One meter is 3.28084 feet, e can convert by doing rule of 3
 *
 * Arguments: it receives the degrees as a double
 *
 * Returns: it returns the radians as double
 */

double metersToFeet(double meters){
	double feets;
	feets=meters*3.28084;
	return feets;
}

/*
 * Name: calculateDistance
 *
 * Description: this function calculates the distance traveled by the projectile given the velocity and angle.
 * The distance is (v^2 sin 2@)/g, range of the projectile, taken from http://en.wikipedia.org/wiki/Range_of_a_projectile
 *
 * Arguments: it receives the velocity and the angle as doubles
 *
 * Returns: it returns the distance as a double
 */

double calculateDistance(double velocity, double degrees){
	double distance=((velocity*velocity)*sin(2*degToRads(degrees)))/gravity;
	return distance;
}

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
