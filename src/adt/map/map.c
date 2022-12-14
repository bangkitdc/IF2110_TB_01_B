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
    createLSPoint(&MGame->T_Map);
    createLSPoint(&MGame->M_Map);
    createLSPoint(&MGame->F_Map);
    createLSPoint(&MGame->C_Map);
    createLSPoint(&MGame->B_Map);
    createLSPoint(&MGame->X_Map);
}

/* DISPLAY MAP */
void DisplayMap(Map MGame, POINT sim){
    int row = (MGame).Peta.rowEff;
    int col = (MGame).Peta.colEff;
    
    for (int i=0; i<row+2; i++) {
        for (int j=0; j<col+2; j++) {
            if (i == 0 || i == row+1 || j == 0 || j == col+1) {
                printf("*");
            } else {
                if (i == Absis(sim) + 1 && j == Ordinat(sim) + 1) {
                    printYellow('S');
                } else {
                    if (((MGame).Peta.mem[i-1][j-1]) == '#') {
                        printf(" ");
                    } else {
                        switch (((MGame).Peta.mem[i-1][j-1])) {
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
        }
        printf("\n");
    }
}