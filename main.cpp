#include<iostream> 
#include<string> 

#include "degree.h"
#include "roster.h"
#include "student.h"

using namespace std;

int main() {

	const string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	};

	size_t classRosterSize = sizeof(studentData) / sizeof(studentData[0]);

	Roster classRoster(studentData, classRosterSize);

	classRoster.printAll();

	classRoster.printInvalidEmails();

	for (size_t i = 0; i < classRosterSize; i++) {

		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());

	};

	cout << '\n';

	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");

	return 0;

};