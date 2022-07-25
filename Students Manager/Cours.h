#pragma once
#ifndef COURS_H
#define COURS_H

#include <string>
#include <iostream>
#include "Student.h"
using namespace std;


//Cr�ation de la classe Cours
class Cours{
    // Ajout des op�rateurs d'entr�e et de sortie
    friend istream& operator>>(istream&, Cours&);					
    friend ostream& operator<<(ostream&, const Cours&);
    friend bool operator==(const Cours& v, const Cours& r);
    friend bool operator!=(const Cours& v, const Cours& r);

    static Cours CourForCreate(){
        int CID; string CCode; string CTitle;
        cout << "What is the course ID? \n";
        cin >> CID;
        cout << "What is the course code? \n";
        cin >> CCode;
        cout << "What is the course title? \n";
        cin >> CTitle;
        return Cours(CID,CCode,CTitle);
    }

    friend void CreateCours(vector<Cours> s){
        Cours cour = CourForCreate();
    }

    friend void AddMembers(vector<Cours> s, vector<Student> k){}

public:
    //D�finition des objets de la classe 
    int CourseID;
    string CourseCode;
    string CourseTitle;
    vector<Student> ListMembers;

//D�finition du constructeur par d�faut
public:Cours() {};
//D�finition du constructeur param�tr�
public:Cours(int CID, string Code, string Title, vector<Student> CMembers)
{
    CourseID = CID;
    CourseCode = Code;
    CourseTitle = Title;
    ListMembers = CMembers;
}
public:Cours(int CID, string Code, string Title){
    CourseID = CID;
    CourseCode = Code;
    CourseTitle = Title;
}
};

#endif