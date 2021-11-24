#include <rogue.h>

bool setup(void) 
{
    initscr(); //ncurses 시스템을 시작하고 터미널에서 다른 모든 함수를 호출가능하게 함
    noecho(); //아무 키나 누를 때 ncurses가 화면에 즉시 그려지는 것을 방지
    curs_set(0); //커서 깜박이 제거
    halfdelay(5);
    scrollok(stdscr, TRUE);
    keypad(stdscr, TRUE);
    srand((unsigned)time(NULL));
    if (has_colors()) //color 예외처리
    {
        start_color();

        init_pair(VISIBLE_COLOR, COLOR_WHITE, COLOR_BLACK);
        init_pair(SEEN_COLOR, COLOR_BLUE, COLOR_BLACK);
        init_pair(NPC_COLOR, COLOR_RED, COLOR_BLACK);
        return TRUE;
    }
    else
    {
        mvprintw(20, 50, "Your system doesn't support color. Can't start game!");
        getch();
        return FALSE;
    }
}

void gameLoop(void)
{
    int ch;

    drawEverything();

    while(1) //사용자로 부터 키 입력받으며 무한루프
    {
        if (npc_collision()){
            printMassage("Caught by npc!");
            break;
        }
        if(kbhit()){
            ch = getch();
            if (ch == 'q') // 종료키 설정
                break;
            handleInput(ch);
        }
        drawEverything();
    }
}

void closeGame(void)
{
    endwin(); // ncurses 시스템종료
    free(player); // player 동적할당 해제
    freeMap(); //map 동적할당 해제
}

// 입력 무시 함수
int kbhit(void)
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}