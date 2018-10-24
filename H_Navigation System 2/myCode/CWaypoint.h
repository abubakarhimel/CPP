/*
 * CWaypoint.h
 *
 *  Created on: 03.11.2017
 *      Author: himel
 */

#ifndef CWAYPOINT_H_
#define CWAYPOINT_H_
#include <string>

#define DEGREE  1
#define MMSS  2

using namespace std;

class CWaypoint
{
protected:
	string m_name;
	double m_latitude;
	double m_longitude;
public:
	CWaypoint(string name="", double longitude =0, double latitude=0);
	void set(string name, double longitude, double latitude);
	string getName();
	double getLatitude();
	double getLongitude();
	void getAllDataByReference(string& name, double &longitude, double& latitude);
	double calculateDistance(const CWaypoint& wp);
	void print(int format);
private:
	void transformLongitude2degmmss(int& deg, int& mm, double& ss);
	void transformLatitude2degmmss(int& deg, int& mm, double& ss);

};

#endif /* CWAYPOINT_H_ */
