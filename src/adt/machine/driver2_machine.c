#include <stdio.h>
#include "wordmachine.h"

/* Driver input Console */

int main() {
    ListWord L;
    createListWord(&L);

    L = readLine();

    char *name = ListWordToString(ListWord L);

    printf("%s", name);
    return 0;
}