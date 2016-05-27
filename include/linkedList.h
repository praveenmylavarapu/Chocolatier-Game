#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<string.h>
using namespace std;

template<class dataType>
struct node
{
    dataType data;
    int numberOfChocolates;
    node* link;
};

template<class dataType>
class linkedList
{
    node<dataType>* head;
    node<dataType>* tail;

public:

    linkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void addnew(dataType item)
    {
        node<dataType>* temp = new node<dataType>;

        temp->data = item;
        temp->link = NULL;
        temp->numberOfChocolates=0;

        if (head == NULL)
            head = temp;
        else
            tail->link = temp;
        tail=temp;
    }

    void displayFullList()
    {
        node<dataType>* ptr = head;

        while(ptr!=NULL)
        {
            cout<<ptr->data<<endl;
            ptr = ptr->link;
        }
    }

    void taDa(int g, int num, int kkk=1)
    {
        node<dataType>* ptr = head;
        for(int i=0;i<g;i++)
            ptr = ptr->link;

        if(!kkk)
            num*=-1;

        ptr->data.incN(num);
    }

    void ingReguired(int g,int *ir1,int *ir2,int *ir3)
    {
        node<dataType>* ptr = head;

        for(int i=0;i<g;i++)
            ptr = ptr->link;

        *ir1 =  ptr->data.ing[0];
        *ir2 =  ptr->data.ing[2];
        *ir3 =  ptr->data.ing[3];
    }
};


#endif // LINKEDLIST_H
