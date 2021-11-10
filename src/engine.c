#include <rogue.h>

void cursesSetup(void)
{
    initscr(); //ncurses 시스템을 시작하고 터미널에서 다른 모든 함수를 호출가능하게 함
    noecho(); //아무 키나 누를 때 ncurses가 화면에 즉시 그려지는 것을 방지
    curs_set(0); //커서 깜박이 제거
}

void gameLoop(void)
{
    int ch;

    drawEverything();

    while(1) //사용자로 부터 키 입력받으며 무한루프
    {
        ch = getch();
        if (ch == 'q') // 종료키 설정
            break;
        handleInput(ch);
        drawEverything();
    }
}

void closeGame(void)
{
    endwin(); // ncurses 시스템종료
    free(player); // player 동적할당 해제
    freeMap(); //map 동적할당 해제
}