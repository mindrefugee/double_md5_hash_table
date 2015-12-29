#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>
#include <gmp.h>
#include "dmht.h"

unsigned long hash_dl(int length,double* data){

  int i,j;
  unsigned long* base;
  double_byte db;
  char* char_data;

  MD5_CTX c;
  unsigned char md[MD5_DIGEST_LENGTH];
  int r;

  mpz_t number;

  mpz_init(number);
  mpz_ui_pow_ui(number,123,45);

  
  base= ( unsigned long* )malloc(sizeof(unsigned long)*length);
  char_data=(char* )malloc(sizeof(double)*length+1);
  char mdString[33];
  
  for(i=0;i<length;i++){
    db.d=data[i];
    printf("%.14e ",db.d);
    for(j=0;j<sizeof(double);j++){
      char_data[sizeof(double)*i+j]=db.c[j];
      printf("%08x ",db.c[j]);
    }
    printf("\n");


    
    /*memcpy(&base[i],&data[i],sizeof(double));*/
    /* base[i]=(unsigned long) data[i]; */
    /* printf("%.14e %x\n",data[i],base[i]); */
  }
  char_data[sizeof(double)*length]='\0';

  r=MD5_Init(&c);
  if(r != 1) {
    perror("init");
    exit(1);
  }
    
  r = MD5_Update(&c, char_data, strlen(char_data));
  if(r != 1) {
    perror("update");
    exit(1);
  }
    
  r = MD5_Final(md, &c);
  if(r != 1) {
    perror("final");
    exit(1);
  }
  
  

  for(i = 0; i < 16; i++)
    sprintf(&mdString[i * 2], "%02x", (unsigned int)md[i]);

  for(i=0;i<32i++){
    number=
  }
  
    printf("md5 digest: %s\n", mdString);


    /* for(i = 0; i < 16; i++) */

/* prime=251 */

    gmp_printf("gmp_printf %Zd\n",number);
    
    return 0;
}
