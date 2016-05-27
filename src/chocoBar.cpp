#include "chocoBar.h"

chocoBar::chocoBar()
{
    for(int i=0;i<5;i++)
        ing[i]=0;
}

void chocoBar::getData()
{
    chocolate::getData();
    int temp;
    for(int i=0;i<5;i++)
    {
        cin>>temp;
        ing[i]=temp;
    }
}

void chocoBar::incN(int k)
{
    number+=k;
}
