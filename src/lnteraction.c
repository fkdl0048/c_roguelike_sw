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

void callInteraction(void){
    Position degPos[4] = {{-1,0},{0,-1},{0,1},{1,0}};
    Tile temp;
    Position pos = player->pos;
    char interch;

    for (int i = 0; i < 4; i++){
        interch = map[pos.y+degPos[i].y][pos.x+degPos[i].x].ch;
        if((interch == ']') || (interch == '[')){
            if(curLocationFlag == 0)
                upFloor();
            else if(curLocationFlag == 1)
                downFloor();
        }
        else if (interch == '-' || interch == '|'){
            if (curLocationFlag == 1)
                enterRoom();
            else if(curLocationFlag == 2)
                exitRoom();
        }
        // 메세지 박스 상호작용 부분 추가
    }
}

