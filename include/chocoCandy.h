#ifndef CHOCOCANDY_H
#define CHOCOCANDY_H

#include <iostream>
#include <chocolate.h>
#include"linkedList.h"

class chocoCandy : private chocolate
{
    public:
        chocoCandy();

        void getData();
        void incN(int);

        friend ostream& operator << (ostream&,chocoCandy&);
        friend istream& operator >> (istream&,chocoCandy&);

        friend void linkedList<chocoCandy>::ingReguired(int,int*,int*,int*);

    private:
        int ing[3];     // Ingredients ratio

};

#endif // CHOCOCANDY_H
