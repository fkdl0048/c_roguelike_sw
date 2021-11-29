#include <rogue.h>

void printTitle(void){
    mvaddstr(4,32,"[I Want Go Home, PROFESSOR!]");
}

void drawStartScreen(void)
{
    clear();
    //box(stdscr, '.','.');
    drawFrame(); 
    printTitle();
    printStartMassage();
    while (1)
    {
        printTime();
        if(kbhit()){
            if(getch() == '\n'){
                break;
            }
        }
    }
}


void printGameOver(void){
    mvaddstr(8, 40,"[GAME OVER!]");
    mvaddch(8,40,'[' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,41,'G' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,42,'A' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,43,'M' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,44,'E' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,46,'O' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,47,'V' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,48,'E' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,49,'R' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,50,'!' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,51,']' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddstr(12, 32,"If you want to start again,");
    mvaddstr(14, 40,"Press Enter");
}

void drawGameOver(void){

    clear();
    //box(stdscr, '.','.');
    drawFrame(); 
    printGameOver();
    while (1)
    {
        if(kbhit()){
            if(getch() == '\n'){
                break;
            }
        }
    }
}
