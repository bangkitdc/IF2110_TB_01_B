#ifndef LISTSTATIKT_H
#define LISTSTATIKT_H

#include "../../include/boolean.h"
#include "../tree/tree.h"

#define MAX_RESEP 100
typedef struct {
   Tree list[MAX_RESEP];
   int elEff;
} ListStatikT;

void CreateListTree(ListStatikT *lt);

#endif