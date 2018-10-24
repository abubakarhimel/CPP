/*
 * CNavigationSystem.h
 *
 *  Created on: 04.11.2017
 *      Author: himel
 */

#ifndef CNAVIGATIONSYSTEM_H_
#define CNAVIGATIONSYSTEM_H_
#include "CGPSSensor.h"
#include"CRoute.h"
#include"CPOIDatabase.h"

class CNavigationSystem
{
public:

	CNavigationSystem();

	void run();

private:

	void enterRoute();

	void printRoute();

	void printDistanceCurrPosToNxtPoi();

	CGPSSensor m_GPSSensor;
	CRoute m_route;
	CPOIDatabase m_POIDatabase;
};

#endif /* CNAVIGATIONSYSTEM_H_ */
