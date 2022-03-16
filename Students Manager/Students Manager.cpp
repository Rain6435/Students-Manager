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
#include "Notes.h"
#include "Student.h"
using namespace std;

//template < typename T>
//pair<bool, Student> findInVector(const vector<T>& vecOfElements, const T& element)
//{
//    pair<bool,Student > result;
//     Find given element in vector
//    auto it = find(vecOfElements.begin(), vecOfElements.end(), element);
//    if (it != vecOfElements.end())
//    {
//        result.second = distance(vecOfElements.begin(), it);
//        result.first = true;
//    }
//    else
//    {
//        result.first = false;
//        result.second = -1;
//    }
//    return result;
//}

static Student StudentInputForCreate() {
    int ID; string Name, Lname;
    cout << "What is the students ID? \n";
    cin >> ID;
    cout << "What is the students name? \n";
    cin >> Name;
    cout << "What is the students last name? \n";
    cin >> Lname;
    return Student(ID, Name, Lname);
}
static Student StudentInputForSearch() {
    int ID;
    cout << "What is the students ID? \n";
    cin >> ID;
    return Student(ID);
}

void DisplayAllStudents(vector<Student> k) {
    for (auto x : k) {
        cout << endl << x;
    }
}

void SearchStudent(vector<Student> k) {
    Student t = StudentInputForSearch();
    for (auto x : k) {

        //Condition d'existance
        if (x.StudentID == t.StudentID)
        {
            cout << endl<< x;
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
}

Student SearchStudentForUpdate(vector<Student> k) {
    Student t = StudentInputForSearch();
    for (auto x : k) {
        if (x.StudentID == t.StudentID)
        {
            return x;
        }
        else
        {
            cout << "The student doesn't exist, try again!"<<endl;
            SearchStudentForUpdate(k);
        }
    }
}

bool requestToContinue(){
    string res;
    cout << "Would you like to add another student?(Yes or No)\n";
    cin >> res;
    if (res == "No")
    {
        return false;
    }
    else if (res == "no")
    {
        return false;
    }
    else
    {
        return true;
    }
}
void CreateStudent(Student t,vector<Student> k) {
    k.push_back(t);
    bool b = requestToContinue();
    //cout << boolalpha <<b;
    if (b == true) {
        CreateStudent(t, k);
    }
    if(b == false)
    {
        DisplayAllStudents(k);
        cout << "Perfect, have a great day!";
    };
}
void CreateStudent(vector<Student> k) {
    Student t = StudentInputForCreate();
    k.push_back(t);
    bool b = requestToContinue();
    //cout << boolalpha<< b;
    if (b == true) {
        CreateStudent(k);
    }
    if(b == false)
    {
        DisplayAllStudents(k);
        cout << "Perfect, have a great day!";
    };
}
void UpdateStudent(vector<Student> k){
    Student t = SearchStudentForUpdate(k);
    for (auto x : k) {
        if (x.StudentID == t.StudentID)
        {
            x = StudentInputForCreate();
        }
        else
        {
            UpdateStudent(k);
        }
    }
}
void DeleteStudent(vector<Student> k) {
    Student t = StudentInputForSearch();
    for (auto x : k)
    {
        if (x.StudentID == t.StudentID)
        {
            x.StudentID = NULL;
            x.StudentFName = "";
            x.StudentName = "";
        }
    }
    DisplayAllStudents(k);
}

void createTemplateList(vector<Student> k) {
    Student a = Student(1,"Lo","Ad");
    Student b = Student(2, "Ka", "Af");
    Student c = Student(3, "Ma", "Gh");
    Student d = Student(4, "Jo", "Op");
    k.push_back(a);
    k.push_back(b);
    k.push_back(c);
    k.push_back(d);
    DisplayAllStudents(k);
}

int main()
{
    vector<Student> ListOfStudents;
    vector<Notes> ListOfNotes;
    vector<Cours> ListOfCourses;

    

    createTemplateList(ListOfStudents);
    DeleteStudent(ListOfStudents);
    
}
