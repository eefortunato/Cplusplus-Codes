/**
 * @file
 * @author Eric Fortunato
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This exception class handles when more than the maximum observations records are entered.
 */


#ifndef OBSERVATIONSOVERFLOWEXCEPTION_H_
#define OBSERVATIONSOVERFLOWEXCEPTION_H_

#include <exception>
#include <stdexcept>
#include <string>

class ObservationsOverFlowException: public std::runtime_error {
	public:
		/**
		 * Constructor that sets the error message
		 *
		 * @param errorOverFlow String for the message error when it over flows the records
		 */
		ObservationsOverFlowException(const std::string& errorOverFlow):std::runtime_error(""){}
};




#endif /* OBSERVATIONSOVERFLOWEXCEPTION_H_ */
