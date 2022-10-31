#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include "../../adt/adt.h"

typedef enum {
    MAKANAN = 1,
    RESEP = 2,
    PETA = 3
} ConfigType;

typedef struct {
    int currentTime;
    ListStatik listMakanan;
    ListStatik listResep;
    Matrix map;
    boolean endGame;
} Game;

void startGame(Game *game);

boolean isEndGame(Game g);

#endif