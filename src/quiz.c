#include <rogue.h>

Quiz* createQuiz(void){
    Quiz* tmp = calloc(1,sizeof(Quiz));
    
    tmp->n1 = (rand()%99) + 1;
    tmp->n2 = (rand()%99) + 1;
    tmp->result= tmp->n1 + tmp->n2;

    return tmp;
}
int CheckNPC(void){
    if(map[roomY + 1][roomX + roomWidth / 2].ch == '$'){
        quiz = createQuiz();
        drawEverything();
        printMassage("Quiz!!");
        return TRUE;
    }
    else return FALSE;
}
void CallQuiz(void){
    int n1, n2;
    char s1[3];
    char s2[3];
    char s[8];
    
    itoa(quiz->n1,s1,10);
    itoa(quiz->n2,s2,10);
    strcpy(s,s1);
    strcat(s,"+");
    strcat(s,s2);
    strcat(s,"=");
    drawEverything();
    quizMessage(s);
    drawEverything();
    CheckAnswer();
}

void CheckAnswer(void){
    int ch;

    if(atoi(answer) == quiz->result){
        printMassage("Correct");
        map[roomY + 1][roomX + roomWidth / 2].ch = '/';
        map[roomY + 1][roomX + roomWidth / 2].walkable = FALSE;
    }
    else{
        printMassage("Wrong Answer");
        level_time-=10;
        map[roomY + 1][roomX + roomWidth / 2].ch = ' ';
        map[roomY + 1][roomX + roomWidth / 2].walkable = TRUE;
    }
    randam_Level[curLocationFlag-2].quiz = 0;
    noecho();

    free(quiz);
}