#include <stdio.h>
#include "../utils/utils.h"

Word dir = {"../../config/", 13};
Word dirMakanan = {"makanan/", 8};
Word dirResep = {"resep/", 6};
Word dirPeta = {"peta/", 5};

void startGame(Game *game) {
    createLSMakanan(&game->listMakanan);
    game->endGame = false;

    printf("Selamat datang di BNMO!\nMasukkan nama config file untuk makanan: ");
    inputConfigFile(game, concatWord(dir, dirMakanan), MAKANAN);

    printCatalog(game->listMakanan);

    game->endGame = true;
}