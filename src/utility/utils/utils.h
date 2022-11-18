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
/* Memilih START/ EXIT */

int startInput(Word w);
/* Validasi startMenu */

void inputConfigFile(Game *g,Simulator *sim, char *PATH, int type);
/* Memasukkan config file (.txt) ke dalam game */

int MenuInput(Word w);
/* Mengecek command dari USER */

void help();
/* HELP command untuk menampilkan command apa saja yang tersedia */

int select(int min, int max);
/* Menginginkan input USER dari (min - max) */

void tambahBahan(Tree *p, Tree l);
/* Menambah bahan */

void printCookBook(ListStatikT listResep, ListStatikM listMakanan);
/* Menampilkan CookBook */

int getUrutanFromListMakanan(ListStatikM listMakanan, int idMakanan);
/* Mendapatkan urutan makanan */

boolean apakahBisa(Tree t, Set s, ListStatikM listMakanan);
/* Cek resep makanan */

void rekomendasiMakanan(ListStatikM listMakanan, PrioQueue listInvenMakanan, ListStatikT listResep);
/* Inisisasi rekomendasi makanan */

void mengolahMakanan(Makanan makananOlah, Simulator *simulator, PrioQueue *delivery_list, ListDinMakanan *latest_notification, MatrixKulkas kulkas, Stack *stackUndo, Stack *stackRedo, Game *game, State *latest_state);
/* Inisiasi pengolahan makanan */

void exitGame();
/* Keluar dari game */

#endif