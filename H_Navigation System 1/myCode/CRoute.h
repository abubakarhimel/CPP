/*
 * CRoute.h
 *
 *  Created on: 04.11.2017
 *      Author: himel
 */

#ifndef CROUTE_H_
#define CROUTE_H_
#include "CWaypoint.h"
#include "CPOI.h"
#include "CPOIDatabase.h"

class CRoute
{
private:
	CWaypoint* m_pWaypoint;
	unsigned int m_maxWp;
	unsigned int m_nextWp;
	CPOI** m_pPoi;
	unsigned int m_maxPoi;
	unsigned int m_nextPoi;
	CPOIDatabase* m_pPoiDatabase;
public:
	CRoute(unsigned int maxWp, unsigned int maxPoi);
	CRoute(CRoute const& origin);
	void connectToPoiDatabase(CPOIDatabase* pPoiDb);
	void addWaypoint(CWaypoint const& wp);
	void addPoi(string namePoi);
	double getDistanceToNextPoi(CWaypoint const& wp, CPOI& poi);
	void print();
	~CRoute();

};

#endif /* CROUTE_H_ */
