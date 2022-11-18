/*
#include "set.h"
#include "../makanan/makanan.h"
#include "../queue/Prioqueue.h"
#include "../liststatik/liststatikM.h"
#include "../infotype/infotype.h"
#include "../time/time.h"
#include "../point/point.h"
#include <stdio.h>

int main () {
    Set testset1, testset2;
    Makanan makanan1, makanan2;
    ListStatikM testlistmakanan;
    PrioQueue testinventory;
    TIME EXP, DLVRY, PENGOLAHAN;
    POINT P;
    infotype testinfotype;

    createLSMakanan(&testlistmakanan);
    CreateEmptyPrioqueue(&testinventory, 50);

    CreateTime(&EXP, 1, 2, 3);
    CreateTime(&DLVRY, 1, 10, 3);
    CreateTime(&DLVRY, 1, 10, 3);
    CreateTime(&PENGOLAHAN, 1, 10, 3);
    CreatePoint(&P, 1, 1);
    createMakanan(&makanan1, 123, "ayam goyeng", EXP, 'T', DLVRY, P, PENGOLAHAN);
    createMakanan(&makanan2, 123, "ayam goyeng", EXP, 'T', DLVRY, P, PENGOLAHAN);
    MakeinfoType(&testinfotype, makanan2);
    insertFood(&testlistmakanan, makanan1);
    Enqueue1(&testinventory, testinfotype);

    
    createSet(&testset1);
    createSet(&testset2);

    makeSetFromInventory(&testset2, testlistmakanan, testinventory);
    makeSetFromListMakanan(&testset1, testlistmakanan);

    if (isSubset(testset1, testset2)) {
        printf("Subset benar");
    }


    return 0;
}
*/