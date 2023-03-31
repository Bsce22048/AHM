//
// Created by Admin on 3/23/2023.
//

#ifndef OOP_SEMESTER2_PHARMACY_H
#define OOP_SEMESTER2_PHARMACY_H

#include "Cabinet.h"

class Pharmacy
{
public:
    vector<Cabinet *> cabinets;
public:
    void addNewCab();

    int searchCab(string);

    void modifyCabinet(int ind);

    void operations(int );
};


#endif //OOP_SEMESTER2_PHARMACY_H
