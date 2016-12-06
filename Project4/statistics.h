/**
 * @file
 * @author Eric Fortunato
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This is the statistics template class declaration and implementation to handle basic statistics functions.
 */

#ifndef STATISTICS_H_
#define STATISTICS_H_

#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <map>
#include <iostream>
#include <stdexcept>

template <typename T>
class Statistics: public std::vector<T>{
public:
	Statistics(){} //default constructor
	T mean(); //method for calculating the mean
	T median(); //method for calculating the median
	std::set<T> mode(); //method for calculating and setting the mode
	T variance(); //method for calculating variance
	T standardDeviation(); //method for calculating standard deviation

};

/**
 * This is the method for calculating the mean of all the elements
 *
 * The mean of all the elements is calculated using the concept defined in this link:
 * http://en.wikipedia.org/wiki/Mean#Arithmetic_mean_.28AM.29
 *
 * @throws underflow_error if there are 0 elements
 * @return mean of all the values
 */
template <typename T>
T Statistics<T>::mean(){
	if(this->size() ==0){
		throw std::underflow_error("Insufficient data");
	}
	T result=accumulate(this->begin(), this->end(), 0);

	return result/=this->size();

}

/**
 * This is the method for calculating the median of all the elements
 *
 * The meadian of all the elements is calculated using the concept defined in this link:
 * http://www.mathsisfun.com/median.html
 *
 * @throws underflow_error if there are 0 elements
 * @return mean of all the values
 */

template <typename T>
T Statistics<T>::median(){
	if(this->size() ==0){
		throw std::underflow_error("Insufficient data");
	}
	int halfVector=this->size()/2;
	sort(this->begin(),this->end(), typename std::less<T>());
	if(halfVector%2 != 0){
		return this->operator[](halfVector);
	}

	T result= this->operator[](halfVector) + this->operator [](halfVector-1);

	return result/2;
}

/**
 * This is the method for calculating and setting the mode of all the elements
 *
 * The mode of all the elements is calculated using the concept defined in this link:
 * http://www.purplemath.com/modules/meanmode.htm
 *
 * @throws underflow_error if there are 0 elements
 * @return mean of all the values
 */

template <typename T>
std::set<T> Statistics<T>::mode(){
	if(this->size() ==0){
		throw std::underflow_error("Insufficient data");
	}
	typename std::map<T,int> numbersToCompare;
	typedef typename std::map<T,int>::value_type Pair;

	int counter=0;
	for(typename Statistics<T>::iterator it=this->begin(); it < this->end(); ++it){
		typename std::map<T, int>::iterator number=numbersToCompare.find(*it);
		if(number != numbersToCompare.end()){
			numbersToCompare[*it]+=1;
		}
		else{
			numbersToCompare.insert(Pair(*it, 1));
		}
		if(numbersToCompare[*it] > counter){
			counter= numbersToCompare[*it];
		}
	}
	typename std::set<T> modeSet;
	for(typename std::map<T, int>::iterator it= numbersToCompare.begin(); it != numbersToCompare.end(); ++it){
		if(it->second == counter){
			modeSet.insert(it->first);
		}
	}
		return modeSet;
}

/**
 * This is the method for calculating the variance of all the elements
 *
 * The variance of all the elements is calculated using the concept defined in this link:
 * http://www.mathsisfun.com/data/standard-deviation.html
 *
 * @throws underflow_error if there are less than 2 elements
 * @return mean of all the values
 */

template <typename T>
T Statistics<T>::variance(){
	if(this->size() <=1){
		throw std::underflow_error("Insufficient data");
	}
	T calculatedMean = this->mean();
	 T result = 0;
	 for(typename Statistics<T>::iterator it = this->begin(); it != this->end(); ++it)
	 {
		 result+=pow(*it-calculatedMean,2);
	 }
	 return result/(this->size()-1);
}

/**
 * This is the method for calculating the standard deviation of all the elements
 *
 * The standard deviation of all the elements is calculated using the concept defined in this link:
 * http://www.mathsisfun.com/data/standard-deviation.html
 *
 * @throws underflow_error if there are less than 2 elements
 * @return mean of all the values
 */

template <typename T>
T Statistics<T>::standardDeviation(){
	if(this->size() <=1){
		throw std::underflow_error("No enough data");
	            }
	return sqrt(variance());

}
#endif /* STATISTICS_H_ */
