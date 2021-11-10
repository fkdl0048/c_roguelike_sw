#include <rogue.h>

Inventory *createInventory(){
    Inventory *tmp = calloc(1, sizeof(Inventory));
    tmp->cardkey = 0;
    tmp->key = 0;
    tmp->driver = 0;
    return tmp;
}

//아이템 획득 - 0: 녹슨 열쇠, 1: 카드키, 2: 드라이버
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

//아이템 삭제 - 0: 녹슨 열쇠, 1: 카드키, 2: 드라이버
void deleteInventory(int id){
    switch(id){
        case 0:
            inven->key--;
            break;
        case 1:
            inven->cardkey--;
            break;
        case 2:
            inven->driver--;
            break;
        default:
            break;
    }
}
