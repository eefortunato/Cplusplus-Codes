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
 * Name: main
 *
 * Description: this is the main function in which me test our functions to print the pine tree given the rows by the user
 *
 * Arguments: it receives nothing from the command line
 *
 * Returns: it returns 0 if everything worked correctly
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


