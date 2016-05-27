#ifndef PLAYERSTATUS_H
#define PLAYERSTATUS_H

#include"chocolate.h"
#include"chocoBar.h"
#include"chocoCandy.h"
#include"linkedList.h"

using namespace std;

class playerStatus
{
    public:

        playerStatus();

        void displayStatus();
        void manufactureChocoCandy();
        void manufactureChocoBar();
        void sellChocoCandy(int);
        void sellChocoBar(int);
        void buyIng(int*);
        void saveGame(char*);
        void loadGame(char*);
        friend void createBarReciepe(playerStatus*);
        friend void createCandyRecipe(playerStatus*);

    private:

        int money;
        int ing[5];
        linkedList<chocoBar> CB;
        linkedList<chocoCandy> CC;
};

#endif // PLAYERSTATUS_H
