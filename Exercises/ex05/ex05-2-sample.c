#include <stdio.h>
#include <sys/time.h>

int main(){
  int i,n,sum;
  hrtime_t start,finish;

  printf("n= ");
  scanf("%d",&n);
  start=gethrtime(); /* ��¬���� */

  sum=0;
  for( i=0; i<n; i++) sum++;

  finish=gethrtime(); /* ��¬��λ */
  printf("time: %f seconds.\n", (double)(finish-start)/NANOSEC);

  return 0;
}
