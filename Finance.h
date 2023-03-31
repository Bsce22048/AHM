//
// Created by HP on 3/23/2023.
//

#ifndef OOP_SEMESTER2_FINANCE_H
#define OOP_SEMESTER2_FINANCE_H
#include <iostream>
#include <fstream>
#include <time.h>
#include "Prize.h"
#include <vector>
using namespace std;
class Balance
{
private:
    double current_money;
    static Balance * ptr;
    Balance()
    {
        cout<<"Private Constructor :)"<<endl;
    }
public:
    static Balance * getInstance()
    {
        if(!ptr)
        {
            ptr=new Balance ;
        }
        return ptr;
    }
    double total_budget;
    double investment;
    double sold;
    void getInput2()
    {
        cout<<"Please Enter All Money Details in PKR " << "Thank You :) " <<endl;
        cout<<"Please Enter Total Budget For Pharmacy : " ;
        cin>>total_budget;
        cout<<"Please Enter Investment Amount : " ;
        cin>>investment;
        cout<<"Please Enter Total Sold Amount : " ;
        cin>>sold;
    }
};

class Selling;
class Invoice;
class Finance
{
private:
    ofstream a;
    string search;
    string name;
    double quantity;
    double price;
    string type;
    int size;
    double total_budget;
    double investment;
    double current_budget;
    double sold;
    double profit;
    double loss;
    double bought_price_per_item;
    double sold_price_per_item;
    double per_item_profit;
    double overall_profit;
    double per_item_loss;
    Finance * az;
    friend class Invoice;
public:
    Finance()
    {
        a.open("Initial.txt",ios::app);
        total_budget=0;
        investment=0;
        current_budget=0;
        sold=0;
        profit=0;
        loss=0;
    }
    void getInput()
    {
        cout<<"Please Enter All Money Details in PKR " << "Thank You :) " <<endl;
        cout<<"Please Enter Total Budget For Pharmacy : " ;
        cin>>total_budget;
        cout<<"Please Enter Investment Amount : " ;
        cin>>investment;
        cout<<"Please Enter Total Sold Amount : " ;
        cin>>sold;
    }
    void displayData()
    {
        cout<<"Total Budget : " << total_budget << "pkr" <<endl;
        a<<"Total Budget : " << total_budget << "pkr" <<endl;
        cout<<"Investment : " << investment << "pkr" <<endl;
        a<<"Investment : " << investment << "pkr" <<endl;
        current_budget=total_budget-investment;
        cout<<"Now Current Budget  : " << current_budget << "pkr" <<endl;
        a<<"Now Current Budget  : " << current_budget << "pkr" <<endl;
        if(sold>investment)
        {
            cout<<"Profit : " << sold-investment << "pkr" <<endl;
            a<<"Profit : " << sold-investment << "pkr" <<endl;
        }
        if(sold<investment)
        {
            cout<<"Loss : " << investment-sold << "pkr" <<endl;
            a<<"Loss : " << investment-sold << "pkr" <<endl;
        }
        a.close();
    }
   /* void getProfitPer_Medicine_Item()
    {
        cout<<"Enter The Price At Which You Bought One item : " ;
        cin>>bought_price_per_item;
        cout<<"Enter The Price At Which You Sold One item : " ;
        cin>>sold_price_per_item;
    }
    void displayProfitPer_Medicine_Item()
    {
        per_item_profit=sold_price_per_item-bought_price_per_item;
        if(sold_price_per_item>bought_price_per_item) {
            cout << "At this Item We Had A Profit Of : " << per_item_profit << "pkr" << endl;
        }
        if(bought_price_per_item>sold_price_per_item)
        {
            cout<<"At this Item We Had A Loss Of : " << bought_price_per_item-sold_price_per_item << "pkr"<<endl;
        }
    } */
    void gettingData()
    {
        overall_profit=0;
        cout<<"Enter the Type To Calculate Profit i.e (Grocery,Medicine,Machinery) : ";
        cin>>type;
        cout<<"Enter the How many things you want to enter  : " ;
        cin>>size;
        az=new Finance [size];
        for(int i=0;i<size;i++)
        {
            cout<<"Enter the name of " << type << "\t "<< i+1 << " : " ;
            cin>>az[i].name;
            cout<<"Enter the quantity of " << type << "\t"<< i+1 << " : ";
            cin>>az[i].quantity;
            cout<<"Enter the price of " << type << "\t" <<i+1 << " : ";
            cin>>az[i].price;
           sold_price_per_item=az[i].quantity*az[i].price;
           bought_price_per_item=az[i].quantity*az[i].sold;
           per_item_profit=sold_price_per_item-bought_price_per_item;
           overall_profit+=per_item_profit;
        }
    }
    void represent()
    {
        double a=0;
        double b=0;
        gettingData();
        for(int i=0;i<size;i++)
        {
            cout<< "Name of " << type << "\t" << i+1 << "  : "    << az[i].name<<endl;
            cout<< "Quantity of " <<type << "\t" << i+1 << " : " <<az[i].quantity<<endl;
            cout<< "Price of " << type << "\t" << i+1 << " : "   <<az[i].price<<endl;
            cout<<" Profit " << type << "\t" <<i+1 << " : " <<  per_item_profit<<endl;
        }
        cout<<"Overall profit on these items are : " << overall_profit <<endl;
        cout<<"Enter the name of the thing to find profit : " ;
        cin>>search;
        for(int i=0;i<size;i++) {
            if (az[i].name == search) {
                cout << "Thing Found :)" << endl;
                cout << "Enter the price at which you bought : ";
                cin >> bought_price_per_item;
                cout << "Enter the price at which you sold one item :";
                cin >> sold_price_per_item;
                a = az[i].quantity * sold_price_per_item;
                b = az[i].quantity * bought_price_per_item;
                if (a > b) {
                    cout << "At this item we had a profit of : " << a - b << "pkr" << endl;
                }
                if (a < b) {
                    cout << "At this item we had a loss of : " << b - a << "pkr" << endl;
                }
            }
            else
                cout<<"Thing not Found :("<<endl;
        }
    }
};
class Invoice : public Finance
{
private:
    ofstream invoice;
    double account;
    double cash;
    double pay;
    string method;
    double total;
    int si;
//    Finance * a;


public:
    Invoice()
    {
        invoice.open("Invoice.txt",ios::app);
    }

