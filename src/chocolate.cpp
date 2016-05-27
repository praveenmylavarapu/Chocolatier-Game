#include "chocolate.h"
#include<string.h>

chocolate::chocolate()
{
    strcpy(name,"");
    number=0;
}

void chocolate::getData()
{
    char name[10];
    cin>>name;
    strcpy(this->name,name);
}

