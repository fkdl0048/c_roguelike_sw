#include <rogue.h>

void upFloor(void){
    curLocationFlag++;
    setupMap();
}

void downFloor(void){
    curLocationFlag--;
    setupMap();
}

void enterRoom(void){
    curLocationFlag++;
    player->pos = setupMap();
}

void exitRoom(void){
    curLocationFlag--;
    player->pos = setupMap();
}

void callMoveMap(char check){
    if((check == ']') || (check == '[')){
        if(curLocationFlag == 0)
            upFloor();
        else if(curLocationFlag == 1)
            downFloor();
    }
    else if (check == '-' || check == '|'){
        if (curLocationFlag == 1)
            enterRoom();
        else if(curLocationFlag == 2)
            exitRoom();
    }
}