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
    mvaddstr(6,10,"I was studying and it's late... Let's go out before the last train stops!"); //상수 추가하기
    mvaddstr(8, 29,"Use 'wasd' or 'arrow' for movement.");
    mvaddch(8,34,'W' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,35,'A' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,36,'S' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,37,'D' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,44,'A' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,45,'R' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,46,'R' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,47,'O' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(8,48,'W' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddstr(10, 37,"Interaction uses 'p'");
    mvaddch(10,55,'P' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddstr(12, 20,"Press 'Enter' when you start or turn over the message.");
    mvaddch(12,27,'E' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(12,28,'n' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(12,29,'t' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(12,30,'e' | A_BOLD | COLOR_PAIR(NPC_COLOR));
    mvaddch(12,31,'r' | A_BOLD | COLOR_PAIR(NPC_COLOR));
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