#include <stdio.h>
#include "../utils/utils.h"

char *dirMakanan = "../../config/makanan/configmakanan.txt";
char *dirResep = "../../config/resep/configresep.txt";
char *dirPeta = "../../config/peta/configpeta.txt";

void startGame(Game *game) {
    CreateTime (&game->currentTime, 0, 1, 23);
    createLSMakanan(&game->listMakanan);
    CreateListTree(&game->listResep);

    printf("\nSelamat datang di BNMO!\n\n");

    inputConfigFile(game, dirMakanan, MAKANAN);
    inputConfigFile(game, dirResep, RESEP);
    inputConfigFile(game, dirPeta, PETA);

    TulisTIME3(game->currentTime);
    DisplayMap(game->map);

    game->endGame = false;
}

boolean isEndGame(Game g) {
    return (g.endGame);
}