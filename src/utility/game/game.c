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

    sprintBlue("Masukkan nama config file untuk makanan (.txt): \n");
    inputConfigFile(game, concatWord(dir, dirMakanan), MAKANAN);

    // sprintBlue("\nMasukkan nama config file untuk resep: \n");
    // inputConfigFile(game, concatWord(dir, dirResep), RESEP);

//     sprintBlue("\nMasukkan nama config file untuk peta: \n");
//     inputConfigFile(game, concatWord(dir, dirPeta), PETA);
}

boolean isEndGame(Game g) {
    return (g.endGame);
}