#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include "../adt/adt.h"

int currentTime;

typedef enum {
    MAKANAN = 1,
    RESEP = 2;
    PETA = 3;
} ConfigType;

typedef struct {
    // ListStatik listMakanan;
    // ListStatik listResep;
    Matrix map;
    ListDin notifikasi;
    boolean endGame;
} Game;

void startGame(Game *game);



#endif