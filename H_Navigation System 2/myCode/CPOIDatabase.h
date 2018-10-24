/*
 * CPOIDatabase.h
 *
 *  Created on: 04.11.2017
 *      Author: himel
 */

#ifndef CPOIDATABASE_H_
#define CPOIDATABASE_H_
#include "CPOI.h"


class CPOIDatabase
{
private:
	CPOI m_poi[10];
	int m_noPoi;
public:
	CPOIDatabase();
	void addPoi(t_poi type, string name, string description, double latitude,double longitude);
	CPOI* getPointerToPoi(string name);
};

#endif /* CPOIDATABASE_H_ */
