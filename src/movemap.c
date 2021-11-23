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

    for(int i = 0;i < 10; i++){
        if (player->pos.x == roomPos[i].x && player->pos.y == roomPos[i].y)
        {
            if(randam_Level[i].lock_room == 1){
                if(inven->key > 0){
                    printMassage("You used the key.");
                    randam_Level[i].lock_room = 0;
                    inven->key--;
                }
                else{
                    printMassage("This room is locked.");
                    return;
                }
            }
            curLocationFlag = i + 2;
            break;
        }
    }
    player->pos = setupMap();
}

void exitRoom(void){
    player->pos = roomPos[curLocationFlag - 2];
    curLocationFlag = 1;
    setupMap();
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
        else if(curLocationFlag >= 2)
            exitRoom();
    }
}