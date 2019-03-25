#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATANUM 5000

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
int treelevel(NodePointer node);
char rand_ascii(void);

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

  /*5000個のデータを赤黒木に入れる*/
  for(i = 0; i < DATANUM; i++){
    rbtreeinsert(rand_ascii());
  }

  /*木は表示(print_tree 関数)させなくても良い*/
  //print_tree(head->right, 0);

  /*データを入れ終ったあとに、木の高さを求めて表示 */
  printf("level: %d\n", treelevel(head->right));

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
      x=x->left;//num++;
  //num++;
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

int treelevel(NodePointer node){

  int Llevel, Rlevel;

  /*左側の木の高さを求める*/
  if(node->left == tail) Llevel = 0;
  else Llevel = treelevel(node->left);

  /*右側の木の高さを求める*/
  if(node->right == tail) Rlevel = 0;
  else Rlevel = treelevel(node->right);

  if(Rlevel > Llevel) return Rlevel + 1;//右の分岐のほうが深い場合
  else if(Llevel > Rlevel) return Llevel + 1;//左の分岐のほうが深い場合
  else return Rlevel + 1;//どちらの分岐も等しい深さの場合
}

char rand_ascii(){
  static num = 0;
  char c;
  /*時間を用いるだけだと値が似てしまうので、numを用いて冗長性を持たせる*/
  srand((unsigned)time(NULL) + num);
  c = rand() % 26 + 65;
  num++;
  return c;
}
