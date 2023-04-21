//main.cpp
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<netinet/in.h>

uint32_t n1, n2, res;
uint32_t *buffer;
FILE *fp1, *fp2;

int main(int argc, char *argv[])
{
  if(argc != 3) {
    printf("Input Error!\n");
    return -1;
  }

  if((fp1 = fopen(argv[1], "rb")) == NULL || (fp2 = fopen(argv[2], "rb")) == NULL) {
    printf("Read Error!\n");
    return -1;
  }

  if((buffer = (uint32_t*)malloc(sizeof(uint32_t))) == NULL) {
    printf("Memory Error!\n");
    return -1;
  }

  fread(buffer, 4, 1, fp1);
  n1 = ntohl(*buffer);
  fread(buffer, 4, 1, fp2);
  n2 = ntohl(*buffer);
  res = n1 + n2;
  printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, res, res);
  
  fclose(fp1);
  fclose(fp2);
  return 0;
}
