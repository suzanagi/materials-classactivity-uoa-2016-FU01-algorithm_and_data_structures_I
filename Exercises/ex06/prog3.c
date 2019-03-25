#include <stdio.h>
#include <stdlib.h>

#define DEEP 10

struct node {
  struct node *right;
  char key;
  struct node *left;
};
typedef struct node * NodePointer;

int judge(char); //受け取った文字が適正かの判定
void push(NodePointer); //ノードのポインタをスタックにプッシュする
NodePointer pop(void); //スタックの中身をポップする
int isempty(void); /*スタックが空かどうかをチェックする関数。空なら 1、そうでないなら 0 を返す。*/
void treeinitialize(void); //木の初期化
NodePointer makenode(char); //ノードの作成
void preorder(NodePointer node);
void inorder(NodePointer node);
void postorder(NodePointer node);

NodePointer head, tail;
NodePointer stack[DEEP];

int main(){

  char receive;
  int flag;
  NodePointer a,b,p;

  /*スタックの中身をNULLで初期化しておく*/
  for(flag = 0; flag < DEEP; flag++){
    stack[flag] = NULL;
  }

  flag = 0;

  /*入力の要求*/
  printf("Input data by Reverse Polish Notation: ");

  while(1){
    /*1文字読み込む*/
    receive = getchar();
    switch(judge(receive)){      
    case 0:
      /*判定外の文字なら処理しないで終了*/
      printf("What's this character.\n");
      flag = 1;
      break;
    case 1:
      /* 受け取ったものが改行文字なら終了 */
      flag = 1;
      break;
    case 2:
      /* 受け取ったものが演算子の場合 */
      /*2回ポップする*/
      b = pop();
      a = pop();
      /*ポップしたポインタがNULLだったらエラー*/
      if(a == NULL || b == NULL){
	printf("No enough data in stack.\n");
	flag = 1;
	break;
      }
      /*ノードをつくる*/
      p = makenode(receive);
      /*それぞれポップしたものを右左に繋ぐ*/
      p->right = b;
      p->left = a;
      /*ノードを再びプッシュする*/
      push(p);
      break;
    case 3:
      /* 受け取ったものが数字の場合 */
      p = makenode(receive);
      push(p);
      break;
    }
    if(flag == 1) break;
  }

  /*スタックが空でなければ*/
  if(isempty() == 0){
    /*トラバース*/
    printf("preorder:  ");
    preorder(stack[0]);
    printf("\n");
    
    printf("inorder:   ");
    inorder(stack[0]);
    printf("\n");
    
    printf("postorder: ");
    postorder(stack[0]);
    printf("\n");
  }
  
  return 0;
}

 int judge(char c){/*文字が演算子か数字か改行文字かそれ以外か判定する関数*/
   /*
    *改行文字なら 1
    *演算子なら 2
    *数字なら 3
    *それ以外なら 0
    *を返す
    */
   if(c == '\n') return 1;
   else if(c == '+' || c == '-' || c == '*' 
	   || c == '/' || c == '%') return 2;
   else if(c >= '0' && c <= '9') return 3;
   else return 0;
 }

void push(NodePointer p){
  int i;
  for(i = 0; i < DEEP; i++){
    if(stack[i] == NULL) break;
  }
  stack[i] = p;
}

NodePointer pop(){
  NodePointer p;
  int i;

  if(isempty() == 1) return NULL;
  for(i = DEEP - 1; i >= 0; i--)
    if(stack[i] != NULL) break;
  p = stack[i];
  stack[i] = NULL;
  return p;
}

void treeinitialize(void){
  head=makenode(-1);
  tail=makenode(-1);
  head->right=tail;
  head->left=tail;
}

int isempty(){
  /*スタックが空かどうかをチェックする関数。空なら 1、そうでないなら 0 を返す。*/
  int i;
  for(i = DEEP - 1; i >= 0; i--){
    if(stack[i] != NULL) return 0;
  }

  return 1;
}

/*
 * ノードを作成し、そのノードへのポインタを返す。
 */
NodePointer makenode(char c){
  NodePointer x;

  x=malloc(sizeof(struct node));
  x->key=c;
  x->right=tail;
  x->left=tail;

  return x;
}

void preorder(NodePointer node){
  printf("%c",node->key);
  if(node->left != tail){
    preorder(node->left);
  }
  if(node->right != tail){
    preorder(node->right);
  }
}

void inorder(NodePointer node){
  if(node->left != tail){
    inorder(node->left);
  }
  printf("%c",node->key);
  if(node->right != tail){
    inorder(node->right);
  }
}

void postorder(NodePointer node){
  if(node->left != tail){
    postorder(node->left);
  }
  if(node->right != tail){
    postorder(node->right);
  }
  printf("%c",node->key);
}
