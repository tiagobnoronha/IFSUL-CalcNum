//
//  CalcNum.c
//  IFSUL-CalcNum
//
//  Created by Tiago Baptista Noronha on 31/07/2018.
//  Copyright © 2018 Tiago Baptista Noronha. All rights reserved.
//

#include "CalcNum.h"
#include <stdio.h>

double det(int n, const double A[n][n]){
    double ret = 0;
    double C[n-1][n-1];
    
    if(n==1) return A[0][0];
    
    for(int l=0;l<n;l++){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                C[i][j] = A[(i<l)?i:i+1][j+1];
            }
        }
        ret += A[l][0]*(l%2==0?1:-1)*det(n-1,C);
    }
    
    return ret;
    
}

int mult(int nla, int nca, int nlb, int ncb, const double A[nla][nca], const double B[nlb][ncb], double resp[nla][ncb]){
    
    if(nca!=nlb) return 0;
    
    for(int l=0; l<nla; l++){
        for(int c=0; c<ncb; c++){
            double r = 0;
            for(int i=0;i<nca; i++){
                r += A[l][i] * B[i][c];
            }
            resp[l][c]=r;
        }
    }
    
    return 1;
}

void adj(int n, const double A[n][n], double resp[n][n]){
    double C[n-1][n-1];
    
    for(int l=0;l<n;l++){
        for(int c=0; c<n; c++){
            
            for(int i=0; i<n-1; i++){
                for(int j=0; j<n-1; j++){
                    C[i][j] = A[(i<l)?i:i+1][(j<c)?j:j+1];
                }
            }

            resp[c][l] = ((l+c)%2==0?1:-1)*det(n-1,C);
            
        }
    }

}

void multK(int nl, int nc, double K, const double A[nl][nc], double resp[nl][nc]){
    
    for(int l=0;l<nl;l++){
        for(int c=0; c<nc; c++){
            resp[l][c] = K*A[l][c];
        }
    }
}

int inv(int n, const double A[n][n], double resp[n][n]){
    double detA = det(n,A);
    double adjA[n][n];
    
    if(detA==0) return 0;
    
    adj(n, A, adjA);
    multK(n, n, 1/detA, adjA, resp);
    
    return 1;
}

void soma(int nl, int nc, const double A[nl][nc], const double B[nl][nc], double resp[nl][nc]){
    for(int l=0;l<nl; l++){
        for(int c=0; c<nc; c++){
            resp[l][c] = A[l][c]+B[l][c];
        }
    }
}

void subt(int nl, int nc, const double A[nl][nc], const double B[nl][nc], double resp[nl][nc]){
    for(int l=0;l<nl; l++){
        for(int c=0; c<nc; c++){
            resp[l][c] = A[l][c]-B[l][c];
        }
    }
}
