#include <rogue.h>

int abs(int n)
{
    if (n < 0)
        return (n * -1);
    return n;
}

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
    //1층
    for (int y = firstFloorY; y < firstFloorHeight; y++)
    {
        for (int x = firstFloorX; x < firstFloorWidth; x++)
        {
            map[y][x].ch = ' ';
            map[y][x].walkable = TRUE;
        }
    }
    for (int y = firstFloorHeight;y < firstFloorHeight + firstFloorRoomSize; y++){
        for (int x = (firstFloorWidth + firstFloorX)/2 - 2 * firstFloorRoomSize; x < (firstFloorWidth + firstFloorX)/2 + 2 * firstFloorRoomSize; x++){
            map[y][x].ch = ' ';
            map[y][x].walkable = TRUE;
        }
    }
    //계단
    for (int x = firstFloorX, y = firstFloorY; x < firstFloorX + stairSize; x++)
    {
        map[y][x].ch = ']';
        map[y][x].walkable = FALSE;
    }
    for (int x = firstFloorWidth - stairSize, y = firstFloorY; x < firstFloorWidth; x++)
    {
        map[y][x].ch = '[';
        map[y][x].walkable = FALSE;
    }
}

void setSecondFloor(void)
{
    //2층 복도
    for (int y = secondFloorY; y < secondFloorHeight; y++)
    {
        for (int x = secondFloorX; x < secondFloorWidth; x++)
        {
            map[y][x].ch = ' ';
            map[y][x].walkable = TRUE;
        }
    }
    for (int y = secondFloorY + secondFloorCenterSize; y < secondFloorHeight - secondFloorCenterSize; y++)
    {
        for (int x = secondFloorX + 2 * secondFloorCenterSize; x < secondFloorWidth - 2 * secondFloorCenterSize; x++)
        {
            map[y][x].ch = '#';
            map[y][x].walkable = FALSE;
        }
    }
    for (int y = secondFloorY + secondFloorCenterSize; y < secondFloorHeight - secondFloorCenterSize; y++)
    {
        for (int x = (secondFloorX + secondFloorWidth)/2 - 1; x < (secondFloorX + secondFloorWidth)/2 + 1; x++)
        {
            map[y][x].ch = ' ';
            map[y][x].walkable = TRUE;
        }
    }
    //계단
    for (int x = secondFloorX, y = secondFloorY; x < secondFloorX + stairSize; x++)
    {
        map[y][x].ch = ']';
            map[y][x].walkable = FALSE;
    }
    for (int x = secondFloorWidth - stairSize, y = secondFloorY; x < secondFloorWidth; x++)
    {
        map[y][x].ch = '[';
            map[y][x].walkable = FALSE;
    }
    //Room Entrance
    for (int y = secondFloorY; y < secondFloorHeight; y++)
    {
        for (int x = secondFloorX; x < secondFloorWidth; x++)
        {
            if (abs(x - secondFloorWidth / 2) % 15 == 0 && y == secondFloorY && x != secondFloorWidth / 2)
            {
                map[y][x - 1].ch = '<';
                map[y][x + 1].ch = '>';
                map[y - 1][x].ch = '+';
                
                map[y][x - 1].walkable = FALSE;
                map[y][x + 1].walkable = FALSE;
            }
            else if (abs(x - secondFloorWidth / 2) % 15 == 0 && y == secondFloorHeight - 1 && x != secondFloorWidth / 2)
            {
                map[y][x - 1].ch = '<';
                map[y][x + 1].ch = '>';
                map[y + 1][x].ch = '+';
                map[y][x - 1].walkable = FALSE;
                map[y][x + 1].walkable = FALSE;
            }
            else if (abs(y - secondFloorHeight / 2) % 4 == 0 && x == secondFloorX && y != secondFloorY)
            {
                map[y - 1][x].ch = '^';
                map[y + 1][x].ch = 'v';
                map[y][x - 1].ch = '+';
                map[y - 1][x].walkable = FALSE;
                map[y + 1][x].walkable = FALSE;
            }
            else if (abs(y - secondFloorHeight / 2) % 4 == 0 && x == secondFloorWidth - 1 && y != secondFloorY)
            {
                map[y - 1][x].ch = '^';
                map[y + 1][x].ch = 'v';
                map[y][x + 1].ch = '+';
                map[y - 1][x].walkable = FALSE;
                map[y + 1][x].walkable = FALSE;
            }
        }
    }
}

void setRoomFloor(void)
{
    for (int y = roomY; y < roomY + roomHeight; y++)
    {
        for (int x = roomX; x < roomX + roomWidth; x++)
        {
            if (x == roomX + roomWidth / 2 - 1 && y == roomY + roomHeight - 1)
            {
                map[y][x].ch = '<';
                map[y][x].walkable = FALSE;
            }
            else if (x == roomX + roomWidth / 2 + 1 && y == roomY + roomHeight - 1)
            {
                map[y][x].ch = '>';
                map[y][x].walkable = FALSE;
                map[y + 1][x - 1].ch = '+';
            }
            else
            {
                map[y][x].ch = ' ';
                map[y][x].walkable = TRUE;
            }
        }
    }
}

Position setupMap(void)
{
    resetMapTiles();

    Position start_pos;
    if(curLocationFlag == 0){
        setFirstFloor();
        start_pos.x = 11;
        start_pos.y = 11;
    }
    else if(curLocationFlag == 1){
        setSecondFloor();
        start_pos.x = 5;
        start_pos.y = 5;
    }
    else if(curLocationFlag == 2){
        setRoomFloor();
        start_pos.x = 50;
        start_pos.y = 20;
    }

    return start_pos;
}

void freeMap(void)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        free(map[y]);
    }
    free(map);
} 