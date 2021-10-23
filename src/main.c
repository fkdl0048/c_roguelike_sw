#include <rogue.h>

const int MAP_HEIGHT = 25;
const int MAP_WIDTH = 100;

Entity* player; //전역 포인터 변수 선언(및 정의 헤더파일에 존재하는 extern정의) -> player.c에서 동적할당하여 사용
Tile** map;

int main(void)
{
  cursesSetup();

  Position start_pos = { 10, 20 }; //Postion구조체 변수 할당 / 시작위치 초기화  
  player = createPlayer(start_pos); //해당 포인터변수가 동적할당된 player를 가르킴
  map = createMapTiles();
  gameLoop();

  closeGame();

  return 0;
}
