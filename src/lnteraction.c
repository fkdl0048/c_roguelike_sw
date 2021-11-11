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
    Position degPos[8] = {{-1, -1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    Tile temp;
    Position pos = player->pos;
    char interch;

    for (int i = 0; i < 8; i++){
        interch = map[pos.y+degPos[i].y][pos.x+degPos[i].x].ch;
        if((interch == ']') || (interch == '[')){
            if(curLocationFlag == 0)
                upFloor();
            else if(curLocationFlag == 1)
                downFloor();
        }
    }
}
