
#include "Pharmacy.h"

void Pharmacy::addNewCab() {
    string name;
    cout << "\nenter name of cabinet  : ";
    cin >> name;
    long int capacity;
    cout << "\nenter capacity  : ";
    cin >> capacity;
    Cabinet *c = new Cabinet(name, capacity);
    cabinets.push_back(c);
}

int Pharmacy::searchCab(string na) {
    if (cabinets.size() == 0)
        return 0;
    else {
        for (int i = 0; i < cabinets.size(); ++i) {
            if (cabinets[i]->name == na) {
                return i;
            }
        }
        return -1;
    }
}

void Pharmacy::modifyCabinet(int ind) {
    cabinets[ind]->testing();
    cabinets[ind]->displaying();
}

void Pharmacy::operations(int x) {
    switch (x) {
        case 1:
            addNewCab();             //new cabinet
            break;
        case 2: {
            cout << "enter name of cabinet :";
            string name;
            cin >> name;
            int ind = searchCab(name);    //search cabinet
          if(ind>=0)
            cabinets[ind]->operations();
          else
              cout<<"this cabinet not found";
          break;
        }
    }
}