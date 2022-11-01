#include <stdio.h>
#include "../utils/utils.h"

char *dirMakanan = "../../config/makanan/configmakanan.txt";
char *dirResep = "../../config/resep/configresep.txt";
char *dirPeta = "../../config/peta/configpeta.txt";

void startGame(Game *game) {
    createLSMakanan(&game->listMakanan);
    CreateListTree(&game->listResep);

    printf("\nSelamat datang di BNMO!\n");

    inputConfigFile(game, dirMakanan, MAKANAN);
    inputConfigFile(game, dirResep, RESEP);
    inputConfigFile(game, dirPeta, PETA);
    DisplayMap(game->map);

    game->endGame = false;
}

boolean isEndGame(Game g) {
    return (g.endGame);
}