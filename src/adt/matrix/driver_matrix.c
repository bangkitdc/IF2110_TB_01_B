// #include <stdio.h>
// #include "matrix.h"

// int main(){
//     Matrix m;

//     createMatrix(5,5,&m);

//     for(int i=0;i<5;i++){
//         for(int j=0;j<5;j++){
//             ELMT_MATRIX(m, i, j) = (i+1)*(j+1);
//         }
//     }

//     printf("%d\n", countElmtMatrix(m));
//     if(isSquare(m)){
//         printf("Matrix square\n");
//     }

//     displayMatrix(m);

//     return 0;
// }