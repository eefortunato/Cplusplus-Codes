/**
 * @file
 * @author Eric Fortunato
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This exception class handles when the program ends abruptly or there are no records.
 */
#ifndef NONEOBSERVATIONSEXCEPTION_H_
#define NONEOBSERVATIONSEXCEPTION_H_

#include <exception>
#include <stdexcept>
#include <string>

/**
 *
 */
class NoneObservationsException: public std::runtime_error{

	public:
		/**
		 * Constructor that sets the message for the exception
		 *
		 * @param errorNoData String with the exception message
		 */
		NoneObservationsException(const std::string& errorNoData):std::runtime_error(""){}
};


#endif /* NONEOBSERVATIONSEXCEPTION_H_ */
