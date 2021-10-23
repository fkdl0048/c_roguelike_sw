#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h> // window.h랑 비슷한 헤더파일
#include <stdlib.h> // 동적할당을 위해

typedef struct //구조체 선언
{
  int y;
  int x;
} Position; //좌표

typedef struct
{
  char ch;
  bool walkable;
}Tile;

typedef struct 
{
  Position pos;
  char ch;
} Entity; //객체

//draw.c functions
void drawMap(void);
void drawEntity(Entity* entity);
void drawEverything(void);

// engine.c functions
void cursesSetup(void);
void gameLoop(void);
void closeGame(void);

// map.c functions
Tile** createMapTiles(void);
Position setupMap(void);
void freeMap(void);

// player.c functions
Entity* createPlayer(Position start_pos); 
void handleInput(int input);
void movePlayer(Position newPos);

// externs
extern const int MAP_HEIGHT;
extern const int MAP_WIDTH;
extern Entity* player; //전역변수 공유 -> 다른 소스파일에 정의가 되어 있으니 찾아가서 사용할 것 이라는 뜻
extern Tile** map;

#endif
