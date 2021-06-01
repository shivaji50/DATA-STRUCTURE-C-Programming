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
void Prime(PNODE Head)
{
	int i=0,N=0;
	while(Head!=NULL)
  {
     for(i=2;i<Head->Data;i++)
     {
     	if(Head->Data%i==0)
     	{
     		N=2;
     		break;
     	}
     }
     if(N==0)
     {
     	printf("\n|%d|\t",Head->Data);
     }
     Head=Head->Next;		
  }
}
int main()
{
	PNODE First=NULL;
	int ret=0;

	InsertL(&First,11);
	InsertL(&First,13);
	InsertL(&First,7);
	InsertL(&First,49);
	InsertL(&First,6);
	InsertL(&First,111);
	Display(First);
	Prime(First);
	
    return 0;	
}