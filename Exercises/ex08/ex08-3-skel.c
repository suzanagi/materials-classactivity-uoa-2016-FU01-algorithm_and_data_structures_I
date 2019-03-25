#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define N 100000

void print_array(int a[]);
void insertion(int a[]);
void shell(int a[]);

int main(){
  int i;
  int a[N], b[N];
  hrtime_t start, finish;

  srand(getpid());

  for( i=0; i<N; i++){
    a[i]=rand();
    b[i]=a[i];
  }

  start=gethrtime();
  insertion(a);
  finish=gethrtime();
  printf("insertion sort: elapsed time %f.\n", (double)(finish-start)/NANOSEC);

  start=gethrtime();
  shell(b);
  finish=gethrtime();
  printf("shell sort: elapsed time %f.\n", (double)(finish-start)/NANOSEC);


  return 0;
}

void print_array(int a[]){
  int i;

  for( i=0; i<N; i++ ){
    printf("%d ", a[i]);
  }
  printf("\n");
}

void insertion(int a[]){

  /* ここにプログラムを追加 */

}

void shell(int a[]){

  /* ここにプログラムを追加 */

}
