//
// Created by Admin on 3/23/2023.
//

#ifndef OOP_SEMESTER2_CABINET_H
#define OOP_SEMESTER2_CABINET_H

#include <vector>
#include "Medicine.h"
#include "Prize.h"

class Cabinet {
public:
    vector<Medicine *> medicines;
    vector<Prize *> prizes;

    string name;

    long int capacity;
    long int totalQuantity;

    Cabinet(string, long int);

    Cabinet();

    void testing();

    void addMedicine(int, string, int, double, double, int);

    int searchMedicine(string, int &, double = 0, double = 0);

    void changeQuantity(int, int);

    void displaying();

    void operations();
};


#endif //OOP_SEMESTER2_CABINET_H
