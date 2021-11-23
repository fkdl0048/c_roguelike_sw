#include <rogue.h>

Inventory *createInventory(void){
    Inventory *tmp = calloc(1, sizeof(Inventory));
    tmp->cardkey = 0;
    tmp->key = 0;
    tmp->driver = 0;
    return tmp;
}

void callItem(Tile* check){
    if(check->ch == '0'){
        if(check->item == '0'){
            printMassage("Get key..!!!");
            inven->key++;
            check->item = ' ';
        }
        else{
            printMassage("Nothing");
        }
    }
}

// free함수 만들기