#include <rogue.h>

void makeFOV()
{ 
    int y, x, distance;
    int RADIUS = 15;
    Position target;

    map[player->pos.y][player->pos.x].visible = TRUE;
    map[player->pos.y][player->pos.x].seen = TRUE;

    target = npc->pos;
    distance = getDistance(player->pos, target);
    if (distance < RADIUS)
    { 
        if (isInMap(target.y, target.x) && lineOfSight(player->pos, target))
        { 
            npc->visible = TRUE;
            npc->seen = TRUE;
        } 
    }

    target = secondNpc->pos;
    distance = getDistance(player->pos, target);
    if (distance < RADIUS)
    { 
        if (isInMap(target.y, target.x) && lineOfSight(player->pos, target))
        { 
            secondNpc->visible = true;
            secondNpc->seen = true;
        } 
    }

  for (y = player->pos.y - RADIUS; y < player->pos.y + RADIUS; y++)
  { 
    for (x = player->pos.x - RADIUS; x < player->pos.x + RADIUS; x++)
    { 
      target.y = y;
      target.x = x;
      distance = getDistance(player->pos, target);

      if (distance < RADIUS)
      { 
        if (isInMap(y, x) && lineOfSight(player->pos, target))
        { 
          map[y][x].visible = TRUE;
          map[y][x].seen = TRUE;
        } 
      } 
    } 
  } 
}

void clearFOV()
{ 
  int y, x;
  int RADIUS = 15;
  npc->visible = FALSE;
  npc->seen = FALSE;
  secondNpc->visible = FALSE;
  secondNpc->seen = FALSE;
  for (y = player->pos.y - RADIUS; y < player->pos.y + RADIUS; y++)
  { 
    for (x = player->pos.x - RADIUS; x < player->pos.x + RADIUS; x++)
    {
      if (isInMap(y, x))
        map[y][x].visible = FALSE;
    }
  } 
} 

int getDistance(Position origin, Position target)
{ 
  double dy, dx;
  int distance;
  dx = target.x - origin.x;
  dy = (target.y - origin.y) * 2;
  distance = floor(sqrt((dx * dx) + (dy * dy)));

  return distance;
}

bool isInMap(int y, int x)
{ 
  if ((0 < y && y < MAP_HEIGHT) && (0 < x && x < MAP_WIDTH))
  { 
    return TRUE;
  }

  return FALSE;
}

bool lineOfSight(Position origin, Position target)
{
  int t, x, y, abs_delta_x, abs_delta_y, sign_x, sign_y, delta_x, delta_y;

  delta_x = origin.x - target.x;
  delta_y = origin.y - target.y;

  abs_delta_x = abs(delta_x);
  abs_delta_y = abs(delta_y);

  sign_x = getSign(delta_x);
  sign_y = getSign(delta_y);

  x = target.x;
  y = target.y;

  if (abs_delta_x > abs_delta_y)
  {
    t = abs_delta_y * 2 - abs_delta_x;

    do
    {
      if (t >= 0)
      {
        y += sign_y;
        t -= abs_delta_x * 2;
      }

      x += sign_x;
      t += abs_delta_y * 2;

      if (x == origin.x && y == origin.y)
      {
        return TRUE;
      }
    }
    while (map[y][x].transparent);

    return FALSE;
  }
  else
  {
    t = abs_delta_x * 2 - abs_delta_y;

    do
    {
      if (t >= 0)
      {
        x += sign_x;
        t -= abs_delta_y * 2;
      }

      y += sign_y;
      t += abs_delta_x * 2;

      if (x == origin.x && y == origin.y)
      {
        return TRUE;
      }
    }
    while (map[y][x].transparent);

    return FALSE;
  }
}

int getSign(int a)
{
  return (a < 0) ? -1 : 1;
}