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
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>


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
  bool walkable;
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
} Entity; 

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
void setup(void);
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
void printInventory(void);

// time.c functions
void printTime(void);

// message.c functions
void printMassage(char *str);
void callMassageBox(char str);
void inputMessage(void);
void quizMessage(char *str);

// ineraction.c functions
void callInteraction(void);

// random.c functions
Randam_Level *creatRandom(void);

//quiz.c
Quiz* createQuiz(void);
int CheckNPC(void);
void CallQuiz(void);
void CheckAnswer(void);

// util.c functions
char *ft_itoa(int n);
long int ft_abs(long int nbr);

// externs
extern Entity* player; //전역변수 공유 -> 다른 소스파일에 정의가 되어 있으니 찾아가서 사용할 것 이라는 뜻
extern Tile** map;
extern Inventory* inven; //인벤토리 객체
extern Quiz* quiz;
extern int curLocationFlag;
extern Position roomPos[10];
extern char answer[3];
extern Randam_Level *randam_Level;

#endif