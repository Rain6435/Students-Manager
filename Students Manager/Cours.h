#pragma once
#ifndef COURS_H
#define COURS_H


#include <string>
#include <iostream>
using namespace std;


//Création de la classe Cours
class Cours{
    // Ajout des opérateurs d'entrée et de sortie
    friend istream& operator>>(istream&, Cours&);					
    friend ostream& operator<<(ostream&, const Cours&);			
public:
    //Définition des objets de la classe 
    int CourseID;
    string CourseCode;
    string CourseTitle;

//Définition du constructeur par défaut
public:Cours();
//Définition du constructeur paramètré
public:Cours(int CID, string Code, string Title)
{
    CourseID = CID;
    CourseCode = Code;
    CourseTitle = Title;
}
};

#endif
