#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "MT.h"
#include "dmht.h"

void param_gen(int nparam, double* param);

int main(){
  int ndata=1080;
  double* test;
  int i,j;
  unsigned long hash;
  unsigned long hash2;
  unsigned long hash3;
  unsigned long hash4;
  double test2;
  
  init_genrand(194743097);

  test=(double*) malloc(sizeof(double)*ndata);

  for(  j=0;j<100000;j++){
    for(i=0;i<ndata;i++){
      test[i]=genrand_res53();
    }

    hash=hash_dl(2161,ndata,test);
    hash2=hash_dl2(2161,ndata,test);
    hash3=hash_dl3(2161,ndata,test);
    hash4=hash_dl4(2161,ndata,test);
	/* hash=hash_dl(9973,ndata,test); */
    printf("%d %d %d %d\n",hash,hash2,hash3,hash4);
  }
  /* test2=1.0; */
  /* hash=hash_dl(241,1,&test2); */
  /* test2=-1.0; */
  /* hash=hash_dl(241,1,&test2); */

  /* test2=0.1; */
  /* hash=hash_dl(241,1,&test2); */
  /* test2=-0.1; */
  /* hash=hash_dl(241,1,&test2); */

  /* test2=10.; */
  /* hash=hash_dl(241,1,&test2); */
  /* test2=-10.; */
  /* hash=hash_dl(241,1,&test2); */

  
  

 return 0;
 
} 
