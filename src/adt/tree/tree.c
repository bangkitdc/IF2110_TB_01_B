#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Tree NewTree (ElType root, Tree children[])
/* Menghasilkan sebuah pohon root, children, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */
{
    /* KAMUS */
    Tree p;
    int pjg;

    /* ALGORITMA */
    p = (Address) malloc(sizeof(TreeNode));
    if (p != NULL) {
        ROOT(p) = root;
        pjg = *(&children+1)-children;
        for(int i=0;i<pjg;i++){
            CHILDREN(p)[i] = children[i];
        }
        CHILD_EFF(p) = pjg;
    }
    return p;
}

void CreateTree (ElType root, Tree children[], Tree *p)
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon p dari akar, children, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */
{
    /* KAMUS */

    /* ALGORITMA */
    *p = NewTree(root, children);
}

Address newTreeNode(ElType val)
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.children=[NULL*10], p↑.childEff=0 
   Jika alokasi gagal, mengirimkan NULL */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = (Address) malloc(sizeof(TreeNode));
    if (p != NULL) {
        ROOT(p) = val;
        for(int i=0;i<MAX_CHIlD;i++){
            CHILDREN(p)[i] = NULL;
        }
        CHILD_EFF(p) = 0;
    }
    return p;
}

void addChild(Tree *p, Tree child)
/* menambahkan child pada sebuah tree*/
{
    if(CHILD_EFF(*p) != MAX_CHIlD){
        CHILDREN(*p)[CHILD_EFF(*p)] = child;
        CHILD_EFF(*p)++;
    }
}

void deallocTreeNode (Address p)
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */
{
    /* KAMUS */

    /* ALGORITMA */
    free(p);
}

boolean isTreeEmpty (Tree p)
/* Mengirimkan true jika p adalah pohon biner yang kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    return (p == NULL);
}

boolean isOneElmt (Tree p)
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */
{
    /* KAMUS */

    /* ALGORITMA */
    return (!isTreeEmpty(p) && CHILD_EFF(p)==0);
}

/* ****** Display Tree ***** */
void printPreorder(Tree p)
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, children. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
    /* KAMUS */

    /* ALGORITMA */
    printf("(");
    if (!isTreeEmpty(p)) {
        printf("%d", ROOT(p));
        for(int i=0;i<CHILD_EFF(p);i++){
            printPreorder(CHILDREN(p)[i]);
        }
    }
    printf(")");
}