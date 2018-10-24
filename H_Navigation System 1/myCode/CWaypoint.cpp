/*
 * CWaypoint.cpp
 *
 *  Created on: 03.11.2017
 *      Author: himel
 */

//#define SHOWADRESS

#include "CWaypoint.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#define R 6378

using namespace std;

CWaypoint::CWaypoint(string name, double  latitude, double longitude)
{
	set( name,  latitude,  longitude);

#ifdef SHOWADRESS

	cout<<"Object is created at address: "<<this<<", With name: "<<m_name<<" @ "<<&m_name<<
			", Latitude: "<<m_latitude<<" @ "<<&m_latitude<<" ,& Longitude: "<<m_longitude<<" @ "<<&m_longitude<<endl;

	cout<<"Data occupied by m_name: "<<sizeof m_name<<", m_latitude: "<<sizeof m_latitude
			<<" , & m_longitude: "<<sizeof m_longitude<<endl;

#endif
}


void CWaypoint::set(string name, double latitude, double longitude )
{

	m_name = name;


	if(latitude>=-90 && latitude<=90)//******
	{m_latitude = latitude;}
	else{
		m_latitude=0;
		cout<<"wrong latitude"<<endl;
	}

	if(longitude>=-180 && longitude<=180)
	{m_longitude = longitude;}
	else{
		m_longitude=0;
		cout<<"wrong longitude"<<endl;
	}




}

void CWaypoint::print(int format)
{
	switch (format){
		case 1:
			cout<<m_name<<" on latitude= "<<m_latitude<<" & Longitude= "<<m_longitude<<endl;
		break;

		case 2:
			int degree, minute;
			double second;
			transformLongitude2degmmss(degree,minute,second);//******
			transformLatitude2degmmss(degree,minute,second);
			break;
	}

}

void CWaypoint::transformLongitude2degmmss(int& deg, int& mm, double& ss)
{
	deg=int(m_longitude);//******
	mm = int ((m_longitude-deg)*60);
	ss =((m_longitude-deg)*60)-mm;

	cout<<m_name<<" on longitude = "<<deg<<" deg, "<<mm<<" min, "<<ss<<" sec"<<endl;
}

string CWaypoint::getName()
{

	return m_name;

}

double CWaypoint::getLatitude()
{
	return m_latitude;
}

double CWaypoint::getLongitude()
{
	return m_longitude;
}

void CWaypoint::transformLatitude2degmmss(int& deg, int& mm, double& ss)
{
	deg=int(m_latitude);//******
	mm = int ((m_latitude-deg)*60);
	ss =((m_latitude-deg)*60)-mm;

	cout<<m_name<<" on latitude = "<<deg<<" deg, "<<mm<<" min, "<<ss<<" sec"<<endl;
}

void CWaypoint::getAllDataByReference(string& name, double& latitude ,double& longitude )
{
	name = m_name;
	longitude = m_longitude;
	latitude = m_latitude;

	cout<<name<<" Has address: "<<&name<<" with latitude: "<<latitude<<" @ "<<&latitude
			<<" and longitude "<<longitude<<" @ "<<&longitude<<endl;

}

double CWaypoint::calculateDistance(const CWaypoint& wp){
	double distance;

	distance = R*(acos((sin(this->m_latitude)*sin(wp.m_latitude))+(cos(m_latitude)*cos(wp.m_latitude)*cos(wp.m_longitude-m_longitude))));

	return distance;
}
