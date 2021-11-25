#ifndef ROGUE_H
#define ROGUE_H

#define TRUE 1
#define FALSE 0

#include <curses.h> // window.h랑 비슷한 헤더파일
#include <stdlib.h> // 동적할당을 위해
#include <time.h> //데이터 파일
#include <data.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include <math.h>

// color pairs 색 설정
#define VISIBLE_COLOR 1
#define SEEN_COLOR 2
#define NPC_COLOR 3
#define NPC_POV_COLOR 4

//좌표
typedef struct //구조체 선언
{
  int y;
  int x;
} Position; 

//타일
typedef struct
{
  char ch;
  int item; //숨겨진 아이템
  bool walkable;
  // 색설정 부분
  int color;
  bool transparent;
  bool visible;
  bool seen;
}Tile;

//인벤토리
typedef struct
{
  int key;
  int cardkey;
  int driver;
}Inventory;

typedef struct
{
  int lock_room;
  int key;
  int quiz;
  int driver;
  int box;
}Randam_Level;

//객체
typedef struct 
{
  Position pos;
  char ch;
  int color;
} Entity; 

//npc entity
typedef struct 
{
  Position pos;
  char ch;
  int color;
  bool transparent; // 벽 관통 여부
  bool visible; // 현재위치에서 보이는지
  bool seen; // 지나간 곳
  int direction;
} NpcEntity;

//퀴즈
typedef struct
{
  int n1;
  int n2;
  int result;
}Quiz;


//draw.c functions
void drawMap(void);
void drawEntity(Entity* entity);
void drawEverything(void);

// engine.c functions
bool setup(void);
void gameLoop(void);
void closeGame(void);
int kbhit(void);

// map.c functions
Tile** createMapTiles(void);
Position setupMap(void);
void freeMap(void);

// movemap.c functions
void callMoveMap(char check);

// player.c functions
Entity* createPlayer(Position start_pos); 
void handleInput(int input);
void movePlayer(Position newPos);

// inventory.c functions
Inventory* createInventory(void);
void callItem(Tile* check);

// time.c functions
void printTime();

// message.c functions
void printMassage(char *str);
void callMassageBox(char check);

// ineraction.c functions
void callInteraction(void);

// random.c functions
Randam_Level *creatRandom(void);
void callRandom(void);

// util.c functions
char *ft_itoa(int n);
long int ft_abs(long int nbr);
int	ft_atoi(const char *nptr);

// npc.c functions 
NpcEntity* createNpc(Position npc_pos, int dir);
void npc_move(NpcEntity *npc_);
int npc_collision(NpcEntity *npc_);
void drawNpcPov(NpcEntity *npc_);

//quiz.c
void callQuiz(void);
void inputMessage(void);
void quizMessage(char *str);

// fov.c functions
void makeFOV();
void clearFOV();
int getDistance(Position origin, Position target);
bool isInMap(int y, int x);
bool lineOfSight(Position origin, Position target);
int getSign(int a);


extern Entity* player; //전역변수 공유 -> 다른 소스파일에 정의가 되어 있으니 찾아가서 사용할 것 이라는 뜻
extern Tile** map;
extern Inventory* inven; //인벤토리 객체
extern Position roomPos[10];
extern Randam_Level *randam_Level;
//extern Entity* npc; //npc 생성 추가
extern Quiz* quiz;
extern Position pos_arr[12];
extern NpcEntity* npc; //npc 생성 추가 (변경)
extern NpcEntity* secondNpc;

extern int direction;
extern char answer[3];
extern int curLocationFlag;
extern int damageflag;

#endif