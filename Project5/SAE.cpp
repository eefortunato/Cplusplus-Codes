/**
 * @file
 * @author Eric Fortunato
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * Source file for SAE class implementation.
 */

#include <sstream>
#include <exception>
#include <stdexcept>
#include <cmath>
#include "SAE.h"

using namespace std;

/**
 * Default constructor that initializes feet and dimension
 */
SAE::SAE():feet(0), dimension(1) {
	// TODO Auto-generated constructor stub

}

/**
 * Constructor that initializes feet and inches and dimension and converts everything to feet
 * @param feet double value for the feet
 * @param inches double value for the inches
 */

SAE::SAE(double feet, double inches): feet(0), dimension(1){
    this->feet += feet + convertToFeet(inches);
}

/**
 * Operator overloading for addition
 * @param magnitudeB a SAE magnitude
 * @return result the result of the operation as a SAE object
 */

SAE SAE::operator+(const SAE &magnitudeB){
	SAE result(*this);
	return result+=magnitudeB;
}
/**
 * Operator overloading for +=
 * @param magnitudeB a SAE magnitude
 * @return *this the result of the operation as a SAE object
 */
SAE SAE::operator+=(const SAE &magnitudeB){
	feet+=magnitudeB.getFeet();
	return *this;
}
/**
 * Operator overloading for subtraction
 * @param magnitudeB a SAE magnitude
 * @return result the result of the operation as a SAE object
 */
SAE SAE::operator-(const SAE &magnitudeB){
	SAE result(*this);
	return result-=magnitudeB;
}
/**
 * Operator overloading for -=
 * @param magnitudeB a SAE magnitude
 * @return *this the result of the operation as a SAE object
 */
SAE SAE::operator-=(const SAE &magnitudeB){
	feet-=magnitudeB.getFeet();
	return *this;
}
/**
 * Operator overloading for multiplication
 * @param magnitudeB a SAE magnitude
 * @return result the result of the operation as a SAE object
 */
SAE SAE::operator*(const SAE &magnitudeB){
	SAE result(*this);
	return result*=magnitudeB;
}
/**
 * Operator overloading for *=
 * @param magnitudeB a SAE magnitude
 * @return *this the result of the operation as a SAE object
 */
SAE SAE::operator*=(const SAE &magnitudeB){
    dimension+=magnitudeB.getDimension();
    feet *= magnitudeB.getFeet();
	return *this;
}
/**
 * Operator overloading for division
 * @param magnitudeB a SAE magnitude
 * @return result the result of the operation as a SAE object
 */
SAE SAE::operator/(const SAE &magnitudeB){
	SAE result(*this);
	return result/=magnitudeB;
}
/**
 * Operator overloading for /=
 * @param magnitudeB a SAE magnitude
 * @return *this the result of the operation as a SAE object
 */
SAE SAE::operator/=(const SAE &magnitudeB){
	if(dimension <= magnitudeB.getDimension()){
		throw std::underflow_error("Not enough dimensions!");
	}
	dimension-=magnitudeB.getDimension();
	feet /= magnitudeB.getFeet();
	return *this;
}
/**
 * Method for converting inches to feet
 * @param inches double value for the iches
 * @return inches/12 the value in feet
 */
double SAE::convertToFeet(double inches){
	return inches/12;
}
/**
 * Getter method for feet
 * @return feet the value of feet
 */
double SAE::getFeet()const{
	return feet;
}
/**
 * Getter method for dimension
 * @return dimension the value for dimension
 */
double SAE::getDimension()const{
	return dimension;
}



/**
 * Operator overloading for <<
 * @param os output source
 * @param magnitudeB a SAE magnitude
 * @return os the stream to print as an output stream
 */
ostream& operator<<(std::ostream& os, const SAE& sae ){
	stringstream iss;
	if(sae.dimension==1){
		int justFeet = (int)sae.feet; // Stores the integer part of the feet value
		double feetDecimal= sae.feet-justFeet; // Stores the decimal part of the feet value
		double justInches = feetDecimal*12; // Converts the decimal part of the feet value to inches
		iss << justFeet << " feet, " << justInches << " inches";
		os << iss.str();
		return os;
	}
	if(sae.feet > -1 && sae.feet < 1){
			iss << sae.feet*12 << " inches^";
	}
	else{
		iss << sae.feet << " feet^";
		iss << sae.dimension;
	}
	os << iss.str();
	return os;
}



