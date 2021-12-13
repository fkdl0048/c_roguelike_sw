#include <rogue.h>

int MAP_HEIGHT = 23;
int MAP_WIDTH = 90; 
// map pos
int firstFloorX = 4;
int firstFloorY = 3;
int secondFloorX = 4;
int secondFloorY = 3;
int roomX = 35;
int roomY = 9; 
//Position firstFloorPos1,2};//수정

// map size
int firstFloorWidth = 88;
int firstFloorHeight = 15;
int firstFloorRoomSize = 4;
int stairSize = 3;
int secondFloorWidth = 88;
int secondFloorHeight = 15;
int secondFloorCenterSize = 3;
int roomWidth = 22;
int roomHeight = 13;

// Frame pos
int curPosFrameX = 94;
int curPosFrameY = 0;
int timerFrameX = 94;
int timerFrameY = 5;
int invenFrameX = 94;
int invenFrameY = 10; 
int massageBoxFrameX = 0;
int massageBoxFrameY = 25;
int batteryFrameX = 94;
int batteryFrameY = 25;

// Frame size
int curPosFrameWidth = 23;
int curPosFrameHeight = 3;
int timerFrameWidth = 23;
int timerFrameHeight = 3;
int invenFrameWidth = 23;
int invenFrameHeight = 13;
int massageBoxWidth = 90;
int massageBoxHeight = 3;
int batteryFrameWidth = 23;
int batteryFrameHeight = 3;


// 중요 변수들
Entity* player; //전역 포인터 변수 선언(및 정의 헤더파일에 존재하는 extern정의) -> player.c에서 동적할당하여 사용
Tile** map;
Inventory *inven;
NpcEntity* npc;
NpcEntity* secondNpc;

int curLocationFlag = 0;
time_t start_time;
time_t cur_time;
Quiz *quiz;
int level_time;

Randam_Level *randam_Level;
int max_lock_room = 4;
int max_key = 5;
int max_quiz = 10;
int max_box = 1;
int max_driver = 1;
int max_battery = 7;

Position roomPos[10];
Position npcStartPos = {4, 6};
Position secondNpcStartPos = {13, 85};

int direction = 0;
int end_time;
int radius;
int batteryFlag = 0;

// test Postion array
Position pos_arr[6];

int damageflag = 0; 
int clearFlag = 0;

int main(void)
{
  Position start_pos;

  int compatibleTerminal = setup();
  
  if (compatibleTerminal){
    while (1)
    {
      curLocationFlag = 0;
      start_time = time(NULL);
      randam_Level = creatRandom();
      map = createMapTiles(); 
      start_pos = setupMap();
      player = createPlayer(start_pos);
      inven = createInventory();
      npc = createNpc(npcStartPos, 0);
      secondNpc = createNpc(secondNpcStartPos, 2);
      quiz = createQuiz();

      level_time = 600;
      radius = 15;
      batteryFlag = 0;
      // restart 부분 추가
      if(gameLoop())
        break;
    }
    closeGame();
  }
  else
    endwin();

  return 0;
}

// 2~11

//roompos -> randam_level 사용
