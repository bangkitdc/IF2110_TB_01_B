#ifndef UTILS_H
#define UTILS_H

// #include "game.h"
#include "../../include/boolean.h"
#include "../game/game.h"
#include "../../adt/machine/charmachine.h"
#include "../../adt/machine/wordmachine.h"
#include "../../adt/tree/tree.h"
#include "../color/color.h"

void startMenu();

int startInput(Word w);

void inputConfigFile(Game *g, Word PATH, int type);

void exitGame();

#endif