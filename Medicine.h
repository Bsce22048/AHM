//
// Created by Admin on 3/23/2023.
//

#ifndef OOP_SEMESTER2_MEDICINE_H
#define OOP_SEMESTER2_MEDICINE_H

#include <iostream>

using namespace std;

class Medicine {
public:
    string name;


    Medicine();

    ~Medicine();

    Medicine(string);

    friend ostream &operator<<(ostream &os, const Medicine &med);

    friend istream &operator>>(istream &is, Medicine &med);
};


#endif //OOP_SEMESTER2_MEDICINE_H
