#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "MT.h"
#include "dmht.h"

void param_gen(int nparam, double* param);

int main(){
  int ndata=10;
  double* test;
  int i;
  unsigned long hash;
  double test2;
  
  init_genrand(194743097);

  test=(double*) malloc(sizeof(double)*ndata);

  for(i=0;i<ndata;i++){
    test[i]=genrand_res53();
  }
  
  hash=hash_dl(ndata,test);

  test2=1.0;
  hash=hash_dl(1,&test2);
  test2=-1.0;
  hash=hash_dl(1,&test2);

  test2=0.1;
  hash=hash_dl(1,&test2);
  test2=-0.1;
  hash=hash_dl(1,&test2);

  test2=10.;
  hash=hash_dl(1,&test2);
  test2=-10.;
  hash=hash_dl(1,&test2);

  
  
  printf("%x",hash);
 return 0;
 
} 
