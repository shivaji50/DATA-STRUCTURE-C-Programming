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
void InsertL(PPNODE Head,int No)
{
	PNODE newn=NULL;
	PNODE Temp=*Head;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->Data=No;
	newn->Next=NULL;

	if(*Head==NULL)
	{
		*Head=newn;
	}
	else
	{
		while(Temp->Next!=NULL)
		{
			Temp=Temp->Next;
        }
        Temp->Next=newn;
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
int LastOcc(PNODE Head,int No)
{
	int iCnt=0,iCnt2=0;
	while(Head!=NULL)
	{
		iCnt++;
		if(Head->Data==No)
		 { iCnt2=iCnt; }
		Head=Head->Next;
	}
	return iCnt2;
}
int main()
{
	PNODE First=NULL;
	int ret=0;

	InsertL(&First,10);
	InsertL(&First,20);
	InsertL(&First,30);
	InsertL(&First,40);
	InsertL(&First,50);
	InsertL(&First,30);
	InsertL(&First,70);
	Display(First);
	ret=LastOcc(First,30);
	printf("The Last ccurance of 30 is %d",ret);
    return 0;	
}