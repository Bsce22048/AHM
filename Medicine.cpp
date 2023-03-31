//
// Created by Admin on 3/23/2023.
//

#include "Medicine.h"

Medicine::Medicine() {}

Medicine::Medicine(string name) {
    this->name = name;
}
ostream& operator<<(ostream& os, const Medicine& med) {
    os<<"\nname is :" << med.name ;
    return os;
}

istream& operator>>(istream& is, Medicine& med) {
    cout << "Enter medicine name: ";
    is >> med.name;
    cout << "Enter quantity: ";
    return is;
}
Medicine::~Medicine() {
}