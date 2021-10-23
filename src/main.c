#include <rogue.h>

Entity* player; //전역 포인터 변수 선언(및 정의 헤더파일에 존재하는 extern정의) -> player.c에서 동적할당하여 사용

int main(void)
{
  int ch;
  Position start_pos = { 10, 20 }; //Postion구조체 변수 할당

  initscr(); //ncurses 시스템을 시작하고 터미널에서 다른 모든 함수를 호출가능하게 함
  noecho(); //아무 키나 누를 때 ncurses가 화면에 즉시 그려지는 것을 방지
  curs_set(0); //커서 깜박이 제거

  player = createPlayer(start_pos); //해당 포인터변수가 동적할당된 player를 가르킴
  mvaddch(player->pos.y, player->pos.x, player->ch); // 초기 화면이 검정색만 뜨는걸 방지하기 위해 찍어줌

  while(ch = getch()) //사용자로 부터 키 입력받으며 무한루프
  {
    if (ch == 'q') // 종료키 설정
      break;

    handleInput(ch);
    clear();
    mvaddch(player->pos.y, player->pos.x, player->ch); // y,x,표시할 문자 세가지를 인수로 받아 표시 *y먼저x가 뒤에온다*
  }

  endwin(); // ncurses 시스템종료

  return 0;
}
