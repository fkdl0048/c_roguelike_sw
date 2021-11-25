#include <rogue.h>

void printMassage(char *str){
    mvaddstr(27,3,str); //상수 추가하기
    mvaddch(27,88,'<' | A_BLINK);
    while (1)
    {
        // if(damageflag == 1)
        //     attron(COLOR_PAIR(NPC_COLOR));
        // printTime();
        if(kbhit()){
            if(getch() == '\n'){
                break;
            }
        }
        // if(damageflag == 1){
        //     attroff(COLOR_PAIR(NPC_COLOR));
        //     damageflag--;
        // }
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
