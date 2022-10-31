#ifndef UTILS_H
#define UTILS_H

// #include "game.h"
#include "../../include/boolean.h"
#include "../game/game.h"
#include "../../adt/machine/charmachine.h"
#include "../../adt/machine/wordmachine.h"
#include "../color/color.h"

void startMenu();

int startInput(Word w);

void inputConfigFile(Game *g, Word PATH, int type);

int MenuInput(Word w);

void exitGame();

#endif