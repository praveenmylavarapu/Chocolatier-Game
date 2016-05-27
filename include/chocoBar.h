#ifndef CHOCOBAR_H
#define CHOCOBAR_H

#include <iostream>

#include <chocolate.h>
#include"linkedList.h"


class chocoBar : private chocolate
{
    public:
        chocoBar();

        void getData();
        void incN(int);

        friend ostream& operator << (ostream&,chocoBar&);
        friend istream& operator >> (istream&,chocoBar&);

        friend void linkedList<chocoBar>::ingReguired(int,int*,int*,int*);

    private:
        int ing[5];
};

#endif // CHOCOBAR_H
