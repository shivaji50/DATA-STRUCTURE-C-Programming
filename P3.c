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
int Max(PNODE Head)
{
	int sum=0;
	while(Head!=NULL)
	{
		sum=sum+Head->Data;
		Head=Head->Next;
	}
	return sum;
}
int main()
{
	PNODE First=NULL;
	int ret=0;

	InsertL(&First,10);
	InsertL(&First,20);
	InsertL(&First,30);
	InsertL(&First,40);
	
	Display(First);
	ret=Max(First);
	printf("The Sum is %d",ret);
    return 0;	
}