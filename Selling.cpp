//
// Created by Admin on 30/03/2023.
//

#include "Selling.h"
#include <fstream>
void Selling::getInfo()
{
    cout<<"Enter your first name:"<<endl;
    cin>>user.first_name;
    cout<<"Enter your last name:"<<endl;
    cin>>user.last_name;
    writing<<"Name: "<<user.first_name<<" "<<user.last_name<<endl;
    cout<<"Provide us your phone number:"<<endl;
    cin>>user.PhoneNo;
    writing<<"Phone number: "<<user.PhoneNo<<endl;
//    writing<<"User's unique ID is: "<<user.UserUniqueID<<endl;
}



void Selling::buyMed()
{
    int sz=1;
    int k=1,p=0;
    int q = 0, amo = 0;
   vector<string>medname;
    vector<int> qt;
    vector<double>medPr;
    vector <double>ttPr;


    while (k==1)
    {
        int q;string n; double pr,tpr;
        cout << "Enter the name of medicine you want to buy:" << endl;
        cin >> n;
        medname.push_back(n);
        cout << "Enter quantity you want of this medicine:" << endl;
        cin >> q;
        qt.push_back(q);

        for (int e = 0; e < ph->cabinets.size(); e++)
        {
            int g;
            g = ph->cabinets[e]->prizes.size();

            for (int ma = 0; ma < g; ma++)
            {
                if (n == ph->cabinets[e]->prizes[ma]->medicine->name)
                {
                    if(ph->cabinets[e]->prizes[ma]->quantity<q)
                    {
                        cout<<"Sorry we currently have "<<ph->cabinets[e]->prizes[ma]->quantity<<" quantity of this medicine:"<<endl;
                    }

                    else {
                        cout << "Medicine: " << ph->cabinets[e]->prizes[ma]->medicine->name << endl;
                        cout << "Price of 1 medicine is: " << ph->cabinets[e]->prizes[ma]->salePrize << endl;
                        cout << "Price of " << q << " medicines: " << ph->cabinets[e]->prizes[ma]->salePrize * q<< endl;

                        tpr=ph->cabinets[e]->prizes[ma]->salePrize*q;
                        ttPr.push_back(tpr);
                        pr=ph->cabinets[e]->prizes[ma]->salePrize;
                        medPr.push_back(pr);
                        ph->cabinets[e]->prizes[ma]->quantity = ph->cabinets[e]->prizes[ma]->quantity - q;
                        q++;

                        writing << "Medicine: " <<n << endl;
                        writing << "Quantity: " << q << endl;
                        writing << "Total price: " << ph->cabinets[e]->prizes[ma]->salePrize * q << endl;
                    }
                }
            }
        }


        if (q == 0)
        {
            cout << "Medicine is not available at this branch." << endl;
        }

        cout<<"Do you want to buy another medicine:"<<endl;
        cout<<"If yes, press 1 and if no then press any other number:"<<endl;
        cin>>k;
    }

    string gh;
    gh=user.first_name+user.last_name;
    aze.getInvoice(medname,medPr,qt,gh,ttPr);
}


void Selling::returnMed()
{
    int q = 0, qt;
    string medname;
    cout << "Enter the name of medicine you want to return:" << endl;
    cin >> medname;
    cout << "Enter quantity you want to return of this medicine:" << endl;
    cin >> qt;

    for (int e = 0; e < ph->cabinets.size(); e++) {
        int g;
        g = ph->cabinets[e]->prizes.size();

        for (int ma = 0; ma < g; ma++) {
            if (medname == ph->cabinets[e]->prizes[ma]->medicine->name) {
                cout << "Medicine: " << ph->cabinets[e]->prizes[ma]->medicine->name << endl;
                cout << "Price of 1 medicine is: " << ph->cabinets[e]->prizes[ma]->salePrize << endl;
                cout << "Here is your money back, price of " << qt << " medicines: "
                     << ph->cabinets[e]->prizes[ma]->salePrize * qt << endl;

                ph->cabinets[e]->prizes[ma]->quantity = ph->cabinets[e]->prizes[ma]->quantity + qt;
                q++;

            }
        }
    }

    if (q == 0)
    {
        cout << "Medicine is not available at this branch." << endl;
    }


}



