#ifndef UTILS_H
#define UTILS_H

// #include "game.h"
#include "../../include/boolean.h"
#include "../../adt/machine/charmachine.h"
#include "../../adt/machine/wordmachine.h"
#include "../../adt/tree/tree.h"
#include "../color/color.h"

Word START = {"START", 5};
Word EXIT = {"EXIT", 4};

Word BUY = {"BUY", 3};
Word FRY = {"FRY", 3};
Word CHOP = {"CHOP", 4};
Word BOIL = {"BOIL", 4};
Word MIX = {"MIX", 3};

void startMenu();

int startInput(Word w);

void exitGame();

#endif