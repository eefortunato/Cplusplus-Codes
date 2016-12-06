/**
 * 4003-703-03 Homework 4 main.cpp.  Students should add a showStats()
 * function to this file.
 */
/**
 * @file
 * @author Eric Fortunato
 * @version 2.0
 *
 * @section DESCRIPTION
 *
 * This is the main program where I test the statistics class template.
 */
#include "statistics.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <set>

using namespace std;

/* showStats() function goes here */
template <typename T>
void showStats(Statistics<T> stats){
	cout << "mean: " << stats.mean() << endl;
	cout << "median: " << stats.median() << endl;
	set<T> mode = stats.mode();
	cout << "mode: ";
	for(typename set<T>::iterator it= mode.begin(); it!=mode.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	cout << "variance: " << stats.variance() << endl;
	cout << "stdDeviation: " << stats.standardDeviation() << endl;
}


/* DO NOT MODIFY ANYTHING BELOW THIS LINE */
int main()
{
   Statistics< int > iStats;
   Statistics< float > fStats;

   cout << "Enter integers separated by whitespace. Press CTRL-D on an empty line to end." << endl;;

   /* Set up an input iterator and process the user input for integers */
   istream_iterator< int > i_in_it( cin );
   for( ; i_in_it != istream_iterator<int>(); i_in_it++ )
   {
      if ( !cin.fail() )
      {
         iStats.push_back(*i_in_it);
      }
   }

   showStats( iStats );

   /* Clear the EOF we recieved from integer inputs */
   cin.clear();

   cout << endl << endl;
   cout << "Enter floats separated by whitespace. Press CTRL-D on an empty line to end." << endl;;

   /* Set up an input iterator and process the user input for integers */
   istream_iterator< float > f_in_it( cin );
   for( ; f_in_it != istream_iterator<float>(); f_in_it++ )
   {
      if ( !cin.fail() )
      {
         fStats.push_back(*f_in_it);
      }
   }
   showStats( fStats );

}
