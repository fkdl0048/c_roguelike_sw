#include <rogue.h>

void printMassage(char *str){
    mvaddstr(27,3,str);
    //attron(A_BLINK);
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
    //attron(A_NORMAL);
}

void callMassageBox(char check){
    switch (check)
    {
    case '/':
        printMassage("get?");
        break;
    case '8':
        printMassage("YoungJoo ba bo ba bo");
    default:
        break;
    }

}