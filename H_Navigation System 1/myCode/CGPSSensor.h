/*
 * CGPSSensor.h
 *
 *  Created on: 04.11.2017
 *      Author: himel
 */

#ifndef CGPSSENSOR_H_
#define CGPSSENSOR_H_
#include "CWaypoint.h"

class CGPSSensor:public CWaypoint
{
public:
	CGPSSensor();
	CWaypoint getCurrentPosition();

};

#endif /* CGPSSENSOR_H_ */
