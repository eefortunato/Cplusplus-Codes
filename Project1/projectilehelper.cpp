/*
 * projectilehelper.cpp
 *
 * Created on: Jan 31, 2014
 *      Author: Eric Fortunato
 *
 * Decription: this is the file in which the functions are defined/implemented
 */

#include <math.h>
#include "projectile.h"

const float gravity = 9.8;

/*
 * Name: degToRads
 *
 * Description: this function converts from degrees to radians
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
 *
 * Arguments: it receives the velocity and the angle as doubles
 *
 * Returns: it returns the distance as a double
 */

double calculateDistance(double velocity, double degrees){
	double distance=((velocity*velocity)*sin(2*degToRads(degrees)))/gravity;
	return distance;
}


