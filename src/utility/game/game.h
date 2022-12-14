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
    TIME currentTime;
    ListStatikM listMakanan;
    ListStatikT listResep;
    Map map;
    boolean endGame;
} Game;

void startGame(Game *game, Simulator *s);
/* Inisiasi Game */

boolean isEndGame(Game g);
/* Menghasilkan true jika endGame = true, false jika tidak*/

#endif