#include <rogue.h>

void drawMap(void) // 맵 그림
{
    for(int y = 2; y < MAP_HEIGHT; y++)
    {
        for(int x = 2; x < MAP_WIDTH; x++)
        {
            mvaddch(y,x,map[y][x].ch);
        }
    }
}

void drawEntity(Entity* entity)
{
    mvaddch(entity->pos.y, entity->pos.x, entity->ch);// y,x,표시할 문자 세가지를 인수로 받아 표시 *y먼저x가 뒤에온다*
}

// void drawRect(int x,int y,int width, int height)
// {
//     int i,j;
//     for(i = 1; i <= height;i++){
//         for (j = 1; j <= width; j++){
//             if((i == 1 || i == height) && (j == 1 || j == width)){
//                 if(i == 1 && j == 1)
//                     mvaddch(y+i,x+j,ACS_ULCORNER);
//                 else if(i == height && j == 1)
//                     mvaddch(y+i,x+j,ACS_LLCORNER);
//                 else if(i == 1 && j == width)
//                     mvaddch(y+i,x+j,ACS_URCORNER);
//                 else if(i == height && j == width) 
//                     mvaddch(y+i,x+j,ACS_LRCORNER);
//             }
//             else if(i == 1 || i == height)
//                 mvaddch(y+i,x+j,ACS_HLINE);
//             else if(j == 1 || j == width)
//                 mvaddch(y+i,x+j,ACS_VLINE);
//         }
//     }
// }

void drawRect(int x,int y,int width, int height)
{
    int i,j;
    for(i = 1; i <= height;i++){
        for (j = 1; j <= width; j++){
            if((i == 1 || i == height) && (j == 1 || j == width)){
                mvaddch(y+i,x+j,'*');
            }
            else if(i == 1 || i == height)
                mvaddch(y+i,x+j,'-');
            else if(j == 1 || j == width)
                mvaddch(y+i,x+j,'|');
        }
    }
}

void drawFrame(void)
{
    drawRect(0,0,MAP_WIDTH,MAP_HEIGHT); // 메인 화면 프레임
    drawRect(curPosFrameX,curPosFrameY,curPosFrameWidth,curPosFrameHeight); // 현재위치 프레임
    drawRect(timerFrameX,timerFrameY,timerFrameWidth,timerFrameHeight); // 타이머 프레임
    drawRect(invenFrameX,invenFrameY,invenFrameWidth,invenFrameHeight); // 인벤토리 프레임
    drawRect(massageBoxFrameX,massageBoxFrameY,massageBoxWidth,massageBoxHeight); // 메세지 박스 프레임
}

void drawCurLocation(void){
    //mvaddstr(, , "first foor");
    if(curLocationFlag == 0){
        mvaddstr(curPosFrameY+2, curPosFrameX+3, "First Floor");
    }
    else if(curLocationFlag == 1){
        mvaddstr(curPosFrameY+2, curPosFrameX+3, "Second Floor");
    }
    else if(curLocationFlag == 2){
        mvaddstr(curPosFrameY+2, curPosFrameX+3, "Room");
    }
}


// 다시 짤것 time.c 작성
char buf1[10];
void drawTimer(void){
    char timer[10] = "";
    cur_time = time(NULL);
    int end_time = 600 - (long long int)(cur_time - start_time);
    int min;
    int sec;
    min = end_time / 60;
    sec = end_time % 60;
    strcat(timer,itoa(min,buf1,10));
    strcat(timer," : ");
    strcat(timer,itoa(sec,buf1,10));
    mvaddstr(timerFrameY+2,timerFrameX+3,timer);
}

void drawMassagebox(void){
    printMassage("test!!!!!!");
}

void drawEverything(void)
{
    clear();
    drawFrame(); 
    drawMap();
    drawMassagebox();
    drawCurLocation();
    drawTimer();
    drawEntity(player);
    //printf("%lf",(double)end_time);
}