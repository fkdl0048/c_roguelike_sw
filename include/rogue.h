#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h> // window.h랑 비슷한 헤더파일
#include <stdlib.h> // 동적할당을 위해

typedef struct //구조체 선언
{
  int y;
  int x;
} Position;

typedef struct 
{
  Position pos;
  char ch;
} Entity;

// player.c functions
Entity* createPlayer(Position start_pos); 
void handleInput(int input);

// externs
extern Entity* player; //전역변수 공유 -> 다른 소스파일에 정의가 되어 있으니 찾아가서 사용할 것 이라는 뜻

#endif
