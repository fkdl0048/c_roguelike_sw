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
        printMassage("used driver..!!!");
        inven->driver--;
        inven->cardkey++;
    }
    else{
        printMassage("You need a driver..!!!");
    }
}

void callItem(Tile* check){
    if(check->ch == '0' || check->ch == '/'){
        if(check->item == 1){
            printMassage("Get key..!!!");
            inven->key++;
            check->item = 0;
        }
        else if(check->item == 2){
            printMassage("Get dirver..!!!");
            inven->driver++;
            check->item = 0;
        }
        else if(check->item == 3){
            printMassage("This is box..!!!");
            addCardkey();
        }
        else{
            printMassage("Nothing");
        }
    }
}



// free함수 만들기