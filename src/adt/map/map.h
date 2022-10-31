/* File: */

#include <stdio.h>
#include "../../include/boolean.h"
#include "../matrix/matrix.h"
#include "../point/point.h"
#include "../liststatik/liststatikP.h"

#ifndef MAP_H
#define MAP_H

typedef struct
{
    Matrix Peta;
    POINT S_Map;
    ListStatikP T_Map;
    ListStatikP M_Map;
    ListStatikP F_Map;
    ListStatikP C_Map;
    ListStatikP B_Map;
} Map;

#define PETA(M) (M).Peta
#define SMap(N) (N).S_Map
#define TMap(O) (O).T_Map
#define MMap(O) (O).M_Map
#define FMap(O) (O).F_Map
#define CMap(O) (O).C_Map
#define BMap(O) (O).B_Map

/* Selektor */
void CreateMap(Map *MGame, int X, int Y);




#endif