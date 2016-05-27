#include "chocoCandy.h"

chocoCandy::chocoCandy()
{
    for(int i=0;i<3;i++)
        ing[i]=0;
}

void chocoCandy::getData()
{
    chocolate::getData();
    int temp;
    for(int i=0;i<3;i++)
    {
        cin>>temp;
        ing[i]=temp;
    }
}

void chocoCandy::incN(int k)
{
    number+=k;
}

