#ifndef __DMHT_H__
#define __DMHT_H__


union _double_byte{
  double d;
  char c[sizeof(double)];
};
typedef union _double_byte double_byte;

unsigned long hash_dl(unsigned int mod, unsigned int length,double* data);
unsigned long hash_dl2(unsigned int mod, unsigned int length,double* data);
unsigned long hash_dl3(unsigned int mod, unsigned int length,double* data);
unsigned long hash_dl4(unsigned int mod, unsigned int length,double* data);








#endif  /* __DHMT_H__ */


