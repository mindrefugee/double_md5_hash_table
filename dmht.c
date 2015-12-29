#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dmht.h"


unsigned long hash_dl(int length,double* data){

  int i,j;
  unsigned long* base;
  double_byte db;
  
  base= ( unsigned long* )malloc(sizeof(unsigned long)*length);
  
  
  
  for(i=0;i<length;i++){
    db.d=data[i];
    printf("%.14e ",db.d);
    for(j=0;j<sizeof(double);j++){
      printf("%08x ",db.c[j]);
    }
    printf("\n");
    
    /*memcpy(&base[i],&data[i],sizeof(double));*/
    /* base[i]=(unsigned long) data[i]; */
    /* printf("%.14e %x\n",data[i],base[i]); */
  }
  
  

  
}
