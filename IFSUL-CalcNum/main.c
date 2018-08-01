//
//  main.c
//  IFSUL-CalcNum
//
//  Created by Tiago Baptista Noronha on 26/07/2018.
//  Copyright © 2018 Tiago Baptista Noronha. All rights reserved.
//

#include <stdio.h>

#include "CalcNum.h"

int main(int argc, const char * argv[]) {
    double A[4][4] = {{1,3,3,5},{1,4,5,-9},{10,9,3,0},{-10,4,7,3}};
    double B[3][3] = {{9,2,3},{4,5,6},{7,8,9}};
    double C[3][3];
    double T[2][2] = {{1,2},{3,4}};
    
    //mult(3, 3, 3, 3, A, B, C );
    adj(3, B, C);
    for(int i=0;i<3;i++){
        for(int j=0; j<3; j++){
            printf("%lf\t", C[i][j]);
        }
        printf("\n");
    }
    
    printf("detA = %lf \n", det(4, A));
    printf("detB = %lf \n", det(3, B));
    printf("detC = %lf \n", det(3, C));
    printf("detT = %lf \n", det(2, T));
    return 0;
}

