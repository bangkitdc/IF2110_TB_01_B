/* File: */

#include <stdio.h>
#include "map.h"
#include "../../utility/color/color.h"
#include "../machine/wordmachine.h"

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
    createLSPoint(&MGame->X_Map);

    // PETA(*MGame) = Pet;
    // SMap(*MGame) = Sim; 
    // TMap(*MGame) = T_M;
    // MMap(*MGame) = M_M;
    // FMap(*MGame) = F_M;
    // CMap(*MGame) = C_M;
    // BMap(*MGame) = B_M;
}

/* DISPLAY MAP */
void DisplayMap(Map MGame){
    int row = (MGame).Peta.rowEff;
    int col = (MGame).Peta.colEff;
    for (int i=0; i<row+2; i++) {
        for (int j=0; j<col+2; j++) {
            if (i == 0 || i == row+1 || j == 0 || j == col+1) {
                printf("*");
            } else {
                if (((MGame).Peta.mem[i-1][j-1]) == '#') {
                    printf(" ");
                } else {
                    switch (((MGame).Peta.mem[i-1][j-1])) {
                    case 'S':
                        printYellow('S');
                        break;
                    case 'T':
                        printGreen('T');
                        break;
                    case 'M':
                        printBlue('M');
                        break;
                    case 'X':
                        printf("X");
                        break;
                    case 'F':
                        printMagenta('F');
                        break;
                    case 'C':
                        printCyan('C');
                        break;
                    case 'B':
                        printRed('B');
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
}

/* Move Simulator */
void MNorth(Map *MGame, boolean *stuck){
    if ((*MGame).S_Map.X -1 >= 0 && (*MGame).S_Map.X-1 < (*MGame).Peta.rowEff) {
        if ((*MGame).S_Map.Y >= 0 && (*MGame).S_Map.Y < (*MGame).Peta.colEff) {
            if ((((*MGame).Peta.mem[(*MGame).S_Map.X -1][(*MGame).S_Map.Y])) == '#' ) {
                *stuck = false;
                (((*MGame).Peta.mem[(*MGame).S_Map.X -1][(*MGame).S_Map.Y])) = 'S'; //Update lokasi simulator di matriks
                (((*MGame).Peta.mem[(*MGame).S_Map.X][(*MGame).S_Map.Y])) = '#'; // update lokasi simulator di matriks
                (*MGame).S_Map.X = (*MGame).S_Map.X - 1; // Update lokasi simulator
            } else {
                *stuck = true;
            }
        } else {
            *stuck = true;
        }
    } else {
        *stuck = true;
    }
}
void MEast(Map *MGame, boolean *stuck){
    if ((*MGame).S_Map.X >= 0 && (*MGame).S_Map.X < (*MGame).Peta.rowEff) {
        if ((*MGame).S_Map.Y+1 >= 0 && (*MGame).S_Map.Y+1 < (*MGame).Peta.colEff) {
            if ((((*MGame).Peta.mem[(*MGame).S_Map.X][(*MGame).S_Map.Y +1])) == '#' ) {
                *stuck = false;
                (((*MGame).Peta.mem[(*MGame).S_Map.X][(*MGame).S_Map.Y+1])) = 'S'; //Update lokasi simulator di matriks
                (((*MGame).Peta.mem[(*MGame).S_Map.X][(*MGame).S_Map.Y])) = '#'; // update lokasi simulator di matriks
                (*MGame).S_Map.Y = (*MGame).S_Map.Y + 1; // Update lokasi simulator
            } else {
                *stuck = true;
            }
        } else {
            *stuck = true;
        }
    } else {
        *stuck = true;
    }
}
void MSouth(Map *MGame, boolean *stuck){
    if ((*MGame).S_Map.X +1 >= 0 && (*MGame).S_Map.X+1 < (*MGame).Peta.rowEff) {
        if ((*MGame).S_Map.Y >= 0 && (*MGame).S_Map.Y < (*MGame).Peta.colEff) {
            if ((((*MGame).Peta.mem[(*MGame).S_Map.X +1][(*MGame).S_Map.Y])) == '#' ) {
                *stuck = false;
                (((*MGame).Peta.mem[(*MGame).S_Map.X +1][(*MGame).S_Map.Y])) = 'S'; //Update lokasi simulator di matriks
                (((*MGame).Peta.mem[(*MGame).S_Map.X][(*MGame).S_Map.Y])) = '#'; // update lokasi simulator di matriks
                (*MGame).S_Map.X = (*MGame).S_Map.X + 1; // Update lokasi simulator
            } else {
                *stuck = true;
            }
        } else {
            *stuck = true;
        }
    } else {
        *stuck = true;
    }
}
void MWest(Map *MGame, boolean *stuck){
    if ((*MGame).S_Map.X >= 0 && (*MGame).S_Map.X < (*MGame).Peta.rowEff) {
        if ((*MGame).S_Map.Y -1 >= 0 && (*MGame).S_Map.Y -1 < (*MGame).Peta.colEff) {
            if ((((*MGame).Peta.mem[(*MGame).S_Map.X][(*MGame).S_Map.Y -1])) == '#' ) {
                *stuck = false;
                (((*MGame).Peta.mem[(*MGame).S_Map.X][(*MGame).S_Map.Y-1])) = 'S'; //Update lokasi simulator di matriks
                (((*MGame).Peta.mem[(*MGame).S_Map.X][(*MGame).S_Map.Y])) = '#'; // update lokasi simulator di matriks
                (*MGame).S_Map.Y = (*MGame).S_Map.Y - 1; // Update lokasi simulator
            } else {
                *stuck = true;
            }
        } else {
            *stuck = true;
        }
    } else {
        *stuck = true;
    }
}