#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
#include <Windows.h>
#include <fstream>
#include "Cours.h"
#include "Student.h"

using namespace std;

//Flux d'entrée pour les élèments de types Student
istream& operator>>(istream& istr, Student& r) {
	istr >> r.StudentFName;
	cout << endl;
	istr >> r.StudentName;
	cout << endl;
	istr >> r.StudentID;
	cout << endl;
	return istr;
}

//Flux de sortie pour les élèments de types Student
ostream& operator<<(ostream& ostr, const Student& r) {
	ostr << "Name:" << r.StudentFName << endl;
	ostr << "Lastname:" << r.StudentName << endl;
	ostr << "ID:" << r.StudentID << endl;
	cout << endl;

	return ostr;
}

bool operator==(const Student& v, const Student& r) {
	if (v.StudentID == r.StudentID)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const Student& v, const Student& r) {
	if (v.StudentID != r.StudentID)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Flux d'entrée pour les élèments de types Cours
istream& operator>>(istream& istr, Cours& r) {
	istr >> r.CourseID;
	cout << endl;
	istr >> r.CourseCode;
	cout << endl;
	istr >> r.CourseTitle;
	cout << endl;
	return istr;
}

//Flux de sortie pour les élèments de types Cours
ostream& operator<<(ostream& ostr, const Cours& r) {
	ostr << r.CourseID;
	cout << ",";
	ostr << r.CourseCode;
	cout << ",";
	ostr << r.CourseTitle;
	cout << endl;
	return ostr;
}

bool operator==(const Cours& r, const Cours& v){

}
bool operator!=(const Cours& r, const Cours& v){
	
}