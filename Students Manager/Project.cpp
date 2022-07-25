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



// Flux d'entrée pour les élèments de types Cours
istream &operator>>(istream &istr, Cours &r)
{
	istr >> r.CourseID;
	cout << endl;
	istr >> r.CourseCode;
	cout << endl;
	istr >> r.CourseTitle;
	cout << endl;
	return istr;
}

// Flux de sortie pour les élèments de types Cours
ostream &operator<<(ostream &ostr, const Cours &r)
{
	ostr << r.CourseID;
	cout << ",";
	ostr << r.CourseCode;
	cout << ",";
	ostr << r.CourseTitle;
	cout << endl;
	return ostr;
}

bool operator==(const Cours &r, const Cours &v)
{
	if (r.CourseID == v.CourseID && r.CourseCode == v.CourseCode)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator!=(const Cours &r, const Cours &v)
{
	if (r.CourseID != v.CourseID || r.CourseCode != v.CourseCode)
	{
		return true;
	}
	else
	{
		return false;
	}
}
static bool RequestToContinue()
{
	string res;
	cout << "Would you like to add another student?(Yes or No)\n";
	cin >> res;

	transform(res.begin(), res.end(), res.begin(), ::toupper);

	if (res == "NO")
	{
		return false;
	}
	else if (res == "YES")
	{
		return true;
	}
	else
	{
		cout << "Please enter a valid answer!";
		RequestToContinue();
	}
};

static Student StudentInputForSearch()
{
	int ID;
	cout << "What is the student's ID? \n";
	cin >> ID;
	return Student(ID);
}

static Student StudentInputForCreate()
{
	int ID;
	string Name;
	string Lname;
	cout << "What is the students ID? \n";
	cin >> ID;
	cout << "What is the students name? \n";
	cin >> Name;
	cout << "What is the students last name? \n";
	cin >> Lname;
	return Student(ID, Name, Lname);
}
static Student SearchStudentForUpdate(vector<Student>& k)
{
	Student t = StudentInputForSearch();
	for (auto x : k)
	{
		if (x.StudentID == t.StudentID)
		{
			return x;
		}
		else
		{
			cout << "The student doesn't exist, try again!" << endl;
			SearchStudentForUpdate(k);
		}
	}
}

static void SearchStudent(vector<Student> &k)
{
	Student t = StudentInputForSearch();
	for (auto x : k)
	{

		// Condition d'existance
		if (x.StudentID == t.StudentID)
		{
			cout << endl
				 << x;
		}
		else
		{
			cout << "The student doesn't exist.";
		}
	}
	/*int myString = t.StudentID;
	auto it = find_if(k.begin(), k.end(), [&myString](const Student& obj) {return obj.StudentID == myString; });
	if (it != k.end())
	{
		cout << "Element Found" << endl;
		// found element. it is an iterator to the first matching element.
		// if you really need the index, you can also get it:
		//auto index = distance(k.begin(), it);
	}
	else{cout << "Element Not Found" << endl;}
	vector<Student>::iterator it = find_if(k.begin(), k.end(), t);
	if (it != k.end())
		cout << "Element Found" << endl;
	else
		cout << "Element Not Found" << endl;

	pair<bool, Student> result = findInVector<Student>(k,t);
	if (result.first)
		std::cout << "Element Found at index : " << result.second << std::endl;
	else
		std::cout << "Element Not Found" << std::endl;*/
};

static void DisplayAllStudents(vector<Student>& k)
{
	for (auto x : k)
	{
		cout << endl
			<< x;
	}
};

static void CreateStudent(Student &t, vector<Student> &k)
{
	k.push_back(t);
	bool b = RequestToContinue();
	// cout << boolalpha <<b;
	if (b == true)
	{
		CreateStudent(t, k);
	}
	if (b == false)
	{
		DisplayAllStudents(k);
		cout << "Perfect, have a great day!";
	};
};
static void CreateStudent(vector<Student> &k)
{
	Student t = StudentInputForCreate();
	k.push_back(t);
	bool b = RequestToContinue();
	// cout << boolalpha<< b;
	if (b == true)
	{
		CreateStudent(k);
	}
	if (b == false)
	{
		DisplayAllStudents(k);
		cout << "Perfect, have a great day!";
	};
};
static void UpdateStudent(vector<Student> &k)
{
	Student t = SearchStudentForUpdate(k);
	for (auto x : k)
	{
		if (x.StudentID == t.StudentID)
		{
			x = StudentInputForCreate();
		}
		else
		{
			UpdateStudent(k);
		}
	}
};
static void DeleteStudent(vector<Student> &k)
{
	Student t = StudentInputForSearch();
	for (auto x : k)
	{
		if (x.StudentID == t.StudentID)
		{
			x.StudentID = 0;
			x.StudentFName = "";
			x.StudentName = "";
		}
	}
	DisplayAllStudents(k);
};

static void CreateTemplateList(vector<Student> &k)
{
	Student a = Student(1, "Lo", "Ad");
	Student b = Student(2, "Ka", "Af");
	Student c = Student(3, "Ma", "Gh");
	Student d = Student(4, "Jo", "Op");
	k.push_back(a);
	k.push_back(b);
	k.push_back(c);
	k.push_back(d);
	DisplayAllStudents(k);
};
