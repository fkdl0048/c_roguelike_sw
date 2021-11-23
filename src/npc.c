#include <rogue.h>

/*
Position npc_pos
npc 시작 위치 (5,6) => 계단 이동 후 아래
]]]@
   X
*/

/*
↓→↑←순으로 이동
directon(이동 방향)
0:↓
1:→
2:↑
3:←
*/

Entity* createNpc(Position npc_pos)
{
  Entity* newNpc = calloc(1, sizeof(Entity)); //동적할당 부분

  newNpc->pos.y = npc_pos.y; //위치, 캐릭터 모양 초기화 부분
  newNpc->pos.x = npc_pos.x;
  newNpc->ch = 'X';

  return newNpc; //해당 포인터 반환
}

void npc_move(){
    if(direction == 0){
        npc->pos.y++;
        if(npc->pos.y==secondFloorHeight - 2) direction = 1;
    }
    else if(direction == 1){
        npc->pos.x++;
        if(npc->pos.x==secondFloorWidth - 3) direction = 2;
    }
    else if(direction == 2){
        npc->pos.y--;
        if(npc->pos.y==secondFloorY + 1) direction = 3;
    }
    else if(direction == 3){
        npc->pos.x--;
        if(npc->pos.x==secondFloorX + 3) direction = 0;
    }
}

int npc_collision(){
    if (npc->pos.x == player->pos.x && npc->pos.y == player->pos.y)
        return TRUE;
    else
        return FALSE;
}