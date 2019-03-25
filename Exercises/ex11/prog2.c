#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *right;
  char key;
  struct node *left;
  int red;
};
typedef struct node * NodePointer;

NodePointer makenode(char c);
void rbtreeinitialize(void);
void rbtreeinsert(char c);
NodePointer rotate(char v, NodePointer y);
void split(char v);
void print_tree(NodePointer p, int l);

NodePointer head, tail, gg, g, p, x;

int main(){
  char c;
  int i;
  
  rbtreeinitialize();

  /*Original
  printf("INPUT DATA:  ");
  
  while( 1 ){
    c=getchar();
    if( c=='\n' ){
      break;
    }
    rbtreeinsert(c);
  }
  */

  /*AからZまでのキーを順に赤黒木に入れるように変更*/
  for(i = 65; i <= 90; i++){//asciiコードは65で'A', 90で'Z'
    c = i;
    rbtreeinsert(c);
  }

  /*
    出力結果は確かに二分木と比べ平衡する。
                  *Z
               Y
            *X
               W
         V
            U
      T
            S
         R
            Q
   *P
            O
         N
            M
      L
            K
         J
            I
H
         G
      F
         E
   D
         C
      B
         A


   */
  
  print_tree(head->right, 0);

  return 0;
}

NodePointer makenode(char c){
  NodePointer x;

  x=malloc(sizeof(struct node));
  x->key=c;
  x->right=tail;
  x->left=tail;
  x->red=0;

  return x;
}

void rbtreeinitialize(void){
  tail=makenode(-1);
  tail->left=tail;
  tail->right=tail;
  head=makenode(-1);
  head->right=tail;
  head->left=tail;
}

void rbtreeinsert(char c){
  x=head;
  p=head;
  g=head;
  while( x!=tail ){
    gg=g;
    g=p;
    p=x;
    if( c < x->key ){
      x=x->left;
    }else{
      x=x->right;
    }
    /* 4-ノードだったら分割 */
    if( x->left->red && x->right->red ){
      split(c);
    }
  }

  x=makenode(c);
  if( c < p->key ){
    p->left=x;
  }else{
    p->right=x;
  }
  split(c);
}

NodePointer rotate(char v, NodePointer y){
  NodePointer c, gc;
  if( v < y->key ){
    c=y->left;
  }else{
    c=y->right;
  }

  if( v < c->key ){
    gc=c->left;
    c->left=gc->right;
    gc->right=c;
  }else{
    gc=c->right;
    c->right=gc->left;
    gc->left=c;
  }

  if( v < y->key ){
    y->left=gc;
  }else{
    y->right=gc;
  }

  return gc;
}

void split(char v){
  x->red=1;
  x->left->red=0;
  x->right->red=0;
  if( p->red ){
    g->red=1;
    if( (v < g->key) != (v < p->key) ){
      p=rotate( v, g );
    }
    x=rotate( v, gg );
    x->red=0;
  }
  head->right->red=0;
}

void print_tree(NodePointer p, int level){
  int i;

  if( p!=tail){
    print_tree(p->right, level+1 ) ;

    for( i=0; i<level; i++ ){
      printf("   ");
    }
    if( p->red ){
      printf("*");
    }
    printf("%c\n", p->key);

    print_tree(p->left, level+1 );
  }
}


