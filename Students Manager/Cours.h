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
};

#endif