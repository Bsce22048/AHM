//
// Created by Admin on 30/03/2023.
//

#ifndef PHARMACY_SELLING_H
#define PHARMACY_SELLING_H

#include "UserInfo.h"
#include <fstream>
#include "Pharmacy.h"
#include "Finance.h"

class Selling
{
public:
    UserInfo user;
    string n2;
    int q2;
    ofstream writing;
    Pharmacy *ph;
    Invoice aze;

    Selling()
    {
        writing.open("UsersData.txt");
    }

    void getInfo();
    void returnMed();
    void buyMed();

    ~Selling()
    {
        writing.close();
    }

};
#endif //PHARMACY_SELLING_H