    void getInvoice(vector <string> &a,vector<double> &price,vector<int> &quantity,string &name,vector <double> &total_price) {
        double d=0;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\tCompany Name : AHM " << endl;
     //   invoice << "------------------------------------------------------------------------------" << endl;
       // invoice << "\t\t\t\tCompany Name : AHM " << endl;
        for(int b=0;b<a.size();++b)
        {
        cout << "Name : " << a[b] << endl;
        cout << "Quantity : " << quantity[b] << endl;
        cout << "Price : " << price[b]<<endl;
        d+=total_price[b];
        //invoice << "\t\t\tYour total bill is : " << total_price << endl;
    }

        cout << "\t\t\tYour total bill is : " << d << endl;

        time_t ct=time(0);
        string current_time;
        current_time=ctime(&ct);
        cout<< "\t\t\t" <<current_time<<endl;
        invoice<< "\t\t\t" <<current_time<<endl;
        cout<<"--------------------------------------------------------------------------------" <<endl;
        cout<<"Which Payment Method You Would Like To Choose i.e(Card or Cash ) : ";
        cin>>method;
        if(method=="cash"||method=="Cash") {
            while(pay != total)
            {
                cout << "Please Pay " <<d  << "pkr ";
                cin >> pay;
                cout << "Please Entire Exact Amount : ";
            }
            if(pay==d)
            {
                cout << "We received an amount of " << d << "pkr" << endl;
                cout << "Thanks for Visiting our Pharmacy :):) " << endl;
                current_budget=total;
            }
        }
        if(method=="card"||method=="Card")
        {
            cout<< "You have to Pay : " << total << endl;
            cout<<"Please give me Your Credit Card " <<endl;
            account=total;
            current_budget=account;
            cout<<"Payment Received Thanks for Visiting our Pharmacy :):)"<<endl;
        }
    }
};
#endif //OOP_SEMESTER2_FINANCE_H
