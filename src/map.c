#include <rogue.h>

Tile** createMapTiles(void)
{
    Tile** tiles = calloc(MAP_HEIGHT, sizeof(Tile*)); //동적할당 상수값

    for(int y = 0; y < MAP_HEIGHT; y++)
    {
        tiles[y] = calloc(MAP_WIDTH, sizeof(Tile));
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            tiles[y][x].ch = '#';
            tiles[y][x].walkable = false; //false 즉, 벽 걷기 불가능한.
        }
    }

    return tiles;
}

Position setupMap(void)
{
    Position start_pos = {10,50};

    for (int y = 5; y < 15; y++)
    {
        for (int x = 40; x < 60; x++)
        {
            map[y][x].ch = '.';
            map[y][x].walkable = true; //평지 걷기 가능한
        }
    }

    return start_pos;
}

void freeMap(void) //동적할당 해체부
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        free(map[y]);
    }
    free(map);
} //아직 사용안함 closegame부분에 넣어야할듯?