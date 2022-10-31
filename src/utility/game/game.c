#include <stdio.h>
#include "../utils/utils.h"

Word dir = {"../../config/", 13};
Word dirMakanan = {"makanan/", 8};
Word dirResep = {"resep/", 6};
Word dirPeta = {"peta/", 5};

void startGame(Game *game) {
    createLSMakanan(&game->listMakanan);
    game->endGame = false;

    printf("\nSelamat datang di BNMO!\n\n");
    
    sprintBlue("Masukkan nama config file untuk makanan: \n");
    inputConfigFile(game, concatWord(dir, dirMakanan), MAKANAN);
}

boolean isEndGame(Game g) {
    return (g.endGame);
}