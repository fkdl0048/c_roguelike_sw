#include <rogue.h>

Entity* createPlayer(Position start_pos)
{
  Entity* newPlayer = calloc(1, sizeof(Entity)); //동적할당 부분

  newPlayer->pos.y = start_pos.y; //위치, 캐릭터 모양 초기화 부분
  newPlayer->pos.x = start_pos.x;
  newPlayer->ch = '@';

  return newPlayer; //해당 포인터 반환
}

void handleInput(int input) 
{
  switch(input)
  {
    //move up
    case 'w':
      player->pos.y--; // player변수 공유 rogue.h헤더파일
      break;
    //move down
    case 's':
      player->pos.y++;
      break;
    //move left
    case 'a':
      player->pos.x--;
      break;
    //move right
    case 'd':
      player->pos.x++;
      break;
    default:
      break;
  }
}