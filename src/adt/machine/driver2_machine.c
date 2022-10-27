#include <stdio.h>
#include "wordmachine.h"

/* Driver input Console */

int main() {
    ListWord L;
    createListWord(&L);

    L = readLine();

    for (int i = 0; i < L.Length; i ++) {
        displayWord(L.TabWords[i]);
        printf(" ");
    }
    return 0;
}