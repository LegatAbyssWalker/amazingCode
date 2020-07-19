#include <stdio.h>

int hello[] = {
	       72,
	       101,
	       108,
	       108,
	       111,
	       32,
	       87,
	       111,
	       114,
	       108,
	       100
};

char c[] = {0x25,0x63,0x00};

char n[] = {012, 000};

unsigned int* P =
  (unsigned int*)
  (int*)
  (short*)
  (char*)
  (unsigned char*)
  (unsigned int*)
  &hello;

unsigned char convertFromInteger(int value) {
  return (
	  *(
	    (char*)
	    (
		    (short*)
		    (void*)
		    &value)))
    ;
}

int
main(
     int argc,
     char* argv[]
     )
{
  int x = (short)hello + (short)P - 2* (short)P;
  goto XX;
 LL:
  if (x == (sizeof(hello) >> 2)) goto LX;
 XX:
  while (*(P + 10) == 0144) {
    if ((hello + x) == (hello + (sizeof(hello) >> 2))) goto LL;
    int* h = hello + x++;
    int _h = *h;
    char __h = convertFromInteger(_h);
    printf(c, __h);
  };
 LX:
  printf(n);
  return x - (sizeof(hello) >> 2);
}
