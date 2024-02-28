#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode {
	char Data;
	struct NTNode* pLchild;
	struct NTNode* pRchild;
}BTNode, * pBTNode;

pBTNode BTNode_Create(void);
void BTNode_PreTraverse(pBTNode);
void BTNode_InTraverse(pBTNode);
void BTNode_PosTraverse(pBTNode);

int main(void) {
	pBTNode pT = BTNode_Create();
	
	BTNode_PreTraverse(pT);
	BTNode_InTraverse(pT);
	BTNode_PosTraverse(pT);

	exit(0);
}

void BTNode_PreTraverse(pBTNode pT) {
	if (pT == NULL)
		return;

	printf("%c\n", pT->Data);
	BTNode_PreTraverse(pT->pLchild);
	BTNode_PreTraverse(pT->pRchild);
}
void BTNode_InTraverse(pBTNode pT) {
	if (pT == NULL)
		return;

	BTNode_PreTraverse(pT->pLchild);
	printf("%c\n", pT->Data);
	BTNode_PreTraverse(pT->pRchild);
}

void BTNode_PosTraverse(pBTNode pT) {
	if (pT == NULL)
		return;

	BTNode_PreTraverse(pT->pLchild);
	BTNode_PreTraverse(pT->pRchild);
	printf("%c\n", pT->Data);
}

pBTNode BTNode_Create(void) {
	pBTNode pA = (pBTNode)malloc(sizeof(BTNode));
	pBTNode pB = (pBTNode)malloc(sizeof(BTNode));
	pBTNode pC = (pBTNode)malloc(sizeof(BTNode));
	pBTNode pD = (pBTNode)malloc(sizeof(BTNode));
	pBTNode pE = (pBTNode)malloc(sizeof(BTNode));
	if (pA == NULL || pB == NULL || pC == NULL || pD == NULL || pE == NULL)
		return;

	pA->Data = 'A';
	pB->Data = 'B';
	pC->Data = 'C';
	pD->Data = 'D';
	pE->Data = 'E';

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
