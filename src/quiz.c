#include <rogue.h>

Quiz* createQuiz(void){
    Quiz* tmp = calloc(1,sizeof(Quiz));
    
    tmp->n1 = (rand()%99) + 1;
    tmp->n2 = (rand()%99) + 1;
    tmp->result= tmp->n1 + tmp->n2;

    return tmp;
}

void checkAnswer(void){
    int ch;

    if(ft_atoi(answer) == quiz->result){
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

    free(quiz);
}

char* makeQuiz(void){
    char *s;
    
    strcpy(s,ft_itoa(quiz->n1));
    strcat(s,"+");
    strcat(s,ft_itoa(quiz->n2));
    strcat(s,"=");

    return s;
}

void callQuiz(void){
    quiz = createQuiz();
    drawEverything();
    printMassage("Quiz!!");
    //printf("1");
    drawEverything();
    quizMessage(makeQuiz());
    drawEverything();
    checkAnswer();
}
