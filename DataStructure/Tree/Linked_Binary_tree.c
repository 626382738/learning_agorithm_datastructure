#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct BTNode
{
	char data;
	struct BTNode * pLchild;
	struct BTNode * pRchild;
};

struct BTNode* CreateBTree();
void PreTraverseBTree(struct BTNode * pT);
void InTraverseBTree(struct BTNode * pT);
void PostTraverseBTree(struct BTNode * pT);

int main()
{
	struct BTNode * pT = CreateBTree();

	printf("pre order\n");
	PreTraverseBTree(pT);
	printf("\n\nIn order\n");
	InTraverseBTree(pT);
	printf("\n\npost order\n");
	PostTraverseBTree(pT);

	return 0;
}

void PreTraverseBTree(struct BTNode * pT)
{
	if(pT == NULL) return;

	printf("%c ",pT->data);
	if(pT->pLchild != NULL) PreTraverseBTree(pT->pLchild);
	if(pT->pRchild != NULL)	PreTraverseBTree(pT->pRchild);

}

void InTraverseBTree(struct BTNode * pT)
{
	if(pT == NULL) return;

	if(pT->pLchild != NULL) InTraverseBTree(pT->pLchild);
	printf("%c ",pT->data);
	if(pT->pRchild != NULL)	InTraverseBTree(pT->pRchild);
}
void PostTraverseBTree(struct BTNode * pT)
{
	if(pT == NULL) return;
	
	if(pT->pLchild != NULL) PostTraverseBTree(pT->pLchild);
	if(pT->pRchild != NULL)	PostTraverseBTree(pT->pRchild);
	printf("%c ",pT->data);
}

struct BTNode* CreateBTree()
{
	struct BTNode* pA = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode* pB = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode* pC = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode* pD = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode* pE = (struct BTNode *)malloc(sizeof(struct BTNode));

	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';

	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;

	return pA;
}
