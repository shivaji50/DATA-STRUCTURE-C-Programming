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
void Sum(PNODE Head)
{
	int sum=0;
	while(Head!=NULL)
  {
  	if(Head->Data%2==0)
  	{sum=sum+Head->Data;}
    Head=Head->Next;		
  }
	printf("\n Sum is %d",sum);
}
int main()
{
	PNODE First=NULL;
	int ret=0;

	InsertL(&First,11);
	InsertL(&First,20);
	InsertL(&First,32);
	InsertL(&First,41);
	
	Display(First);
	Sum(First);
	
    return 0;	
}