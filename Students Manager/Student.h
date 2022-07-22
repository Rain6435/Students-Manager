#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;


//Création de la classe Student
class Student {
    
    // Ajout des opérateurs d'entrée et de sortie
    friend istream& operator>>(istream&, Student&);
    friend ostream& operator<<(ostream&, const Student&);
    friend bool operator==(Student& v, Student& r);
    friend bool operator!=(Student& v, Student& r);


    static Student StudentInputForCreate() {
        int ID; string Name; string Lname;
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
        cout << "What is the student's ID? \n";
        cin >> ID;
        return Student(ID);
    }
    friend Student SearchStudentForUpdate(vector<Student>& k) {
        Student t = StudentInputForSearch();
        for (auto x : k) {
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
    };
    static bool RequestToContinue() {
        string res;
        cout << "Would you like to add another student?(Yes or No)\n";
        cin >> res;

        transform(res.begin(), res.end(), res.begin(), ::toupper);

        if(res == "NO") 
        {
            return false;
        }else if(res == "YES") {
            return true;
        } else {
            cout << "Please enter a valid answer!";
            RequestToContinue();
        }
    };
    friend void SearchStudent(vector<Student>& k) {
        Student t = StudentInputForSearch();
        for (auto x : k) {

            //Condition d'existance
            if (x.StudentID == t.StudentID)
            {
                cout << endl << x;
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
    friend void CreateStudent(Student& t, vector<Student>& k) {
        k.push_back(t);
        bool b = RequestToContinue();
        //cout << boolalpha <<b;
        if (b == true) {
            CreateStudent(t, k);
        }
        if (b == false)
        {
            DisplayAllStudents(k);
            cout << "Perfect, have a great day!";
        };
    };
    friend void CreateStudent(vector<Student>& k) {
        Student t = StudentInputForCreate();
        k.push_back(t);
        bool b = RequestToContinue();
        //cout << boolalpha<< b;
        if (b == true) {
            CreateStudent(k);
        }
        if (b == false)
        {
            DisplayAllStudents(k);
            cout << "Perfect, have a great day!";
        };
    };
    friend void UpdateStudent(vector<Student>& k) {
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
    };
    friend void DeleteStudent(vector<Student>& k) {
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

        friend void DisplayAllStudents(vector<Student>& k) {
        for (auto x : k) {
            cout << endl << x;
        }
    };

    friend void CreateTemplateList(vector<Student>& k) {
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
public:
    //Définition des objets de la classe 
    int StudentID;
    string StudentName;
    string StudentFName;
//Définition du construteur par défaut
public:Student(){

};

//Définition du constructeur paramètré
public:Student(int ID, string Name, string FName) {
    StudentID = ID;
    StudentName = Name;
    StudentFName = FName;
}
public:Student(int ID) {
    StudentID = ID;
    StudentName = "Undefined";
    StudentFName = "Undefined";
}
};
#endif
