#include <rogue.h>

Randam_Level *creatRandom(void){
    int i;
    int ran;

    int lock_room_num = max_lock_room;
    int key_num = max_key;
    int quiz_num = max_quiz;
    int dirver_num = max_driver;
    int box_num = max_box;

    Randam_Level *random = (Randam_Level *)malloc(sizeof(Randam_Level) * 10);
    
    for (i = 0; i < 10; i++)
    {
        random[i].box = 0;
        random[i].driver = 0;
        random[i].key = 0;
        random[i].lock_room = 0;
        random[i].quiz = 0;
    }

    while (lock_room_num)
    {
        ran = rand() % 10;
        if(random[ran].lock_room == 0){
            random[ran].lock_room++;
            if(dirver_num){
                random[ran].driver++;
                dirver_num--;
            }
            else if(box_num){
                random[ran].box++;
                box_num--;
            }
            lock_room_num--;
        } 
    }
    while (key_num)
    {
        ran = rand() % 10;
        if(random[ran].key == 0){
            random[ran].key++;
            key_num--;
        } 
    }
    while (quiz_num)
    {
        ran = rand() % 10;
        if(random[ran].quiz == 0){
            random[ran].quiz++;
            quiz_num--;
        }
    }
    
    return random;
}


void callRandom(void){
    int ran;
    if(randam_Level[curLocationFlag - 2].key == 1){
        while (1)
        {
            ran = rand() % 12;
            if(map[pos_arr[ran].y][pos_arr[ran].x].item)
                continue;
            else{
                map[pos_arr[ran].y][pos_arr[ran].x].item = 1;
                break;
            }
        }
    }
    if(randam_Level[curLocationFlag - 2].driver == 1){
        while (1)
        {
            ran = rand() % 12;
            if(map[pos_arr[ran].y][pos_arr[ran].x].item)
                continue;
            else{
                map[pos_arr[ran].y][pos_arr[ran].x].item = 2;
                break;
            }
        }
    }
    if(randam_Level[curLocationFlag - 2].box == 1){
        while (1)
        {
            ran = rand() % 12;
            if(map[pos_arr[ran].y][pos_arr[ran].x].item)
                continue;
            else{
                map[pos_arr[ran].y][pos_arr[ran].x].item = 3;
                break;
            }
        }
    }
}

// random free함수 작성하기
