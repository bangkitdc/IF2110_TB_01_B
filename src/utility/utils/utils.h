#ifndef UTILS_H
#define UTILS_H

// #include "game.h"
#include "../../include/boolean.h"
#include "../game/game.h"
#include "../../adt/machine/charmachine.h"
#include "../../adt/machine/wordmachine.h"
#include "../../adt/tree/tree.h"
#include "../../adt/liststatik/liststatikT.h"
#include "../../adt/liststatik/liststatikM.h"
#include "../color/color.h"
#include "../../adt/map/map.h"
#include "../../adt/simulator/simulator.h"
#include "../../adt/stack/stack.h"
#include "../../adt/set/set.h"

void startMenu();

int startInput(Word w);

void inputConfigFile(Game *g,Simulator *sim, char *PATH, int type);

int MenuInput(Word w);

void help();

int select(int min, int max);

void tambahBahan(Tree *p, Tree l);

void exitGame();

void printCookBook(ListStatikT listResep, ListStatikM listMakanan);

int getUrutanFromListMakanan(ListStatikM listMakanan, int idMakanan);

boolean apakahBisa(Tree t, Set s, ListStatikM listMakanan);

void rekomendasiMakanan(ListStatikM listMakanan, PrioQueue listInvenMakanan, ListStatikT listResep);

void mengolahMakanan(Makanan makananOlah, Simulator *simulator, PrioQueue *delivery_list, ListDinMakanan *latest_notification, MatrixKulkas kulkas, Stack *stackUndo, Game *game);
#endif