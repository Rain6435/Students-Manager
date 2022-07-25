#pragma once
#ifndef COURS_H
#define COURS_H

#include <string>
#include <iostream>
#include "Student.h"
using namespace std;


//Création de la classe Cours
class Cours{
    // Ajout des opérateurs d'entrée et de sortie
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
    //Définition des objets de la classe 
    int CourseID;
    string CourseCode;
    string CourseTitle;
    vector<Student> ListMembers;

//Définition du constructeur par défaut
public:Cours() {};
//Définition du constructeur paramètré
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