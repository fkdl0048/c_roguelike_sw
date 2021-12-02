#include <rogue.h> 

void printTime(void){
    cur_time = time(NULL);
    int ori_time = end_time;

    char timer[10] = "";
    end_time = level_time - (long long int)(cur_time - start_time);

    if (end_time != ori_time)
    {
        if (batteryFlag == 3){
            updateBattery();
            batteryFlag = 0;
        }
        npc_move(npc);
        npc_move(secondNpc);
        batteryFlag++;
    }

    int min = end_time / 60;
    int sec = end_time % 60;
    strcat(timer,ft_itoa(min));
    strcat(timer," : ");
    strcat(timer,ft_itoa(sec));
    mvaddstr(timerFrameY+2,timerFrameX+3,timer);

    if(end_time == 0){
        // clear부분
    }
}
// draw 부분으로 이동

// 시간 확인은 end_time 사용
