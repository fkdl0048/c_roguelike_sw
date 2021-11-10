#include <rogue.h>
void createInventory(){
    inven = calloc(1, sizeof(Inventory));
    inven->cardkey = 0;
    inven->key = 0;
    inven->driver = 0;
}

//아이템 획득 - 
void addInventory(int id){
    switch(id){
        case 0:
            inven->key++;
            break;
        case 1:
            inven->cardkey++;
            break;
        case 2:
            inven->driver++;
            break;
        default:
            break;
    }
}