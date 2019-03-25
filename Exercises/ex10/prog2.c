#include <stdio.h>

#define N 10

void printdata(void);
int binarysearch(int v);
int interpolationsearch(int v);

 int a[N]={ 4, 8, 10, 13, 16, 17, 19, 20, 23, 25 }; 

int main(){
  int key, ret;

  printdata();

  printf("Input key for binary search:  ");
  scanf("%d", &key);

  ret=binarysearch(key);

  if( ret==-1 ){
    printf("not found.\n");
  }else{
    printf("found.\n");
  }
  printf("\n");

  printf("Input key for interpolation search:  ");
  scanf("%d", &key);

  ret=interpolationsearch(key);

  if( ret==-1 ){
    printf("not found.\n");
  }else{
    printf("found.\n");
  }

  return 0;
}

int binarysearch(int v){

  int l = 0, r = N, m;
  while(r >= l){
	  m = (l + r) / 2;
	  
	  if(v < a[m]) r = m - 1;
	  else if(v == a[m]) return a[m];
	  else l = m + 1;
	  
  }

  return -1;
}

int interpolationsearch(int v){

  int l = 0, r = N - 1, m;
  while(r >= l){
	  /*0での除算になった場合は省く*/
	  if(a[r] == a[l]){
	    //printf("Devided by 0\n");
	    break;
	  }
	  /*分子が負になる場合は省く*/
	  if(v - a[l] < 0){
	    //printf("Minus numerator\n");
	    break;
	  }
	  //printf("l = %d, r = %d, v = %d\n", l, r, v);
	  //printf("a[l]: %d, a[r]: %d, r - l: %d\n", a[l], a[r], r - l);
	  m = l + (((double)(v - a[l])/(double)(a[r] - a[l])) * (r - l));
	  //printf("m = %d\n", m);
	  /*m の値がデータ列の範囲を超えた場合は省く*/
	  if(m >= N || m < 0){
	    //printf("m=%d, Data Range Overflow\n",m);
	    break;
	  }
		  
	  if(v < a[m]) r = m - 1;
	  else if(v == a[m]) return a[m];
	  else l = m + 1;
  }

  return -1;
}

void printdata(void){
  int i;

  printf("data:  ");
  for( i=0; i<N; i++){
    printf("%d ", a[i]);
  }
  printf("\n\n");
}
