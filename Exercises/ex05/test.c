#include <stdio.h>
#include <sys/time.h>

int main(){
  int i,j,n,sum;
  hrtime_t start,finish;

  printf("n= ");
  scanf("%d",&n);
  start=gethrtime(); /* 計測開始 */

  sum=0;
  for( i=0; i<n; i++)
    for( j = 0; j < i; j++)
      sum++;

  finish=gethrtime(); /* 計測終了 */
  printf("time: %f seconds.\n", (double)(finish-start)/NANOSEC);

  return 0;
}
