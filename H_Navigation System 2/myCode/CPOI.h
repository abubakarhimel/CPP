/*
 * CPOI.h
 *
 *  Created on: 04.11.2017
 *      Author: himel
 */

#ifndef CPOI_H_
#define CPOI_H_
#include<string>
#include"CWaypoint.h"
using namespace std;

enum t_poi {HOTEL, SHOPPING, GYM,NONE};

class CPOI:public CWaypoint//***
{

public:
	CPOI(t_poi type= NONE, string name ="Default Name", string description="Default Description", double latitude =0, double longitude=0);

	void printPoi();

	void getAllDataByReferencePoi(string& name, double& latitude, double& longitude, t_poi& type,string& description);

private:
	t_poi m_type;
	string m_description;
};

#endif /* CPOI_H_ */
