/*
 * tree.cpp
 *
 * Created on: Feb 1, 2014
 *      Author: Eric Fortunato
 *
 *  Description: this program prints a pine tree by the given rows
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

/*
 * Name: main
 *
 * Description: this is the main function in which me test our functions to print the pine tree given the rows by the user
 *
 * Arguments: it receives nothing from the command line
 *
 * Returns: it returns 0 if everthing worked correctly
 */

int main(){

	int rows=0;
	cout << "Enter height of tree (in rows): ";
	cin >> rows;
	cout << endl;
	printAsterisc(rows);
	printTrunk(rows);

	return 0;
}


