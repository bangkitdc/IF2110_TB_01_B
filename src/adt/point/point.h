/* File: */

#ifndef POINT_H
#define POINT_H

#include "../../utility/boolean.h"

typedef struct { 
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y

// Membentuk Point
void CreatePoint(POINT *P, int X, int Y);

// I/O device
void ReadPoint(POINT *P);
void WritePoint(POINT P);

// Menentukan dimana letak P (ngecek dia masih didalam ruangan apa engga)


// Operasi Point 
POINT MoveN(POINT P); // North
POINT MoveE(POINT P); // East
POINT MoveS(POINT P); // South
POINT MoveW(POINT P); // West

// Mengecek apakah suatu point bersebelahan atau tidak
boolean SideBy(POINT P1, POINT P2);

#endif