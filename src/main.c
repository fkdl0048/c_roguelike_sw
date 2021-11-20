#include <rogue.h>

int MAP_HEIGHT = 23;
int MAP_WIDTH = 90; 
// map pos
int firstFloorX = 4;
int firstFloorY = 3;
int secondFloorX = 4;
int secondFloorY = 3;
int roomX = 40;
int roomY = 12; 
//Position firstFloorPos1,2};//수정

// map size
int firstFloorWidth = 88;
int firstFloorHeight = 15;
int firstFloorRoomSize = 4;
int stairSize = 3;
int secondFloorWidth = 88;
int secondFloorHeight = 15;
int secondFloorCenterSize = 3;
int roomWidth = 20;
int roomHeight = 10;

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

// 중요 변수들
Entity* player; //전역 포인터 변수 선언(및 정의 헤더파일에 존재하는 extern정의) -> player.c에서 동적할당하여 사용
Tile** map;
Inventory *inven;
int curLocationFlag = 0;
time_t start_time;
time_t cur_time;
int level_time = 600; // 10분

Position roomPos[10];

int main(void)
{
  Position start_pos;

  start_time = time(NULL);

  setup();

  map = createMapTiles(); 
  start_pos = setupMap();
  player = createPlayer(start_pos);
  inven = createInventory();

  gameLoop();
  
  closeGame();

  return 0;
}
