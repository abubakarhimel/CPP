/*
 * CRoute.cpp
 *
 *  Created on: 04.11.2017
 *      Author: himel
 */

#include "CRoute.h"
#include<iostream>

using namespace std;

CRoute::CRoute(unsigned int maxWp, unsigned int maxPoi){

	m_nextWp =0;
	m_nextPoi =0;
	m_maxWp = maxWp;
	m_maxPoi = maxPoi;
	m_pWaypoint = new CWaypoint [m_maxWp];
	m_pPoi = new CPOI* [m_maxPoi];
	m_pPoiDatabase = NULL;

}

CRoute::CRoute(CRoute const& origin){

	m_maxWp = origin.m_maxWp;
	m_maxPoi = origin.m_maxPoi;
	m_nextWp = origin.m_nextWp;
	m_nextPoi = origin.m_nextPoi;
	m_pPoiDatabase = origin.m_pPoiDatabase;

	m_pWaypoint = new CWaypoint [origin.m_maxWp];

	for(unsigned int i=0; i<m_maxWp;i++){
		m_pWaypoint[i] = origin.m_pWaypoint[i];
	}

	m_pPoi = new CPOI* [origin.m_maxPoi];

	for(unsigned int i=0; i<m_maxPoi;i++){
			m_pPoi[i] = origin.m_pPoi[i];
		}

}

CRoute::~CRoute(){

	delete[] m_pWaypoint;
	delete[] m_pPoi;

}

void CRoute::connectToPoiDatabase(CPOIDatabase* pPoiDb){
m_pPoiDatabase = pPoiDb;
}

void CRoute::addWaypoint(CWaypoint const& wp){

	if(m_nextWp<m_maxWp){
		*(m_pWaypoint+m_nextWp) = wp;///*****
		m_nextWp++;
	}

	else{
		cout<<"Excidded max waypoint limit"<<endl;
	}
}

void CRoute::addPoi(string namePoi){//*****

	{
		if((this->m_nextPoi < this->m_maxPoi) && (m_pPoiDatabase != NULL))
		{
			//Condition to avoid adding POI if it is not present in POIDB
			if((this->m_pPoiDatabase)->getPointerToPoi(namePoi) != NULL)
			{
				*(this->m_pPoi + this->m_nextPoi)
							= (this->m_pPoiDatabase)->getPointerToPoi(namePoi);
	#ifdef SHOWOBTADDR
			cout<<"Memory address written at pPoi+"<<m_nextPoi<<"  "<<
					*(this->m_pPoi + this->m_nextPoi)<<endl; //only for debugging
	#endif

				this->m_nextPoi++;
			}
			else
			{
				cout<<endl<<"ERROR: No such Point of interest in Database..!!"
						<<endl;
			}
		}
		else
		{
			cout<<endl<<"ERROR: The Point of interest cannot be added due to any of"
					" the following reasons:"<<endl<<
					"1. It exceeds the maximum number of Point of interests"<<endl<<
					"2. You are not connected to the database"<<endl;
		}

	}
}

double CRoute::getDistanceToNextPoi(CWaypoint const& wp, CPOI& poi)
{
	double shortestDist = 0.0;

	if(m_nextPoi != 0)
	{
		shortestDist = (* *m_pPoi).calculateDistance(wp);
		poi = (* *m_pPoi);
		for(unsigned int index = 0; index < m_nextPoi; index++)
		{
			if(shortestDist > (* *(m_pPoi + index)).calculateDistance(wp))
			{
				shortestDist = (* *(m_pPoi + index)).calculateDistance(wp);

				poi = (* *(m_pPoi + index));
			}
		}
	}
	else
	{
		shortestDist = 0;
		poi.set("MaxPOI is Zero",0.0,0.0);
	}
	return shortestDist;
}

void CRoute::print()
{
	CPOI* tempPoi;

	cout<<endl<<"Our route has "<<this->m_nextWp<<"/"<<this->m_maxWp<<
			" Waypoints and "<<this->m_nextPoi<<"/"<<this->m_maxPoi
			<<" point of interests"<<endl<<endl;
	for(unsigned int index = 0; index < this->m_nextWp; index++)
	{
		((this->m_pWaypoint) + index)->print(MMSS);
	}

	cout<<endl;

	for(unsigned int index = 0; index < this->m_nextPoi; index++)
	{
		tempPoi = *((this->m_pPoi) + index);

#ifdef SHOWOBTADDR
		cout<<"Value @ Memory address of pPoi+ "<<index<<" is: "<< //only for debugging
				*((this->m_pPoi) + index)<<endl;
#endif
		tempPoi->printPoi();
		cout<<endl;
	}
	cout<<endl;
}



