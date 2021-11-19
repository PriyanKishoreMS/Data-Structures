#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *p, i;
  p = (int *)malloc(5*sizeof(int));
  p[0]=45;
  p[1]=54;
  p[2]=28;
  p[4]=12;
  p[3]=19;
  for(i=0;i<5;i++) {
    printf("%d\n", p[i]);
  }
  free(p);
  return 0;
}
