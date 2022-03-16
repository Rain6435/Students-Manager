#pragma once
#ifndef NOTES_H
#define NOTES_H

#include<string>
#include <iostream>
#include "Student.h"
#include "Cours.h"
using namespace std;


//Création de la classe Notes avec comme héritage la classe Cours et la classe Student
class Notes : public Cours, public Student{
    // Ajout des opérateurs d'entrée et de sortie
    friend istream& operator>>(istream&, Notes&);				
    friend ostream& operator<<(ostream&, const Notes&);			
public:
    //Définition des objets de la classe 
    string Identifier;
    float Note;
    Cours::CourseCode;
    Student::StudentID;

 //Définition du constructeur paramètré
public:Notes(string Ident, float StNotes, int StID, string CrID) {
    Identifier = Ident;
    Note = StNotes;
    CourseCode = CrID;
    StudentID = StID;
}
};
#endif
