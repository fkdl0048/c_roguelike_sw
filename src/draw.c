#include <rogue.h>

void drawMap(void) // 맵 그림
{
    for(int y = 0; y < MAP_HEIGHT; y++)
    {
        for(int x = 0; x < MAP_WIDTH; x++)
        {
            mvaddch(y,x,map[y][x].ch);
        }
    }
}

void drawEntity(Entity* entity)
{
    mvaddch(entity->pos.y, entity->pos.x, entity->ch);// y,x,표시할 문자 세가지를 인수로 받아 표시 *y먼저x가 뒤에온다*
}

void drawFrame(int x,int y,int width, int height)
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
        }
    }
}

void drawEverything(void)
{
    clear();
    drawMap();
    drawFrame(94,0,27,3); // 현재위치
    drawFrame(94,5,27,3); // 타이머
    drawFrame(94,10,27,8); // 타이머
    drawFrame(0,26,90,3); // 메세지 박스
    drawEntity(player);
}