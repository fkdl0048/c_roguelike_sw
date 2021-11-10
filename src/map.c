#include <rogue.h>

Tile** createMapTiles()
{
    Tile** tiles = calloc(MAP_HEIGHT, sizeof(Tile*)); //동적할당 상수값

    for(int y = 0; y < MAP_HEIGHT; y++)
    {
        tiles[y] = calloc(MAP_WIDTH, sizeof(Tile));
    }

    return tiles;
}

void resetMapTiles() // 벽 다시그리기
{
    for(int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            map[y][x].ch = '#';
            map[y][x].walkable = FALSE; //false 즉, 벽 걷기 불가능한.
        }
    }
}

void setFirstFloor(void)
{
    for (int y = firstFloorY; y < firstFloorHeight; y++)
    {
        for (int x = firstFloorX; x < firstFloorWidth; x++)
        {
            map[y][x].ch = ' ';
            map[y][x].walkable = TRUE;
        }
    }
}

void setSecondFloor(void)
{
    for (int y = secondFloorY; y < secondFloorHeight; y++)
    {
        for (int x = secondFloorX; x < secondFloorWidth; x++)
        {
            map[y][x].ch = ' ';
            map[y][x].walkable = TRUE;
        }
    }
}

void setRoomFloor(void)
{
    for (int y = secondFloorY; y < secondFloorHeight; y++)
    {
        for (int x = secondFloorX; x < secondFloorWidth; x++)
        {
            map[y][x].ch = ' ';
            map[y][x].walkable = TRUE;
        }
    }
}

Position setupMap(void)
{
    resetMapTiles();

    Position start_pos;
    if(curLocationFlag == 0){
        setFirstFloor();
        start_pos.x = 10;
        start_pos.y = 10;
    }
    else if(curLocationFlag == 1){
        setSecondFloor();
        start_pos.x = 2;
        start_pos.y = 2;
    }
    else if(curLocationFlag == 2){

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