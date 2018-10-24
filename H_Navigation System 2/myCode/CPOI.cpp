/*
 * CPOI.cpp
 *
 *  Created on: 04.11.2017
 *      Author: himel
 */
#include<string>
#include <iostream>
#include "CPOI.h"


using namespace std;


CPOI::CPOI(t_poi type, string name, string description, double latitude, double longitude){

	m_type=type;
	m_description = description;
	set(name,latitude,latitude);//***
}

void CPOI::getAllDataByReferencePoi(string& name, double& latitude, double& longitude, t_poi& type,string& description)
{
	type = m_type;//****
	description = m_description;
	name =m_name;
	latitude =m_latitude;
	longitude = m_longitude;

}

void CPOI::printPoi()
{
	switch(m_type)//****** m_type not t_poi
	{
	case HOTEL:
		cout<<"POI Created, Name: "<<m_name<<", with coordinate ( "<<m_latitude<<" , "<<m_longitude<<" )"<<" Type: Hotel, Description: "<<m_description<<endl;
		break;
	case SHOPPING:
		cout<<"POI Created, Name: "<<m_name<<", with coordinate ( "<<m_latitude<<" , "<<m_longitude<<" )"<<" Type: Shopping, Description: "<<m_description<<endl;
		break;
	case GYM:
		cout<<"POI Created, Name: "<<m_name<<", with coordinate ( "<<m_latitude<<" , "<<m_longitude<<" )"<<" Type: Gym, Description: "<<m_description<<endl;
		break;
	case NONE:
		cout<<"Does not match any type"<<endl;
	}

}
