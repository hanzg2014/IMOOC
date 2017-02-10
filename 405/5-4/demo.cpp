#include <iostream>
#include <stdlib.h>
#include "Line.h"
using namespace std;

int main(void){

	Coordinate coor1(3,5);
	Coordinate coor2(7,9);
	Coordinate * const pCoor = &coor1;
	//const Coordinate &coor2 = coor1;
	//const Coordinate *pCoor = &coor1;

	pCoor->getY();
	//pCoor = &coor2; //const * pCoor cannnot be modified
	
	/*
	coor1.printInfo();
	coor2.printInfo();
	coor2.getX();
	pCoor->printInfo();
	*/

	system("pause");
	return 0;
}

