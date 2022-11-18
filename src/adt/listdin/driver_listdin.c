/*
#include <stdio.h>
#include "listdinmakanan.h"
#include "../infotype/infotype.h"
#include "../point/point.h"
#include "../time/time.h"
#include "../makanan/makanan.h"



int main() {
    ListDinMakanan testlist;
    Makanan tempfood;
    TIME temptime;
    POINT templocation;
    infotype tempinfotype;

    CreatePoint(&templocation, 1, 1);
    CreateTime(&temptime, 1, 3, 2);
    createMakanan(&tempfood, 12, "ayam", temptime, 'R', temptime, templocation, temptime);

    MakeinfoType(&tempinfotype, tempfood);
    CreateListMakananDin(&testlist, 50);
    insertLastMakanan(&testlist, tempinfotype);
    printListMakanan(testlist);

    return 0;
}
*/