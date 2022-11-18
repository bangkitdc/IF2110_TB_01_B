// #include <stdio.h>
// #include "matrixKulkas.h"

// int main(){
//     MatrixKulkas m;
//     ElType x;
//     TIME t;
//     POINT p;

//     p.X = 2;
//     p.Y = 3;

//     t.DD = 0;
//     t.HH = 0;
//     t.MM = 12;

//     x.info.id = 1;
//     x.info.name = "Choco Lava";
//     x.info.delivery = t;
//     x.info.expiry = t;
//     x.info.size = p;
//         // id = 1;             
//         // char *name;         
//         // TIME expiry;        /* Waktu kedaluwarsa */
//         // TIME delivery;      /* Lama pengiriman makanan */
//         // char location;      /* Lokasi aksi makanan */
//         // POINT size;         /* Size makanan (mxn) */
//         // TIME pengolahan;    

//     createMatrixKulkas(10, 20, &m);

//     for(int i=0;i<p.X;i++){
//         for(int j=0;j<p.Y;j++){
//             m.mem[i][j] = x;
//         }
//     }

//     displayMatrixKulkas(m);

//     if(isFullKulkas(m)){
//         printf("kulkas penuh\n");
//     }else{
//         printf("kulkas tidak penuh\n");
//     }

//     return 0;
// }