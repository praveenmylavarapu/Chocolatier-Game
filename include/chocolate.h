#ifndef CHOCOLATE_H
#define CHOCOLATE_H

#include <iostream>

using namespace std;
class chocolate
{
    public:
        chocolate();
        void getData();
        virtual void incN(int) =0;

    protected:
            char name[10];
            int number;
};

#endif // CHOCOLATE_H
