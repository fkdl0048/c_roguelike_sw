#include <rogue.h>

Entity* player; //전역 포인터 변수 선언(및 정의 헤더파일에 존재하는 extern정의) -> player.c에서 동적할당하여 사용
Tile** map;
Inventory *inven;
int curLocationFlag = 0;

int MAP_HEIGHT = 23;
int MAP_WIDTH = 90; 
// map pos
int firstFloorX = 4;
int firstFloorY = 3;
int secondFloorX = 2;
int secondFloorY = 1; 
//Position firstFloorPos1,2};//수정

// map size
int firstFloorWidth = 88;
int firstFloorHeight = 15;
int secondFloorWidth = 40;
int secondFloorHeight = 10;

// Frame pos
int curPosFrameX = 94;
int curPosFrameY = 0;
int timerFrameX = 94;
int timerFrameY = 5;
int invenFrameX = 94;
int invenFrameY = 10; 
int massageBoxFrameX = 0;
int massageBoxFrameY = 25;

// Frame size
int curPosFrameWidth = 24;
int curPosFrameHeight = 3;
int timerFrameWidth = 24;
int timerFrameHeight = 3;
int invenFrameWidth = 24;
int invenFrameHeight = 13;
int massageBoxWidth = 90;
int massageBoxHeight = 3;

//int time;

int main(void)
{

  Position start_pos;

  cursesSetup();

  map = createMapTiles(); 
  start_pos = setupMap();
  player = createPlayer(start_pos);
  inven = createInventory();

  gameLoop();
  
  closeGame();

  return 0;
}
