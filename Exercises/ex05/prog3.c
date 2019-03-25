#include <stdio.h>
#include <sys/time.h>

int main(){
  int i,j,n,sum;
  hrtime_t start,finish;

  n = 500;
  
  while(n <= 10000){
    /*空回りさせる*/
    sum = 0;
    for(i = 0; i < 10000; i++)
      sum++;
    
    start=gethrtime(); /* 計測開始 */
    
    sum=0;
    for( i=0; i<n; i++)
      for( j = 0; j < i; j++)
	sum++;
    
    finish=gethrtime(); /* 計測終了 */
    printf("%d %f\n",n ,(double)(finish-start)/NANOSEC);

    n = n + 500;
  }
    
  return 0;
}
    
