#include <iostream>
#include "University.h"
using namespace oopn;

int main()
{
    University ui;
    Professor a[6];
    std::string names[6] = {"Holder","Reid","Dent","Zavala","Austin","Filin"};

    for(int i = 0;i < 6;i += 1) {a[i].title(names[i]);}

    ui.title("Medgar Evers College");
    ui.newDepartment("Mathematics");
    ui.getDepartment("Mathematics").addProfessor(&a[0]);
    ui.getDepartment("Mathematics").addProfessor(&a[2]);
    ui.newDepartment("Physics");
    ui.getDepartment("Physics").addProfessor(&a[4]);
    ui.getDepartment("Physics").addProfessor(&a[5]);
    ui.newDepartment("Biology");
    ui.getDepartment("Biology").addProfessor(&a[3]);
    ui.newDepartment("Computer Science");
    ui.getDepartment("Computer Science").addProfessor(&a[1]);
    ui.getDepartment("Computer Science").addProfessor(&a[2]);
    ui.newDepartment("Nursing");
    ui.getDepartment("Nursing").addProfessor(&a[1]);
    ui.newDepartment("English");
    ui.getDepartment("English").addProfessor(&a[1]);
    std::cout << ui << "\n";
    return 0;
}