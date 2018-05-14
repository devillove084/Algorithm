#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

void CreateBiTree(BiTree *T){
	char c;
	scanf("%c",&c);
	if( '@'== c){
		*T = NULL;
	}else{
		*T = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

void Visit(char a){
	printf("%c",a);
}

void PostOrder(BiTree T){
	if(T){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		Visit(T->data);
	}
}

int main(){

	BiTree T = NULL;
	CreateBiTree(&T);
	PostOrder(T);
	return 0;
}
