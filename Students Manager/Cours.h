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
};

#endif