#include <rogue.h>

Inventory *createInventory(void){
    Inventory *tmp = calloc(1, sizeof(Inventory));
    tmp->cardkey = 0;
    tmp->key = 0;
    tmp->driver = 0;
    return tmp;
}

void addCardkey(void){
    if(inven->driver == 1){
        printMassage("Used driver..!!!");
        inven->driver--;
        inven->cardkey++;
    }
    else{
        printMassage("You need a driver..!!!");
    }
}

void callItem(Tile* check){
    if(check->ch == '=' && (check->color == COLOR_PAIR(ITEM_COLOR)))
    {
        if(check->item == 1){
            printMassage("I got a key..!!!");
            inven->key++;
            check->item = 0;
        }
        else if(check->item == 2){
            printMassage("I got a dirver..!!!");
            inven->driver++;
            check->item = 0;
        }
        else if(check->item == 3){
            printMassage("I found a box..!!!");
            addCardkey();
        }
        else if(check->item == 4){
            printMassage("I got a battery..!!!");
            radius = 15;
            check->item = 0;
        }
        else{
            printMassage("Nothing");
        }
    }
}



// free함수 만들기