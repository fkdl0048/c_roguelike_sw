#include <rogue.h> 

void printTime(void){
    cur_time = time(NULL);

    char timer[10] = "";
    int end_time = level_time - (long long int)(cur_time - start_time);
    int min = end_time / 60;
    int sec = end_time % 60;
    strcat(timer,ft_itoa(min));
    strcat(timer," : ");
    strcat(timer,ft_itoa(sec));
    
    mvaddstr(timerFrameY+2,timerFrameX+3,timer);
} 

// 시간 확인은 end_time 사용