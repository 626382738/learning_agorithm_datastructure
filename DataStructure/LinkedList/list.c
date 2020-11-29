#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
	int data; 
	struct Node* pNext;
}NODE, *PNODE;	// NODE -> struct NODE     PNODE -> struct Node*

// function declare
PNODE create_list();
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE, int, int);
bool delete_list(PNODE, int, int*);
void sort_list(PNODE);

int main()
{
	PNODE pHead = NULL; // struct Node* pHead = NULL;

	pHead = create_list();	// create a linked_list, return the address of the head
	traverse_list(pHead);
	int len = length_list(pHead);
	printf("the length of list is %d\n", len);

//	sort_list(pHead);
//	traverse_list(pHead);

//	insert_list(pHead, 1, 999);
//	traverse_list(pHead);

	int val = 0;
	if(delete_list(pHead, 4, &val))
	{
		printf("success delete %d \n", val);
		traverse_list(pHead);
	}
	else
	{
		printf("fail delete \n");
	}
//	if( is_empty(pHead) )
//	{
//		printf("empty\n");
//	}
//	else
//	{
//		printf("not empty\n");
//	}

	return 0;
}

PNODE create_list()
{
	int len;
	int val;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if(NULL == pHead)
	{
		printf("fail");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;

	printf("enter the length of the linked list: ");
	scanf("%d", &len);

	for(int i=0; i<len; ++i)
	{
		printf("enter the %d's element: ",i+1);
		scanf("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL == pNew)
		{
			printf("fail");
			exit(-1);
		}
		pNew->data = val;		// set the new value into the pNew node
		pTail->pNext = pNew;	// set pTail point to pNew
		pNew->pNext = NULL;		// set pNew point to NULL
		pTail = pNew;			// update the pTail
	}

	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	if(p == NULL)
	{
		printf("empty\n");
	}
	while( p != NULL)
	{
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}

bool is_empty(PNODE pHead)
{
	if(pHead->pNext == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int len = 0;

	while(p != NULL)
	{
		len++;
		p = p->pNext;
	}

	return len;
}

void sort_list(PNODE pHead)
{
	int i, j, t;
	int len = 0;
	len = length_list(pHead);
	PNODE p, q;
	for(i=0, p=pHead->pNext; i<len-1; ++i,p=p->pNext)
	{
		for(j=i+1, q=p->pNext; j<len; ++j, q=q->pNext)
		{
			if(p->data > q->data)	// similar to a[i] > a[j]
			{
				t = p->data;		// t = a[i];
				p->data = q->data;	// a[i] = a[j];
				q->data = t;		// a[j] = t;
			}
		}
	}
	return;

}

// insert a node befor pos, the value is val, pos start from 1
bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;

	while(p!=NULL && i<pos-1)
	{
		p = p->pNext;
		++i;
	}

	if(i>pos-1 || p==NULL)
	{
		return false;
	}

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL == pNew)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	pNew->data = val;
//	PNODE q = p->pNext;
//	p->pNext = pNew;
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	return true;
}

bool delete_list(PNODE pHead, int pos, int *pVal)
{
	int i = 0;
	PNODE p = pHead;

	while(p->pNext!=NULL && i<pos-1)
	{
		p = p->pNext;
		++i;
	}

	if(i>pos-1 || p->pNext==NULL)
	{
		return false;
	}

	PNODE q = p->pNext;
	*pVal = q->data;
	// delete a node after p
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;

	return true;
}
