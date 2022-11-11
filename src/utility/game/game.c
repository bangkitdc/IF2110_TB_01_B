#include <stdio.h>
#include "../utils/utils.h"

char *dirMakanan = "../../config/makanan/configmakanan.txt";
char *dirResep = "../../config/resep/configresep.txt";
char *dirPeta = "../../config/peta/configpeta.txt";

void startGame(Game *game, Simulator *simulator) {
    POINT p;
    PrioQueue pQueue;
    CreatePoint(&p, 0, 0);
    CreateEmptyPrioqueue(&pQueue, 100);
    CreateTime (&game->currentTime, 0, 1, 23);
    createLSMakanan(&game->listMakanan);
    CreateListTree(&game->listResep);
    createSimulator(simulator, "ADMIN", p, pQueue);

    printf("\nSelamat datang di BNMO!\n\n");

    inputConfigFile(game, simulator, dirMakanan, MAKANAN);
    inputConfigFile(game, simulator, dirResep, RESEP);
    inputConfigFile(game, simulator, dirPeta, PETA);

    WriteLokasi(simulator->lokasi);
    TulisTIME3(game->currentTime);
    
    printf("\n"); DisplayMap(game->map, simulator->lokasi);

    game->endGame = false;
}

boolean isEndGame(Game g) {
    return (g.endGame);
}