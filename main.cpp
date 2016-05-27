#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<iomanip>

#include"chocolate.h"
#include"chocoBar.h"
#include"chocoCandy.h"
#include"linkedList.h"
#include"playerStatus.h"

using namespace std;

ostream& operator << (ostream &cout, chocoCandy &c)
{
    cout<<"Name:"<<c.name<<"\t"<<c.ing[0]<<","<<c.ing[1]<<","<<c.ing[2]<<" - Quantity = "<<c.number<<endl;
    return cout;
}
ostream& operator << (ostream&s, chocoBar &c)
{
    s<<"Name:"<<c.name<<"\t"<<c.ing[0]<<","<<c.ing[1]<<","<<c.ing[2]<<","<<c.ing[3]<<","<<c.ing[4]<<" - Quantity = "<<c.number<<endl;
    return s;
}
istream& operator >> (istream &s, chocoCandy &c)
{
    cout<<"Enter name and ratio of three ingredients:"<<endl;
    s>>c.name>>c.ing[0]>>c.ing[1]>>c.ing[2];
    return s;
}
istream& operator >> (istream&s, chocoBar &c)
{
    cout<<"Enter name and ratio of five ingredients:"<<endl;
    s>>c.name>>c.ing[0]>>c.ing[1]>>c.ing[2]>>c.ing[3]>>c.ing[4];
    return s;
}

// Can be made as member function also
void createBarReciepe(playerStatus *P)
{
    chocoBar C;
    cin>>C;
    P->CB.addnew(C);

}

void createCandyRecipe(playerStatus *P)
{
    chocoCandy C;
    cin>>C;
    P->CC.addnew(C);
}


int main()
{
    char usrname[50],tks;
    int opt,k,money,ingk[5];
    int ingPrices[5]={5,7,16,23,9};
    ofstream outfilek;

l1:
    system("cls");
    cout<<endl<<setw(75)<<"Chocolatier - The Game"<<endl<<endl;
    cout<<setw(30)<<"Enter username: ";
    cin>>usrname;

    if(strcmp(usrname,"Admin")==0)
    {
        while(1)
        {
            system("cls");
            cout<<"\n1. Create new user\n2. Change ingredient prices\n3. Back\n =";
            cin>>opt;


            switch(opt)
            {
            case 1:
                    cout<<"Enter new user name: ";
                    cin>>usrname;
                    outfilek.open(usrname);
                    cout<<"Enter starting money and stock of 5 ingredients:"<<endl;
                    cin>>money;
                    for(int i=0;i<5;i++)
                        cin>>ingk[i];
                    outfilek.write((char*)(&money),sizeof(money));
                    for(int i=0;i<5;i++)
                        outfilek.write((char*)&ingk[i],sizeof(ingk[i]));
                    outfilek.close();
                    break;
            case 2:
                cout<<"Enter ingredient to set: ";
                cin>>k;
                cout<<"Enter new price: ";
                cin>>ingPrices[k-1];
                break;

            case 3:
                goto l1;
            default:
                cout<<"Invalid input";
                break;
            }

        }

    }

    else
    {
        playerStatus P;
        P.loadGame(usrname);
        while(1)
        {
            system("cls");
            cout<<"\n1. Manufacture chocolates\n2. Create a recipe\n3. Buy ingredients\n4. Sell chocolates\n5. My Status\n6. Save and Exit\n=";
            cin>>opt;
            switch(opt)
            {
            case  1:
                    cout<<"1. ChocoBar\n2. ChocoCandy\n =";
                    cin>>tks;
                    switch(tks)
                    {
                    case '1':
                        P.manufactureChocoBar();
                        break;
                    case '2':
                        P.manufactureChocoCandy();
                    }
                   break;
            case 2:
                    cout<<"1. ChocoBar\n2. ChocoCandy\n =";
                    cin>>tks;
                    switch(tks)
                    {
                    case '1':
                        createBarReciepe(&P);
                        break;
                    case '2':
                        createCandyRecipe(&P);
                    }

                    break;

            case 3:
                        P.buyIng(ingPrices);
                        break;

            case 4:
                    cout<<"1. ChocoBar\n2. ChocoCandy\n =";
                    cin>>tks;
                    switch(tks)
                    {
                    case '1':
                        P.sellChocoBar(100);
                        break;
                    case '2':
                        P.sellChocoCandy(50);
                    }
                   break;

                break;

            case 5:
                    system("cls");
                    cout<<setw(30)<<endl<<"Welcome, "<<usrname<<endl<<endl;
                    P.displayStatus();
                    cout<<"\nPress any key to go back to main menu: ";
                    cin>>tks;
                    break;

            case  6:
                P.saveGame(usrname);
                return 0;

            default:
                cout<<"Invalid input";
                break;
            }

        }

    }
}
