#include <rogue.h>

void upFloor(void){
    curLocationFlag++;
    player->pos = setupMap();
}

void downFloor(void){
    curLocationFlag--;
    player->pos = setupMap();
}

void callInteraction(void){
    //upFloor();
    Tile temp;
    
}

