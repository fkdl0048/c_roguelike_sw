#include <rogue.h>

void callInteraction(void){
    Position degPos[4] = {{-1,0},{0,-1},{0,1},{1,0}};

    Position pos = player->pos;
    char interch;

    for (int i = 0; i < 4; i++){
        interch = map[pos.y+degPos[i].y][pos.x+degPos[i].x].ch;
        callMassageBox(interch);
        callMoveMap(interch);
        if(interch == 'K')
            inven->key++;
        if(interch == '/'){
            inven->key++;
            map[pos.y+degPos[i].y][pos.x+degPos[i].x].ch=' ';
            map[pos.y+degPos[i].y][pos.x+degPos[i].x].walkable = TRUE;
        }
        // 메세지 박스 상호작용 부분 추가
    }
}

