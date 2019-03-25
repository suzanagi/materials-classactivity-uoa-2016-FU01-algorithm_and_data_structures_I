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

  int i, j, v;
  for(i = 1; i <= N - 1; i++){
    v = a[i]; j = i;
    while(a[j - 1] > v){
      a[j] = a[j - 1];
      j--;
    }
    a[j] = v;
  }

}

void shell(int a[]){
  int i, j, h, v;
  for(h = 1; h <= N / 9; h = 3 * h + 1);
  for(; h > 0; h /= 3)
    for(i = h + 1; i <= N - 1; i += 1){
      v = a[i]; j = i;
      while(j > h && a[j - h] > v){
	a[j] = a[j - h];
	j -= h;
      }
      a[j] = v;
    }
}
