#include <stdio.h>
#include <stdlib.h>

#define M 11

struct node{
  char key;
};

void hashinitialize(void);
void hashinsert(char v);
int hash(char c);
int hash2(char c);
void hashprint(void);

struct node a[M];

int main(){
  char c;

  hashinitialize();

  printf("Input data: ");
  while( 1 ){
    c = getchar();
    if( c == '\n' ){
      break;
    }
    hashinsert(c);
    hashprint();
  }

  return 0;
}

void hashinitialize(void){
  int i;

  for( i=0; i<M; i++ ){
    a[i].key = ' ';
  }
}

void hashinsert(char v){
  int h1, h2;
  int i;

  h1 = hash(v);
  h2 = hash2(v);

  //fprintf(stderr, "before the while\n");
  
  while(a[h1].key != ' ') h1 = (h1 + h2) % M;

  //fprintf(stderr, "after the while\n");
  
  a[h1].key = v;

}

int hash(char c){
  return (int)(c-64)%M;
}

int hash2(char c){
  return (int)8-(c-64)%8;
}

void hashprint(void){
  int i;
  for( i=0; i<M; i++ ){
    printf("%c ", a[i].key);
  }
  printf("\n");
}
