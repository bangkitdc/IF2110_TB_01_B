#ifndef LISTSTATIKT_H
#define LISTSTATIKT_H

#define MAX_RESEP 100
typedef struct
{
   Tree list[MAX_RESEP];
   int elEff;
} ListStatikT;

void CreateListTree(ListStatikT *lt);

#endif