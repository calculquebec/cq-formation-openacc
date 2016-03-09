#pragma once
#include<cstdlib>
#include "vector.h"


double dot(const vector& x, const vector& y) {
  double sum=0;
  unsigned int n=x.n;
  double *__restrict xcoefs=x.coefs;
  double *__restrict ycoefs=y.coefs;

#pragma acc kernels present(xcoefs,ycoefs)
  {
    for(int i=0;i<n;i++) {
      sum+=xcoefs[i]*ycoefs[i];
    }
  }
  return sum;
}

void waxpby(double alpha, const vector &x, double beta, const vector &y, const vector& w) {
  unsigned int n=x.n;
  double *__restrict xcoefs=x.coefs;
  double *__restrict ycoefs=y.coefs;
  double *__restrict wcoefs=w.coefs;

#pragma acc kernels present(xcoefs,ycoefs,wcoefs)
  {
    for(int i=0;i<n;i++) {
      wcoefs[i]=alpha*xcoefs[i]+beta*ycoefs[i];
    }
  }
}

