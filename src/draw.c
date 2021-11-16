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
            if((i == 1 || i == height) && (j == 1 || j == width)){
                mvaddch(y+i,x+j,'*');
            }
            else if(i == 1 || i == height){
                mvaddch(y+i,x+j,'-');
            }
            else if(j == 1 || j == width){
                mvaddch(y+i,x+j,'|');
            }
                mvprintw(y+i,x+j,"");
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

void drawMassagebox(void){
    printMassage("test!!!!!!");
}

void drawEverything(void)
{
    clear();
    drawFrame(); 
    drawMap();
    drawMassagebox();
    drawEntity(player);
}