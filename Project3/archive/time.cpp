/**
 * @file
 * @author Travis E. Brown
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * Source file for time class implementation.
 */

#include "time.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <exception>
#include <stdexcept>
#include "noneobservationsexception.h"

using namespace std;


/**
 *	Default constructor
 */
Time::Time()
{
   set( 0 );
}

/**
 * Constructor that sets the time in number of seconds since midnight
 *
 * @param secs Number of seconds since midnight
 */

Time::Time( int secs )
{
   set( secs );
}

/**
 * Constructor that sets the time in the format HH:MM. This is passed in as
 * a C++ string
 *
 * @param HHMM a string that is number of hours and minutes since midnight.
 * In the format HH:MM
 */

Time::Time( std::string HHMM )
{
   set( HHMM );
}

/**
 * Get the stored time.
 *
 * @return Number of seconds since midnight
 */

int Time::getTimeInSecs() const
{
   return timeInSecs;
}

/**
 * Get the stored time
 *
 * @return a string in the format "HH:MM" which is the hours and minutes
 * since midnight.
 */
string Time::getTimeInHHMM() const
{

   ostringstream osstr ;
   osstr << setw(2) << setfill('0') << timeInSecs / 3600 << ":" << setw(2) << ( timeInSecs % 3600 ) / 60;

   return osstr.str();

}

/**
 * Set the stored time
 *
 * @param secs number of seconds since midnight
 */
void Time::set( int secs )
{
   timeInSecs = secs;
}


/**
 * Set the stored time
 *
 * @param HHMM a string in the format "HH:MM" which is the hours and
 * minutes since midnight
 */
void Time::set( string HHMM )
{
   int hours, minutes, sec = 0;
   int colon = -1;  // positions of ':' in s
   if(HHMM==""){
  	   throw NoneObservationsException("Program terminated abruptly");
     }
   for (int i=0; i<int(HHMM.size()); ++i)
   {
      if (HHMM[i] == ':')
      {
         colon = i;
      }
   }

   istringstream(HHMM.substr( 0, colon )) >> hours;
   sec = hours * 3600;

   if (colon >= 0)
   {
      istringstream(HHMM.substr(colon+1)) >> minutes;
      sec += minutes * 60;
   }
   if ( sec > 86400 )
   {
      throw overflow_error("Time is out of range");
   }
   if ( sec < 0 )
   {
      throw underflow_error("Time is out of range");
   }



   timeInSecs = sec;

}

/**
 * Operator << for Time class
 *
 * @param os ostream class for chaining
 * @param t Time class
 * @return ostream class for chaining
 */
ostream& operator<<(ostream& os, const Time& t )
{
   os << t.getTimeInHHMM();
   return os;
}
/**
 * Operator >> for Time class
 *
 * @param os istream class for chaining
 * @param t Time class
 * @return istream class for chaining
 */
istream& operator>>(istream& is, Time& t)
{
	if(is.eof()){
		throw NoneObservationsException("Program terminated abruptly");
	}
	string s;
	is >> s;
	t.set( s );
    return is;
}
