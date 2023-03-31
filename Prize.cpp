
#include "Prize.h"

Prize::Prize() {}

Prize::Prize(double pp, double sp, int qt) {
    purchasePrize = pp;
    salePrize = sp;
    quantity = qt;
}

ostream &operator<<(ostream &os, const Prize &med) {
    os << "name is :" << med.medicine->name << "\nquantity is :" << med.quantity;
    os << "\npurchase prize :" << med.purchasePrize;
    os << "\nsales prize :" << med.salePrize;
    return os;
}

istream &operator>>(istream &is, Prize &med) {
    cout << "\nenter purchase prize :";
    is >> med.purchasePrize;
    cout << "\nenter sales prize :";
    is >> med.salePrize;
    return is;
}