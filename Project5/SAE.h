/**
 * @file
 * @author Eric Fortunato
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is the SAE class declaration to handle operator overloading. It includes couple of templatize methods
 */

#ifndef SAE_H_
#define SAE_H_

#include <iostream>
#include <exception>
#include <stdexcept>

class SAE {
public:
	SAE(double feet, double inches); //constructor to initialize feet and inches
	SAE(); //default constructor
	SAE operator+(const SAE &magnitudeB); //operator overloading for addition
	SAE operator+=(const SAE &magnitudeB); //operator overloading for +=
	SAE operator-(const SAE &magnitudeB); //operator overloading for subtraction
	SAE operator-=(const SAE &magnitudeB); //operator overloading for -=
	/**
	 * Operator overloading for multiplication
	 * @param magnitudeB it receives scalar magnitude
	 * @return result which is a SAE object
	 */
	template <typename T> SAE operator*(T magnitudeB){
		SAE result(*this);
		return result*=magnitudeB;
	}
	SAE operator*(const SAE &magnitudeB); //operator over loading for multiplication
	SAE operator*=(const SAE &magnitudeB); //operator overloading for *=
	/**
	 * Operator overloading for *=
	 * @param magnitudeB it receives scalar magnitude
	 * @return *this the value as a SAE object.
	 */
	template <typename T>SAE operator*=(T magnitudeB){
		feet*=magnitudeB;
		return *this;
	}

	/**
	 * Operator overloding for division
	 * @param magnitudeB scalar magnitude
	 * @return result a SAE object
	 */
	template <typename T>SAE operator/(T magnitudeB){
		SAE result(*this);
		return result/=magnitudeB;
	}
	SAE operator/(const SAE &magnitudeB); //operator overloading for division
	SAE operator/=(const SAE &magnitudeB); //operator overloading for /=

	/**
	 * Operator overloading for /=
	 * @param
	 */
	template <typename T> SAE operator/=(T magnitudeB){
		if(magnitudeB == 0){
			throw std::overflow_error("Divide by zero");
		}
		feet/=magnitudeB;
		return *this;
	}
	double getFeet() const;  //getter method for feet
	double getDimension() const; //getter method for dimension
	std::string toString() const; //method for printing feet and inches with a format
	friend std::ostream& operator<<(std::ostream& os, const SAE& sae ); //operator overloading for output stream


private:
	double feet, dimension; //varibles for storing feet and dimension
	double convertToFeet(double inches); //method for converting inches to feet
};


#endif /* SAE_H_ */
