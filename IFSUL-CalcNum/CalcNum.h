//
//  CalcNum.h
//  IFSUL-CalcNum
//
//  Created by Tiago Baptista Noronha on 31/07/2018.
//  Copyright © 2018 Tiago Baptista Noronha. All rights reserved.
//

#ifndef CalcNum_h
#define CalcNum_h

void multK(int nl, int nc, double K, const double A[nl][nc], double resp[nl][nc]);
int mult(int nla, int nca, int nlb, int ncb, const double A[nla][nca], const double B[nlb][ncb], double resp[nla][ncb]);
void soma(int nl, int nc, const double A[nl][nc], const double B[nl][nc], double resp[nl][nc]);
void subt(int nl, int nc, const double A[nl][nc], const double B[nl][nc], double resp[nl][nc]);
double det(int n, const double A[n][n]);
void adj(int n, const double A[n][n], double resp[n][n]);
int inv(int n, const double A[n][n], double resp[n][n]);

#endif /* CalcNum_h */
