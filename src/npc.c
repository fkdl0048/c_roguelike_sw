#include <rogue.h>

NpcEntity* createNpc(Position npc_pos, int dir)
{
  NpcEntity* newNpc = calloc(1, sizeof(NpcEntity)); //동적할당 부분

  newNpc->pos.y = npc_pos.y; //위치, 캐릭터 모양 초기화 부분
  newNpc->pos.x = npc_pos.x;
  newNpc->ch = 'X';
  newNpc->color = COLOR_PAIR(NPC_COLOR);
  newNpc->visible = FALSE;
  newNpc->seen = FALSE;
  newNpc->direction = dir;

  return newNpc; //해당 포인터 반환
}


void npc_move(NpcEntity *npc_){
    if(npc_->direction == 0){
        npc_->pos.y++;
        if(npc_->pos.y==secondFloorHeight - 2) npc_->direction = 1;

    }
    else if(npc_->direction == 1){
        npc_->pos.x++;
        if(npc_->pos.x==secondFloorWidth - 3) npc_->direction = 2;
    }
    else if(npc_->direction == 2){
        npc_->pos.y--;
        if(npc_->pos.y==secondFloorY + 1) npc_->direction = 3;
    }
    else if(npc_->direction == 3){
        npc_->pos.x--;
        if(npc_->pos.x==secondFloorX + 3) npc_->direction = 0;
    }
}

int npc_collision(NpcEntity *npc_){
    if (npc_->pos.x == player->pos.x && npc_->pos.y == player->pos.y)
        return 1;
    if(npc_->direction == 0){
        for(int y = npc_->pos.y + 1, x = npc_->pos.x - 1; x <= npc_->pos.x + 1; x++)
            if (y == player->pos.y && x == player->pos.x)
                return 1;
        for(int y = npc_->pos.y + 2;y <= npc_->pos.y + 4; y++){
            for(int x = npc_->pos.x - 2; x <= npc_->pos.x + 3; x++){
                if (y == player->pos.y && x == player->pos.x)
                    return 1;
            }
        }
    }
    else if(npc_->direction == 1){
        for(int y = npc_->pos.y , x = npc_->pos.x + 1; x <= npc_->pos.x + 2; x++)
            if (y == player->pos.y && x == player->pos.x)
                return 1;
        for(int y = npc_->pos.y - 1;y <= npc_->pos.y + 1; y++){
            for(int x = npc_->pos.x + 3; x <= npc_->pos.x + 8; x++){
                if (y == player->pos.y && x == player->pos.x)
                    return 1;
            }
        }
    }
    else if(npc_->direction == 2){
        for(int y = npc_->pos.y - 1, x = npc_->pos.x - 1; x <= npc_->pos.x + 1; x++)
            if (y == player->pos.y && x == player->pos.x)
                return 1;
        for(int y = npc_->pos.y - 2;y >= npc_->pos.y - 4; y--){
            for(int x = npc_->pos.x - 3; x <= npc_->pos.x + 2; x++){
                if (y == player->pos.y && x == player->pos.x)
                    return 1;
            }
        }
    }
    else if(npc_->direction == 3){
        for(int y = npc_->pos.y , x = npc_->pos.x - 1; x >= npc_->pos.x - 2; x--)
            if (y == player->pos.y && x == player->pos.x)
                return 1;
        for(int y = npc_->pos.y - 1;y <= npc_->pos.y + 1; y++){
            for(int x = npc_->pos.x - 3; x >= npc_->pos.x - 8; x--){
                if (y == player->pos.y && x == player->pos.x)
                    return 1;
            }
        }
    }
    return 0;
}

int check_map(int x, int y){
    if (x >= secondFloorX && x < secondFloorWidth && y >= secondFloorY && y < secondFloorHeight)
        return 1;
    return 0;
}

void drawNpcPov(NpcEntity *npc_){
    if(npc_->direction == 0){
        for(int y = npc_->pos.y + 1, x = npc_->pos.x - 1; x <= npc_->pos.x + 1; x++)
            mvaddch(y, x, '.' | COLOR_PAIR(NPC_COLOR));
        for(int y = npc_->pos.y + 2;y <= npc_->pos.y + 4; y++){
            for(int x = npc_->pos.x - 2; x <= npc_->pos.x + 3; x++){
                if (check_map(x, y))
                    mvaddch(y, x, '.' | COLOR_PAIR(NPC_COLOR));
            }
        }
    }
    else if(npc_->direction == 1){
        for(int y = npc_->pos.y , x = npc_->pos.x + 1; x <= npc_->pos.x + 2; x++)
            if (check_map(x, y))
                mvaddch(y, x, '.' | COLOR_PAIR(NPC_COLOR));
        for(int y = npc_->pos.y - 1;y <= npc_->pos.y + 1; y++){
            for(int x = npc_->pos.x + 3; x <= npc_->pos.x + 8; x++){
                if (check_map(x, y))
                    mvaddch(y, x, '.' | COLOR_PAIR(NPC_COLOR));
            }
        }
    }
    else if(npc_->direction == 2){
        for(int y = npc_->pos.y - 1, x = npc_->pos.x - 1; x <= npc_->pos.x + 1; x++)
            mvaddch(y, x, '.' | COLOR_PAIR(NPC_COLOR));
        for(int y = npc_->pos.y - 2;y >= npc_->pos.y - 4; y--){
            for(int x = npc_->pos.x - 3; x <= npc_->pos.x + 2; x++){
                if (check_map(x, y))
                    mvaddch(y, x, '.' | COLOR_PAIR(NPC_COLOR));
            }
        }
    }
    else if(npc_->direction == 3){
        for(int y = npc_->pos.y , x = npc_->pos.x - 1; x >= npc_->pos.x - 2; x--)
            if (check_map(x, y))
                mvaddch(y, x, '.' | COLOR_PAIR(NPC_COLOR));
        for(int y = npc_->pos.y - 1;y <= npc_->pos.y + 1; y++){
            for(int x = npc_->pos.x - 3; x >= npc_->pos.x - 8; x--){
                if (check_map(x, y))
                    mvaddch(y, x, '.' | COLOR_PAIR(NPC_COLOR));
            }
        }
    }
}