#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include "../adt/adt.h"

typedef struct {
    // ListStatik listMakanan;
    // ListStatik listResep;
    Matrix map;
    
} Game;

void startGame(Game *game);



#endif