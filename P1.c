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
void Perfect(PNODE Head)
{
	int sum=0,i=0;
	while(Head!=NULL)
	{
		sum=0;
		for(i=1;i<Head->Data;i++)
		{
			if(Head->Data%i==0)
			{
				sum=sum+i;
			}
		}
		if(Head->Data==sum)
		{
			printf("\n Perfect No are=|%d|\t",Head->Data);			
		}
		Head=Head->Next;
	}
	
}
int main()
{
	PNODE First=NULL;
	int ret=0;

	InsertL(&First,11);
	InsertL(&First,28);
	InsertL(&First,17);
	InsertL(&First,41);
	InsertL(&First,6);
	InsertL(&First,89);
	Display(First);
	Perfect(First);
	
    return 0;	
}