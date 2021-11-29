#include <rogue.h>

void printMassage(char *str){
    mvaddstr(27,3,str); //상수 추가하기
    mvaddch(27,88,'<' | A_BLINK);
    while (1)
    {
        if(kbhit()){
            if(getch() == '\n'){
                break;
            }
        }
    }
}

void quizMessage(char *str){//퀴즈 출력 중 시간 표시 안되는 것, inputMessage 자동으로 입력되는 것 수정필요
    mvaddstr(27,3,str);
    inputMessage();
}

void callMassageBox(char check){
    switch (check)
    {
    case '/':
        printMassage("get?");
        break;
    default:
        break;
    }
}

void inputMessage(void){
    char *scan[100];
    echo();
    curs_set(1);
    mvgetnstr(27,10,answer,3);
    //mvscanw(27,10,"%s",scan);
    mvaddch(27,88,'<' | A_BLINK);
    curs_set(0);
    noecho();
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

void printStartMassage(void){
    mvaddstr(4,10,"I was studying and it's late... Let's go out before the last train stops!"); //상수 추가하기
    mvaddstr(6, 29,"Use 'wasd' or 'arrow' for movement.");
    mvaddch(6,34,'W' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(6,35,'A' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(6,36,'S' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(6,37,'D' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(6,44,'A' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(6,45,'R' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(6,46,'R' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(6,47,'O' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(6,48,'W' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddstr(8, 37,"Interaction uses 'p'");
    mvaddch(8,55,'P' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddstr(10, 20,"Press 'Enter' when you start or turn over the message.");
    mvaddch(10,27,'E' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(10,28,'n' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(10,29,'t' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(10,30,'e' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(10,31,'r' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddstr(12, 34,"Game Exit 'Q', Restart 'R'");
    mvaddch(12,45,'Q' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(12,58,'R' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    while (1)
    {
        if(kbhit()){
            if(getch() == '\n'){
                break;
            }
        }
    }
}

void printEndMassage(void){
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
    while (1)
    {
        if(kbhit()){
            if(getch() == '\n'){
                break;
            }
        }
    }
}