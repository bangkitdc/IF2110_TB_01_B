/* File : tree.h */
/* ADT pohon */
/* Representasi Address dengan pointer */

#ifndef POHON_H
#define POHON_H

#include "../../include/boolean.h"
#include "../queue/Prioqueue.h"
#include "../makanan/makanan.h"
#include "../liststatik/liststatikM.h"


/* Selektor */
#define ROOT(p) (p)->info
#define CHILDREN(p) (p)->children
#define CHILD_EFF(p) (p)->childEff
#define MAX_CHIlD 10

typedef int ElTypeInt;
typedef struct treeNode* Address;
typedef struct treeNode { 
     ElTypeInt info;
     Address children[MAX_CHIlD];
     int childEff;
} TreeNode;


/* Definisi Pohon */
/* pohon kosong p = NULL */

typedef Address Tree;

Tree NewTree (ElTypeInt root, Tree children[]); 
/* Menghasilkan sebuah pohon root, children, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */

void CreateTree (ElTypeInt root, Tree children[], Tree *p);
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon p dari akar, children, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

Address newTreeNode(ElTypeInt val);
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.children=[NULL*10], p↑.childEff=0 
   Jika alokasi gagal, mengirimkan NULL */

void addChild(Tree *p, Tree x);
/* menambahkan child pada sebuah tree*/

void deallocTreeNode (Address p);
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */

boolean isTreeEmpty (Tree p);
/* Mengirimkan true jika p adalah pohon biner yang kosong */

boolean isOneElmt (Tree p);
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

/* ****** Display Tree ***** */
void printPreorder(Tree p);
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, children. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adal ah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */

#endif
