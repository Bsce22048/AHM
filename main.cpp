#include "Pharmacy.h"
#include "Selling.h"
#include "Finance.h"
Balance *Balance::ptr= nullptr;
int main()
{
    Balance :: getInstance()->getInput2();
    Pharmacy p;
    Selling sl;
    sl.ph=&p;

    int n=0;
    while(n!=3)
    {
        cout<<"Enter 1 for admin, 2 for buying a product and press any key to end this program"<<endl;
        cin>>n;

        if(n==1) {
                cout << "enter 1 for perform operation on cabinet \n"
                        "2 for operation on medicine : ";
                int x;
                cin >> x;
                switch (x) {
                    case 1:
                        p.operations(x);
                        break;
                    case 2:
                        p.operations(x);
                        break;

            }
        }

        else if(n==2)
        {

            sl.getInfo();

            int m=0;
            while(m!=3)
            {
                cout<<"Enter 1 to buy a product, enter 2 to return a product and 3 to end a program:"<<endl;
                cin>>m;
                if(m==1)
                {
                    sl.buyMed();
                }
                else if(m==2)
                {
                    sl.returnMed();
                }
            }
        }

    }




    return 0;
}
