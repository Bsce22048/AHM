//
// Created by Admin on 3/23/2023.
//

#ifndef OOP_SEMESTER2_PRIZE_H
#define OOP_SEMESTER2_PRIZE_H

#include<iostream>
#include "Medicine.h"

using namespace std;

class Prize {
public:
    double purchasePrize;
    double salePrize;
    Medicine *medicine;
    int quantity;

    Prize();

    Prize(double, double,int);

    friend ostream &operator<<(ostream &os, const Prize &med);

    friend istream &operator>>(istream &is, Prize &med);

};


#endif //OOP_SEMESTER2_PRIZE_H
