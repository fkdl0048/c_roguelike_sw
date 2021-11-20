#include <rogue.h>

Inventory *createInventory(void){
    Inventory *tmp = calloc(1, sizeof(Inventory));
    tmp->cardkey = 0;
    tmp->key = 0;
    tmp->driver = 0;
    return tmp;
}

void callItem(char check){
    
}