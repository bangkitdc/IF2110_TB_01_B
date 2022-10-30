#include <stdio.h>
#include "../utils.h"

Word dir = {"../../config/", 13};
Word dirMakanan = {"makanan", 7};
Word dirResep = {"resep", 5};
Word dirPeta = {"peta", 4};

void startGame(Game *game) {
    createLSMakanan(&game->listMakanan);

    printf("Selamat datang di BNMO!\nMasukkan nama config file untuk makanan: ");
    inputConfigFile(&game, concatWord(dir, dirMakanan), MAKANAN);

}