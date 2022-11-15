#include <stdio.h>
#include "../utils/utils.h"

char *dirMakanan = "../../config/makanan/configmakanan.txt";
char *dirResep = "../../config/resep/configresep.txt";
char *dirPeta = "../../config/peta/configpeta.txt";

void startGame(Game *game, Simulator *simulator) {
    POINT p;
    PrioQueue pQueue;
    CreatePoint(&p, 0, 0);
    CreateEmptyPrioqueue(&pQueue, 50);
    CreateTime (&game->currentTime, 0, 1, 23);
    createLSMakanan(&game->listMakanan);
    CreateListTree(&game->listResep);

    char name[20];

    ListWord L;
    createListWord(&L);
    do {
        /* Baca Nama */
        sprintCyan("\nEnter Username: \n");
        printf("> ");
        L = readLine();

        if (L.Length == 1 && L.TabWords[0].Length <= 20) {
            int i;
            for (i = 0; i < L.TabWords[0].Length; i ++) {
                name[i] = L.TabWords[0].TabWord[i];
            }
            name[i] = '\0';
            // name = { wordToString(L.TabWords[0]) };
        } else {
            name[0] = '-'; name[1] = '1'; name[2] = '\0';
        }
        if (name[0] == '-' && name[1] == '1' && name[2] == '\0')
        {
            sprintRed("Input tidak valid, username harus terdiri dari 1 kata dan <= 20 karakter. Ulangi input!\n");
        }
    } while (name[0] == '-' && name[1] == '1' && name[2] == '\0');

    createSimulator(simulator, name, p, pQueue);

    printf("\nHalo %s,\n", simulator->username);
    printf("Selamat datang di BNMO!\n\n");

    inputConfigFile(game, simulator, dirMakanan, MAKANAN);
    inputConfigFile(game, simulator, dirResep, RESEP);
    inputConfigFile(game, simulator, dirPeta, PETA);

    WriteLokasi(simulator->lokasi);
    TulisTIME3(game->currentTime);
    printf("Notifikasi: -\n");      /* IDLE status saja, notifikasi asli ada di main */
    
    printf("\n"); DisplayMap(game->map, simulator->lokasi);

    game->endGame = false;
}

boolean isEndGame(Game g) {
    return (g.endGame);
}