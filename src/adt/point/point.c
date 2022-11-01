/* File: */

#include <stdio.h>
#include "point.h"

// Membentuk Point
void CreatePoint(POINT *P, int X, int Y){
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

// I/O device
void ReadPoint(POINT *P){
    int X, Y;
    scanf("%i %i", &X, &Y);
    CreatePoint(P, X, Y);
}
void WritePoint(POINT P){
    printf("(%i,%i)", Absis(P), Ordinat(P));
}

// Menentukan dimana letak P (ngecek dia masih didalam ruangan apa engga)


// Operasi Point (IS : setiap perpindahan tidak akan menabrak)
POINT MoveN(POINT P){ // North
    POINT tmp;
    CreatePoint(&tmp, Absis(P)-1, Ordinat(P));
    return tmp;
}
POINT MoveE(POINT P){ // East
    POINT tmp;
    CreatePoint(&tmp, Absis(P), Ordinat(P)+1);
    return tmp;
}
POINT MoveS(POINT P){ // South
    POINT tmp;
    CreatePoint(&tmp, Absis(P)+1, Ordinat(P));
    return tmp; 
}
POINT MoveW(POINT P){ // West
    POINT tmp;
    CreatePoint(&tmp, Absis(P), Ordinat(P)-1);
    return tmp;
}

// Mengecek apakah suatu point bersebelahan atau tidak
boolean SideBy(POINT P1, POINT P2) { //patokannya si P2
    boolean cek = false;
    if (Absis(P1) + 1 == Absis(P2) && Ordinat(P1) == Ordinat(P2)) { // P1 disebelah kiri P2 
        cek = true;
    } else if (Absis(P1) - 1 == Absis(P2) && Ordinat(P1) == Ordinat(P2)) { // P1 disebelah kanan P2
        cek = true;
    } else if (Absis(P1) == Absis(P2) && Ordinat(P1) + 1 == Ordinat(P2)) { // P1 diatas P2
        cek = true;
    } else if (Absis(P1) == Absis(P2) && Ordinat(P1) - 1 == Ordinat(P2)) { // P1 dibawah P2
        cek = true;
    }
    return cek;
}