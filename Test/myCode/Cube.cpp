/*
 * Cube.cpp
 *
 *  Created on: 03.11.2017
 *      Author: himel
 */
#include <iostream>
#include "Cube.h"
using namespace std;

int Cube::cubeByValue(int n)
{
	return n*n*n;
}

void Cube::cubeByReference(int* nPtr)
{
	*nPtr = *nPtr * *nPtr * *nPtr;

	cout<<*nPtr<<endl;
}
