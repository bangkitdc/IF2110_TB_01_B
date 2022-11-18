// #include <stdio.h>
// #include "liststatikM.h"
// #include "liststatikP.h"
// #include "liststatikT.h"
// #include "../point/point.h"
// #include "../makanan/makanan.h"

// int main() {
//     ListStatikM tmp1;
//     ListStatikP tmp2;
//     ListStatikT tmp3;

//     createLSMakanan(&tmp1);
//     createLSPoint(&tmp2);
//     CreateListTree(&tmp3);

//     POINT tmpp1;
//     for (int i=0; i<4; i++) {
//         CreatePoint(&tmpp1, i, i+1);
//         insertPoint(&tmp2, tmpp1);
//     }
//     int panjang = listLengthStatikP(tmp2);
//     printf("%d\n", panjang);

//     Makanan tmpfood;
//     TIME EXP;
//     TIME DLVRY;
//     TIME PENGOLAHAN;
//     POINT P;
//     CreateTime(&EXP, 1, 2, 3);
//     CreateTime(&DLVRY, 1, 10, 3);
//     CreateTime(&DLVRY, 1, 10, 3);
//     CreateTime(&PENGOLAHAN, 1, 10, 3);
//     CreatePoint(&P, 1, 1);
//     createMakanan(&tmpfood, 123, "ayam goyeng", EXP, 'T', DLVRY, P, PENGOLAHAN);
//     insertFood(&tmp1, tmpfood);
// }