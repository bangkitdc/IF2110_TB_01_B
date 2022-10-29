#include <stdio.h>
#include "../utility/utils.h"

int main() {
    /* Game */
    startMenu();

    do {
        /* Baca Command START/ EXIT */
        ListWord L;
        createListWord(&L);
        L = readLine();
    
    } while (L.Length > 1);

    return 0;
}