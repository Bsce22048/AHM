//
// Created by Admin on 3/23/2023.
//

#include "Cabinet.h"

Cabinet::Cabinet() {}

Cabinet::Cabinet(string n, long int ca) {
    name = n;
    capacity = ca;
    totalQuantity=0;
}

int Cabinet::searchMedicine(string n, int &i, double p, double s) {
    if (prizes.size() == 0)
        return 1;
    else {
        for (i = 0; i < prizes.size(); ++i) {
            if (prizes[i]->medicine->name == n) {
                if (prizes[i]->purchasePrize == p) {
                    if (prizes[i]->salePrize == s) {
                        return 3;
                    } else return 2;     //to aggregate previous medi name
                } else return 2;
            } else return 1;       //for entering new
        }
    }
    //for entering new

    return 0;
}


void Cabinet::addMedicine(int a, string name, int quantity, double pp, double sp, int ind) {
    if (a == 2) {
        Prize *p = new Prize(pp, sp, quantity);
        prizes.push_back(p);
        int x = prizes.size() - 1;
        prizes[x]->medicine = medicines[ind];

    } else if (a == 1) {
        Medicine *m = new Medicine(name);
        Prize *p = new Prize(pp, sp, quantity);
        prizes.push_back(p);
        medicines.push_back(m);
        int x = prizes.size() - 1;
        int y = medicines.size() - 1;
        prizes[x]->medicine = medicines[y];
    }
}

void Cabinet::displaying() {
    for (int i = 0; i < prizes.size(); ++i) {
        cout << *(prizes[i]);
    }
}

void Cabinet::testing() {
    cout << "\nenter name :";
    string name;
    cin >> name;
    cout << "enter quantity :";
    int quantity;
    cin >> quantity;
    totalQuantity += quantity;
    if (capacity >= totalQuantity) {
        cout << "enter purchase prize :";
        double pp, sp;
        cin >> pp;
        cout << "enter sales prize :";
        cin >> sp;
        int ind = 0;
        int x = searchMedicine(name, ind, pp, sp);
        if (x == 3) {
            changeQuantity(ind, quantity);
        } else {
            addMedicine(x, name, quantity, pp, sp, ind);
        }
    }else
        cout<<"\nyou cannot enter quantity greater than capacity\n"
                "remaining capacity is : "<<capacity-(totalQuantity-=quantity);
}

void Cabinet::changeQuantity(int index, int q) {
    prizes[index]->quantity += q;
}

void Cabinet::operations() {
    cout << "enter 1 for adding medicine"
            "\n2 for displaying all";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {
            if (capacity > totalQuantity)
                testing();
            else
                cout << "\nnot enough quantity : ";
            break;
        }
        case 2:
            displaying();
            break;
    }
}