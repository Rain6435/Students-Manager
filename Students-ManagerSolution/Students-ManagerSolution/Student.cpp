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

// Flux d'entrée pour les élèments de types Student
istream& operator>>(istream& istr, Student& r)
{
	istr >> r.StudentFName;
	cout << endl;
	istr >> r.StudentName;
	cout << endl;
	istr >> r.StudentID;
	cout << endl;
	return istr;
}

// Flux de sortie pour les élèments de types Student
ostream& operator<<(ostream& ostr, const Student& r)
{
	ostr << "Name:" << r.StudentFName << endl;
	ostr << "Lastname:" << r.StudentName << endl;
	ostr << "ID:" << r.StudentID << endl;
	cout << endl;

	return ostr;
}

bool operator==(const Student& v, const Student& r)
{
	if (v.StudentID == r.StudentID)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const Student& v, const Student& r)
{
	if (v.StudentID != r.StudentID)
	{
		return true;
	}
	else
	{
		return false;
	}
}