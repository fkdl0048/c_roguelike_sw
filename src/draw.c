#include <rogue.h>

void drawMap(void)
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

void drawEverything(void)
{
    clear();
    drawMap();
    drawEntity(player);
}