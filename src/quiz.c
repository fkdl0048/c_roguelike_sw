#include <rogue.h>

Quiz* createQuiz(void){
    Quiz* tmp = (Quiz*)malloc(sizeof(Quiz) * 10);
    
    tmp[0].result = '3';
    tmp[1].result = '1';
    tmp[2].result = '2';
    tmp[3].result = '4';
    tmp[4].result = '2';
    tmp[5].result = '3';
    tmp[6].result = '1';
    tmp[7].result = '2';
    tmp[8].result = '3';
    tmp[9].result = '1';

    return tmp;
}

void checkAnswer(char answer, int index){
    if(answer == quiz[index].result){
        printMassage("That's right, here's the rusty key.");
        inven->key++;
    }
    else{
        printMassage("Wrong Answer, Study some more.");
        level_time -= 60;
        map[roomY + 1][roomX + roomWidth / 2].ch = ' ';
        map[roomY + 1][roomX + roomWidth / 2].walkable = TRUE;
        damageflag++;
        drawEverything();
    }
    randam_Level[curLocationFlag-2].quiz = 0;
}

void callQuiz(void){
    int index;
    char answer;
    index = rand()%10;
    
    drawEverything();
    printMassage("Quiz!!");
    printMassage("If you answer correctly, I will give you the rusty key.");
    massageBoxFrameY = 24;
    massageBoxHeight = 4;
    drawEverything();
    answer = quizMessage(index);
    massageBoxFrameY = 25;
    massageBoxHeight = 3;
    drawEverything();
    checkAnswer(answer, index);
    halfdelay(5);
}