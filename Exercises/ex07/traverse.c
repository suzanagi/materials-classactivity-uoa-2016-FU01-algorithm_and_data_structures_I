#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *right;
  char key;
  struct node *left;
};
typedef struct node * NodePointer;

void treeinitialize(void);
NodePointer makenode(char c);
void preorder(NodePointer node);
void inorder(NodePointer node);
void postorder(NodePointer node);

NodePointer head, tail;

int main(){
  treeinitialize();

  /* テスト用の木を作成 */
  head->right=makenode('O');
  head->right->left=makenode('L');
  head->right->right=makenode('S');
  head->right->right->left=makenode('O');
  head->right->left->left=makenode('D');
  head->right->left->left->left=makenode('A');
  head->right->left->left->right=makenode('F');
  head->right->left->left->right->right=makenode('H');
  head->right->left->left->right->right->right=makenode('I');
  head->right->left->right=makenode('N');
  

  /* トラバース */
  printf("preorder:  ");
  preorder(head->right);
  printf("\n");

  printf("inorder:   ");
  inorder(head->right);
  printf("\n");

  printf("postorder: ");
  postorder(head->right);
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
