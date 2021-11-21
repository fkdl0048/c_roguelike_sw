#include <rogue.h>

void printMassage(char *str){
    mvaddstr(27,3,str);
    mvaddch(27,88,'<' | A_BLINK);
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

void callMassageBox(char check){
    switch (check)
    {
    case '/':
        printMassage("get?");
        break;
    case '8':
        printMassage("YoungJoo ba bo ba bo");
        break;
    default:
        break;

    }

}
void quizMessage(char *str){//퀴즈 출력 중 시간 표시 안되는 것, inputMessage 자동으로 입력되는 것 수정필요
    mvaddstr(27,3,str);
    echo();
    curs_set(1);
    inputMessage();
}

void inputMessage(void){
    mvgetnstr(27,10,answer,3);
    mvaddch(27,88,'<' | A_BLINK);
    while (1)
    {
        curs_set(0);
        printTime();
        if(kbhit()){
            if(getch() == '\n'){
                break;
            }
        }
    }
}