#include<iostream>
#include<fstream>
#include<iomanip>

#include "playerStatus.h"

playerStatus::playerStatus()
{
    money = 5000;
    for(int i=0;i<5;i++)
        ing[i]=0;
}

void playerStatus::loadGame(char usrname[50])
{
        ifstream infile(usrname);
        infile.read((char*)(&money),sizeof(money) );
        for(int i=0;i<5;i++)
            infile.read((char*)(&ing[i]),sizeof(ing[i]) );
        infile.close();
}

void playerStatus::displayStatus()
{

    cout<<setw(20)<<"Money: "<<money<<endl<<endl;

    for(int i=0;i<5;i++)
    {
        cout<<setw(20)<<"Ingredient "<<i+1<<": "<<setw(20)<<ing[i]<<endl;
    }

    cout<<endl<<"ChocoBar recipies:"<<endl;
    CB.displayFullList();
    cout<<"ChocoCandy recipies:"<<endl;
    CC.displayFullList();
}

void playerStatus::manufactureChocoCandy()
{
    int opt,num;
    char o;
    CC.displayFullList();
    cout<<"Enter option to manufacture: ";
    cin>>opt;
    cout<<"Enter number of chocolates to manufacture: ";
    cin>>num;

    int ir1,ir2,ir3;
    CC.ingReguired(opt-1,&ir1,&ir2,&ir3);
    int ingReq[3]={ir1,ir2,ir3};
    for(int i=0;i<3;i++)
        ing[i]-=num*ingReq[i];

    CC.taDa(opt-1,num);

    cout<<"Successfully manufactured "<<num<<" chocolates."<<endl;
    cin>>o;
}

void playerStatus::manufactureChocoBar()
{
    //  Displaying list and get the number and manufacture that chocolate

    int opt,num;
    char o;
    CB.displayFullList();
    cout<<"Enter option to manufacture: ";
    cin>>opt;
    cout<<"Enter number of chocolates to manufacture: ";
    cin>>num;
    int ir1,ir2,ir3;
    CB.ingReguired(opt-1,&ir1,&ir2,&ir3);
    int ingReq[3]={ir1,ir2,ir3};
    for(int i=0;i<5;i++)
        ing[i]-=num*ingReq[i];  // Decreasing ingredients
    CB.taDa(opt-1,num);         // Increasing chocolates
    cout<<"Successfully manufactured "<<num<<" chocolates."<<endl;
    cin>>o;
}

void playerStatus::sellChocoCandy(int cost=50)
{
    int opt,num;
    char o;
    CC.displayFullList();
    cout<<"Enter option to sell: ";
    cin>>opt;
    cout<<"Enter number of chocolates to sell: ";
    cin>>num;
    CC.taDa(--opt,num,0);
    money+=cost*num;

    cout<<"Successfully  sold "<<num<<" chocolates."<<endl;
    cin>>o;
}

void playerStatus::sellChocoBar(int cost=100)
{
    int opt,num;
    char o;
    CB.displayFullList();
    cout<<"Enter option to sell: ";
    cin>>opt;
    cout<<"Enter number of chocolates to sell: ";
    cin>>num;
    CB.taDa(--opt,num,0);
    money+=cost*num;
    cout<<"Successfully  sold "<<num<<" chocolates."<<endl;
    cin>>o;
}

void playerStatus::buyIng(int ingPrices[5])
{
    int opt,num,i;
    char o;
    cout<<setw(20)<<"Ingredient"<<setw(20)<<"Price"<<endl<<endl;
    for (i=0;i<5;i++)
        cout<<setw(20)<<i+1<<setw(20)<<ingPrices[i]<<endl;

    cout<<"Select an option: ";
    cin>>opt;

    cout<<"Enter the number of ingredients to buy: ";
    cin>>num;

    if(money < num*ingPrices[opt-1])
    {
        cout<<"No enough money! ";
        cin>>o;
        return;
    }
    money-=ingPrices[opt-1]*num;
    ing[opt-1]+=num;
    cout<<"Press any key to go back to main menu: ";
    cin>>o;
}

void playerStatus::saveGame(char usrname[])
{
    ofstream outfile(usrname);
    outfile.write((char*)(&money),sizeof(money));
    for(int i=0;i<5;i++)
        outfile.write((char*)&ing[i],sizeof(ing[i]));
    outfile.close();
}
