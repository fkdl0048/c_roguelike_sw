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

void drawRect(int x,int y,int width, int height)
{
    int i,j;
    for(i = 1; i <= height;i++){
        for (j = 1; j <= width; j++){
            if((i == 1 || i == height) && (j == 1 || j == width))
                mvaddch(y+i,x+j,'*');
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
    char room_str[10] = "Room 20";
    if(curLocationFlag == 0){
        mvaddstr(curPosFrameY+2, curPosFrameX+3, "First Floor");
    }
    else if(curLocationFlag == 1){
        mvaddstr(curPosFrameY+2, curPosFrameX+3, "Second Floor");
    }
    else if(curLocationFlag >= 2){
        mvaddstr(curPosFrameY+2, curPosFrameX+3, strcat(room_str,ft_itoa(curLocationFlag - 2)));    
    }
}


void drawTimer(void){
    printTime();
}

void drawInventory(void){
    char rustykey_str[20] = "Rusty key : ";
    char driver_str[20] = "Driver : ";
    char cardkey_str[20] = "Card key : ";   
    mvaddstr(invenFrameY+2,invenFrameX+3,strcat(rustykey_str,ft_itoa(inven->key)));
    mvaddstr(invenFrameY+4,invenFrameX+3,strcat(driver_str,ft_itoa(inven->driver)));
    mvaddstr(invenFrameY+6,invenFrameX+3,strcat(cardkey_str,ft_itoa(inven->cardkey)));
}

void drawEverything(void)
{
    clear();
    drawFrame(); 
    drawMap();
    drawCurLocation();
    drawTimer();
    drawInventory();
    drawEntity(player);
    if (curLocationFlag == 1)
        drawEntity(npc);
}





// 프레임 부분 나중에 추가..! 이슈 추가 할것


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