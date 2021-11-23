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
    //Door
    for(int y = firstFloorHeight + firstFloorRoomSize, x = (firstFloorWidth + firstFloorX)/2 - 2;  x <= (firstFloorWidth + firstFloorX)/2 + 2; x++)
    {
        if (x == (firstFloorWidth + firstFloorX)/2 - 2 || x == (firstFloorWidth + firstFloorX)/2 + 2)
            map[y][x].ch = '+';
        else
            map[y][x].ch = '-';
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
    map[8][8].ch = '/';
    map[12][12].ch = '8';
    map[12][20].ch = 'K';
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
    int index = 0;
    for (int y = secondFloorY; y < secondFloorHeight; y++)
    {
        for (int x = secondFloorX; x < secondFloorWidth; x++)
        {
            if (ft_abs(x - secondFloorWidth / 2) % 15 == 0 && y == secondFloorY && x != secondFloorWidth / 2)
            {
                map[y - 1][x - 1].ch = '+';
                map[y - 1][x + 1].ch = '+';
                map[y - 1][x].ch = '-';
                roomPos[index].x = x;
                roomPos[index].y = y;
                index++;
            }
            else if (ft_abs(x - secondFloorWidth / 2) % 15 == 0 && y == secondFloorHeight - 1 && x != secondFloorWidth / 2)
            {
                map[y + 1][x - 1].ch = '+';
                map[y + 1][x + 1].ch = '+';
                map[y + 1][x].ch = '-';
                roomPos[index].x = x;
                roomPos[index].y = y;
                index++;
            }
            else if (y - (secondFloorY + secondFloorHeight) / 2 == 0 && x == secondFloorX)
            {
                map[y - 1][x - 1].ch = '+';
                map[y + 1][x - 1].ch = '+';
                map[y][x - 1].ch = '|';
                roomPos[index].x = x;
                roomPos[index].y = y;
                index++;
            }
            else if (y - (secondFloorY + secondFloorHeight) / 2 == 0 && x == secondFloorWidth - 1)
            {
                map[y - 1][x + 1].ch = '+';
                map[y + 1][x + 1].ch = '+';
                map[y][x + 1].ch = '|';
                roomPos[index].x = x;
                roomPos[index].y = y;
                index++;
            }
        }
    }
}

//roompos[0~9] -> 
// 0 1 2 3 
// 4     5
// 6 7 8 9

void setRoomFloor(void)
{
    //randam_Level
    for (int y = roomY; y < roomY + roomHeight; y++)
    {
        for (int x = roomX; x < roomX + roomWidth; x++)
        {
            map[y][x].ch = ' ';
            map[y][x].walkable = TRUE;
        }
    }
    map[roomY + roomHeight][roomX + roomWidth / 2 - 1].ch = '+';
    map[roomY + roomHeight][roomX + roomWidth / 2 + 1].ch = '+';
    map[roomY + roomHeight][roomX + roomWidth / 2].ch = '-';
    

    // 해당 좌표들 배열로 만들어서 포지션을 rand()설정
    // object 무조건 수정
    map[15][50].ch = '0';
    map[15][50].walkable = FALSE;
    map[15][50].item = '0';
    map[15][51].walkable = FALSE;
    map[15][51].ch = '0';
    map[15][45].ch = '0';
    map[15][45].walkable = FALSE;
    map[15][46].ch = '0';
    map[15][46].walkable = FALSE;
    //랜덤성 부여 수정 필요

    // if(randam_Level[curLocationFlag - 2].quiz == 1){
    //     callQuiz();
    // }

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
    else if(curLocationFlag >= 2){
        setRoomFloor();
        start_pos.x = roomX + roomWidth / 2;
        start_pos.y = roomY + roomHeight - 1;
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