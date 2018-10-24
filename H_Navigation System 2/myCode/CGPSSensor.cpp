/*
 * CGPSSensor.cpp
 *
 *  Created on: 04.11.2017
 *      Author: himel
 */

#include "CGPSSensor.h"
#include "CWaypoint.h"
#include<iostream>

using namespace std;

CGPSSensor::CGPSSensor()
{
	cout<<"GPS Activated"<<endl;
}

CWaypoint CGPSSensor::getCurrentPosition()
{

	string name="Current Position";
	double latitude;
	double longitude;

	cout<<"enter current positions latitude: "<<endl;
	cin>>latitude;

	cout<<"enter current positions longitude: "<<endl;
	cin>>longitude;

	cout<<"Current Coordinate: ("<<latitude<<" , "<<longitude<<")"<<endl;

	CWaypoint temp(name,latitude,longitude);///******
	return temp;
}
