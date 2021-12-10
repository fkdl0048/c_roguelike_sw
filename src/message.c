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

char quizMessage(int index){
    char ch;

    if(index == 0){
        mvaddstr(26,3,"b = 3 > 5 ? 3 : 4, b = ?");
        mvaddstr(27,3,"(1) 2 (2) 3 (3) 4 (4) 5");
    }
    else if(index == 1){
        mvaddstr(26,3,"0111 & 0100 = ?");
        mvaddstr(27,3,"(1) 0100 (2) 0101 (3) 0111 (4) 0110");
    }
    else if(index == 2){
        mvaddstr(26,3,"0110 | 1010 = ?");
        mvaddstr(27,3,"(1) 1101 (2) 1110 (3) 1100 (4) 1111");
    }
    else if(index == 3){
        mvaddstr(26,3,"0001 ^ 0011 = ?");
        mvaddstr(27,3,"(1) 1111 (2) 0111 (3) 0011 (4) 0010");
    }
    else if(index == 4){
        mvaddstr(26,3,"Where is the capital of Korea?");
        mvaddstr(27,3,"(1) Busan (2)Seoul (3) Incheon (4) Daegu");
    }
    else if(index == 5){
        mvaddstr(26,3,"What the last name is SW basic Design professor?");
        mvaddstr(27,3,"(1) Kim (2)Park (3) Choi (4) Lee");
    }
    else if(index == 6){
        mvaddstr(26,3,"a = 13 > 12 ? 11 : 14, a = ?");
        mvaddstr(27,3,"(1) 11 (2) 12 (3) 13 (4) 14");
    }
    else if(index == 7){
        mvaddstr(26,3,"10<11 ? (10<12 ? 12 : 13) : (13<14 ? 11 : 14)");
        mvaddstr(27,3,"(1) 11 (2) 12 (3) 13 (4) 14");
    }
    else if(index == 8){
        mvaddstr(26,3,"What is the name of our university?");
        mvaddstr(27,3,"(1) Sajong (2) Sojong (3) Sejong (4) Sujong");
    }
    else if(index == 9){
        mvaddstr(26,3,"(0001 | 0101) | ~0110 & 0111 = ?");
        mvaddstr(27,3,"(1) 0101 (2) 0111 (3) 0011 (4) 0110");
    }
    else{
        return 0;
    }
        
    ch = inputMessage();
    drawEverything();

    return ch;
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

char inputMessage(void){
    char ch;
    
    nocbreak();
    flushinp();
    echo();
    curs_set(1);
    mvaddstr(27,47,">>>");
    ch = mvgetch(27,50);
    cbreak();
    curs_set(0);
    noecho();

    return ch;
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