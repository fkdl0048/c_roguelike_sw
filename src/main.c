#include <rogue.h>

const int MAP_HEIGHT = 25;
const int MAP_WIDTH = 100;

Entity* player; //전역 포인터 변수 선언(및 정의 헤더파일에 존재하는 extern정의) -> player.c에서 동적할당하여 사용
Tile** map;

int main(void)
{

  Position start_pos;

  cursesSetup();

  map = createMapTiles(); 
  start_pos = setupMap();
  player = createPlayer(start_pos);

  gameLoop();
  printf("%d\n", inven->cardkey);
  closeGame();

  return 0;
}
