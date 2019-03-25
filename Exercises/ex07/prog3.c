#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *right;
  char key;
  struct node *left;
  int deletion;
};
typedef struct node * NodePointer;

void treeinitialize(void);
NodePointer makenode(char c);
void treeinsert_r(char c, NodePointer p);
void delete(char c, NodePointer p);
void preorder(NodePointer node);
void inorder(NodePointer node);
void postorder(NodePointer node);

NodePointer head, tail;

int main(){
  char c;

  treeinitialize();

  printf("INPUT DATA:  ");
  while( 1 ){
    c=getchar();
    if( c=='\n' ){
      break;
    }
    treeinsert_r(c, head);
  }

  /* トラバース */
  printf("inorder:  ");
  inorder(head->right);
  printf("\n");


  /*削除対象を入力*/
  printf("DELETE:  ");
  while( 1 ){
    c = getchar();
    if( c == '\n' ){
      break;
    }
    /*与えられた削除対象を削除*/
    delete(c, head->right);
  }

  /*トラバース*/
  printf("inorder:  ");
  inorder(head->right);
  printf("\n");

  return 0;
}

void treeinitialize(void){
  head=makenode(-1);
  tail=makenode(-1);
  head->right=tail;
  head->left=tail;
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

  x->deletion = 0;

  return x;
}

void treeinsert_r(char c, NodePointer p){

  if(c > p->key){//cの文字コードがpのキーよりも大きい場合(ツリー右側へ)
    if(p->right == tail){//pが外部節点だった場合
      p->right = makenode(c);
    }
    else{//pが内部節点だった場合
      treeinsert_r(c, p->right);
    }
  }
  else if(c == p->key){//cの文字コードがpのキーと等しい場合(今回は右側へ)
    if(p->right == tail){//pが外部節点だった場合
      p->right = makenode(c);
    }
    else{//pが内部節点だった場合
      treeinsert_r(c, p->right);
    }    
  }
  else{//cの文字コードがpのキーよりも小さい場合(ツリー左側へ)
    if(p->left == tail){//pが外部節点だった場合
      p->left = makenode(c);
    }
    else{//pが内部節点だった場合
      treeinsert_r(c, p->left);
    }
  }

}

/*delete()関数ではキーとしてcをもつノードを探し出しそのdeletionを1とする*/
void delete(char c, NodePointer p){
  if(p != tail){
    if(p->key == c) p->deletion = 1;
    delete(c, p->right);
    delete(c, p->left);
  }
}

void preorder(NodePointer node){
  if(node!=tail){
    if(node->deletion == 0)
      printf("%c ", node->key);
    preorder(node->left);
    preorder(node->right);
  }
}

void inorder(NodePointer node){
  if(node!=tail){
    inorder(node->left);
    if(node->deletion == 0)
      printf("%c ", node->key);
    inorder(node->right);
  }
}

void postorder(NodePointer node){
  if(node!=tail){
    postorder(node->left);
    postorder(node->right);
    if(node->deletion == 0)
      printf("%c ", node->key);
  }
}
