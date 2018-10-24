/*
 * CNavigationSystem.cpp
 *
 *  Created on: 04.11.2017
 *      Author: himel
 */

#include "CNavigationSystem.h"

#include<iostream>
#include "CWaypoint.h"

using namespace std;

CNavigationSystem::CNavigationSystem():m_route(3,2)
{

}

void CNavigationSystem::run(){

	m_POIDatabase.addPoi(SHOPPING, "Restaurant in Mannheim", "Nice restaurant",
			49.4883,8.4647);
	m_POIDatabase.addPoi(SHOPPING, "Garden in Pfungstadt", "Nice garden",
			49.8057,8.6025);
	m_POIDatabase.addPoi(SHOPPING, "Bar in Homburg", "Nice Pub", 49.3248,7.3357);
	m_POIDatabase.addPoi(GYM,"Kirche in Olley","Nice Kirche",49.16,5.76);
	m_POIDatabase.addPoi(GYM, "Landesmuseaum Darmstadt", "Nice museaum",
			52.4883,8.564);
	m_POIDatabase.addPoi(GYM, "Local Theater", "Nice theater",
			51.8057,6.6025);
	m_POIDatabase.addPoi(GYM, "Restaurant in Frankfurt", "Nice Frankfurt",
			48.3248,7.8357);
	m_POIDatabase.addPoi(GYM,"Botanical Garden","Nice Botanical garden",
			49.6714,6.76);
	m_POIDatabase.addPoi(GYM, "Bar in Karlsruhe", "Nice chillout place",
			52.3248,9.3357);
	m_POIDatabase.addPoi(HOTEL,"Kirche in Kaiserslautern","Popular Kirche",
			51.5892,9.76);
//	m_POIDatabase.addPoi(HOTEL, "Landesmuseaum Bonn", "Popular museaum",
//			54.4883,6.564);
//	m_POIDatabase.addPoi(HOTEL, "Drama Theater", "Popular theater",
//			49.5021,10.6025);


	m_route.connectToPoiDatabase(&m_POIDatabase);

	enterRoute();
	printRoute();
	printDistanceCurrPosToNxtPoi();
}


void CNavigationSystem::enterRoute(){

	m_route.addWaypoint(CWaypoint("Darmstadt", 49.8705, 8.6494));
	m_route.addWaypoint(CWaypoint("Kaiserslautern", 49.4447, 7.7690));


	m_route.addPoi("Local Theater");



}


void CNavigationSystem::printRoute(){
	m_route.print();
}


void CNavigationSystem::printDistanceCurrPosToNxtPoi()
{
	CPOI nearestPOI;

	cout<<endl<<"Distance to the next Point of interest = "<<
			m_route.getDistanceToNextPoi(m_GPSSensor.getCurrentPosition(),
					nearestPOI)<<" and Point of interest is: "<<endl;

	if(nearestPOI.getName() == "MaxPOI is Zero")
	{
		cout<<"No POIs in the list and hence zero distance..!!"<<endl;
	}
	else
	{
		nearestPOI.print(2);
	}
}
