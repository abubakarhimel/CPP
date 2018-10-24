/*
 * CPOIDatabase.cpp
 *
 *  Created on: 04.11.2017
 *      Author: himel
 */

#include "CPOIDatabase.h"
#include<iostream>

using namespace std;

CPOIDatabase::CPOIDatabase()//***
{
	CPOI defaultPoi;
	for(int index=0; index<10;index++){
		m_poi[index]=defaultPoi;
	}
	m_noPoi = 0;

}

void CPOIDatabase::addPoi(t_poi type, string name, string description,
		double latitude, double longitude)
{
	CPOI newPoi ( type,name,description,latitude,longitude);

	if(m_noPoi <10)
	{
		m_poi[m_noPoi]=newPoi;//*****
		m_noPoi++;
	}

	else
	{
		cout<<"Database Full"<<endl;
	}
}

CPOI* CPOIDatabase::getPointerToPoi(string name)//*****
{
	CPOI* pPoi;

	if(m_noPoi!=0){
		for(int index =0;index<m_noPoi;index++){
			if (m_poi[index].getName() ==name){
				pPoi = &m_poi[index];
				break;
			}
			else{
				pPoi = NULL;
			}

		}

	}

	else{
		cout<<"The POI Database is empty"<<endl;
		pPoi = NULL;
	}

	return pPoi;


}
