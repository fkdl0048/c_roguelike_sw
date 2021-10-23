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

  Position newPos = {player->pos.y, player->pos.x};

  switch(input)
  {
    //move up
    case 'w':
      newPos.y--;
      break;
    //move down
    case 's':
      newPos.y++;
      break;
    //move left
    case 'a':
      newPos.x--;
      break;
    //move right
    case 'd':
      newPos.x++;
      break;
    default:
      break;
  }

  movePlayer(newPos);
}

void movePlayer(Position newPos)
{
  if(map[newPos.y][newPos.x].walkable)
  {
    player->pos.y = newPos.y;
    player->pos.x = newPos.x;
  }
}