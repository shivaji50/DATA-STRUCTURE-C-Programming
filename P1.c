#include<stdio.h>
#include<stdlib.h>
struct node
{
   int Data;
   struct node *Next;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node ** PPNODE;
void InsertFirst(PPNODE Head,int No)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->Data=No;
	newn->Next=NULL;

	if(*Head==NULL)
	{
		*Head=newn;
	}
	else
	{
		newn->Next=*Head;
		*Head=newn;
	}
}
void Display(PNODE Head)
{
	while(Head!=NULL)
	{
		printf("%d\n",Head->Data);
		Head=Head->Next;
	}
}
int FirstOcc(PNODE Head,int No)
{
	int iCnt=0;
	while(Head!=NULL)
	{
		iCnt++;
		if(Head->Data==No)
		 { break; }
		Head=Head->Next;
	}
	return iCnt;
}
int main()
{
	PNODE First=NULL;
	int ret=0;

	InsertFirst(&First,10);
	InsertFirst(&First,20);
	InsertFirst(&First,30);
	InsertFirst(&First,40);
	InsertFirst(&First,30);
	InsertFirst(&First,20);
	InsertFirst(&First,10);
	Display(First);
	ret=FirstOcc(First,30);
	printf("The First ccurance of 30 is %d",ret);
    return 0;	
}