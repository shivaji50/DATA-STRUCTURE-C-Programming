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
		printf("|%d|\t",Head->Data);
		Head=Head->Next;
	}
}
void Maximum(PNODE Head)
{
	int Max1=0,Max2=0;
	Max1=Head->Data;
	PNODE Head2=Head;
	Max2=Head->Data;
	while(Head!=NULL)
	{
		if(Head->Data>Max1)
		{
			Max1=Head->Data;
		}
		Head=Head->Next;
	}
	while(Head2!=NULL)
	{
		if((Head2->Data<Max1)&&(Head2->Data>Max2))
		{
			Max2=Head2->Data;
		}
		Head2=Head2->Next;
	}
	printf("\nSecond Highest is %d",Max2);
}
int main()
{
	PNODE First=NULL;
	int ret=0;

	InsertL(&First,110);
	InsertL(&First,230);
	InsertL(&First,320);
	InsertL(&First,200);
	
	Display(First);
	Maximum(First);
	
    return 0;	
}