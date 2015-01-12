/*
 * tree.cpp
 *
 * Created on: Feb 1, 2014
 *      Author: Eric Fortunato
 *
 *  Description: this file contains the definition of the functions used in the tree program.
 */
#include <iostream>
#include "tree.h"
using namespace std;

/*
 * Name: printAsterisc
 *
 * Description: this function prints the pine tree without the trunk
 *
 * Arguments: it receives the height as an int
 *
 * Returns: it returns nothing
 */

void printAsterisc(int height){
		int temp = height-1;
		int count = height-2;
		for(int i=0; i < height; i++){
			if(height>0){
				for(int k=0; k<temp; k++){
					cout << " ";
				}
				for(int m=count; m < height-1; m++){
					cout << "*";
				}
				cout << endl;
			temp--;
			count-=2;
			}
			else{
				cout << "*";
			}
		}
}

/*
 * Name: printTrunk
 *
 * Description: this function prints the trunk of the tree
 *
 * Arguments: it receives the height of the tree as an int
 *
 * Returns: it returns nothing
 */

void printTrunk(int height){
	if(height <=4){
		if(height >0){
				for(int j=0; j < height-1; j++){
					cout << " ";
				}
				cout << "*" << endl;
		}
		else{
			cout << "*" << endl;
		}
	}

	else if(height >=5 && height <=39){
		for(int i=0; i<2; i++){
			for(int k=0; k < height-2; k++){
				cout << " ";
			}
			cout << "***" << endl;
		}
	}
	else if(height >= 40){
		for(int i=0; i<3; i++){
			for(int l=0; l <= height-3; l++){
				cout << " ";
				}
			cout << "*****" << endl;
		}
	}
}
