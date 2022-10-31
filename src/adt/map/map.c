/* File: */

#include <stdio.h>
#include "map.h"

/* Selektor */
void CreateMap(Map *MGame, int X, int Y){
    // Matrix Pet;
    // POINT Sim;
    // ListStatikP T_M, M_M, F_M, C_M, B_M;
    createMatrix(X, Y, &MGame->Peta);
    CreatePoint(&MGame->S_Map, MARKPOINT, MARKPOINT);
    createLSPoint(&MGame->T_Map);
    createLSPoint(&MGame->M_Map);
    createLSPoint(&MGame->F_Map);
    createLSPoint(&MGame->C_Map);
    createLSPoint(&MGame->B_Map);

    // PETA(*MGame) = Pet;
    // SMap(*MGame) = Sim; 
    // TMap(*MGame) = T_M;
    // MMap(*MGame) = M_M;
    // FMap(*MGame) = F_M;
    // CMap(*MGame) = C_M;
    // BMap(*MGame) = B_M;
}
