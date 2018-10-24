
#include <iostream>
#include "CWaypoint.h"
#include <string>
#include "CGPSSensor.h"
#include "CPOI.h"
#include "CPOIDatabase.h"
#include "CNavigationSystem.h"


//#define TEST_FOR_CWAYPOINT
//#define GPS_TEST
//#define CPOI_TEST
//#define DATABASE_TEST

using namespace std;
int main (void)
{
#ifdef TEST_FOR_CWAYPOINT
	CWaypoint amsterdam("amsterdam",52.3545653,4.7585408);
	CWaypoint darmstadt("darmstadt",49.8748973,8.5147364);
	CWaypoint berlin("berlin",52.5069312,13.144546);
	CWaypoint tokio("tokio",35.6693863,139.6012936);
	CWaypoint newWaypoint();

	amsterdam.print(DEGREE);
	amsterdam.print(MMSS);
	amsterdam.getName();

	string name;
	double latitude,longitude;
	amsterdam.getAllDataByReference(name,latitude,longitude);

	cout<<"Distance between amstardam and berlin is: "<<berlin.calculateDistance(amsterdam)<<" KM"<<endl;

	cout<<"Distance between amstardam and tokio is: "<<berlin.calculateDistance(tokio)<<" KM"<<endl;
#endif

#ifdef GPS_TEST
	CGPSSensor testGps;
	testGps.getCurrentPosition();
#endif

#ifdef CPOI_TEST
	CPOI poiTest(GYM,"Sheraton","Good Hotel",23.5487,90.3654);
	poiTest.printPoi();
#endif

#ifdef DATABASE_TEST

	CPOIDatabase ob;
	ob.addPoi(HOTEL,"Martim","Best hotel in darmstadt",23.455,90.4242);
	ob.addPoi(HOTEL,"Srraton","Best hotel in darmstadt",23.455,90.4242);
	ob.addPoi(HOTEL,"xx","Best hotel in darmstadt",23.455,90.4242);
	ob.addPoi(HOTEL,"yy","Best hotel in darmstadt",23.455,90.4242);
	ob.addPoi(HOTEL,"zz","Best hotel in darmstadt",23.455,90.4242);
	ob.addPoi(HOTEL,"aa","Best hotel in darmstadt",23.455,90.4242);
	ob.addPoi(HOTEL,"bb","Best hotel in darmstadt",23.455,90.4242);
	ob.addPoi(HOTEL,"cc","Best hotel in darmstadt",23.455,90.4242);
	ob.addPoi(HOTEL,"dd","Best hotel in darmstadt",23.455,90.4242);
	ob.addPoi(HOTEL,"ee","Best hotel in darmstadt",23.455,90.4242);

//	string name ="bb";
//	ob.getPointerToPoi(name);
#endif

//CNavigationSystem ob;
//ob.run();

	CWaypoint ob("Da",23.3,90.43);

	ob.print(DEGREE);
	ob.print(MMSS);
	cout<<ob.getName()<<endl;

	return 0;
}
