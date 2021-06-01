// Function Prototype : void Maximum( PNODE Head); 
// Input linked list : |11|->|20|->|32|->|41| 
// Output : 1 2 6 4
// author : Shivai Das

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
	printf("\n\n");
}
void Maximum(PNODE Head)
{
	int idigit=0,pal=0,Max=0;
	while(Head!=NULL)
	{
		pal=1;
		Max=Head->Data;
		while(Max>0)
		{
			idigit=Max%10;
			if(idigit!=0)
			{pal=pal*idigit;}
			Max=Max/10;
		}
		
			printf("|%d|\t",pal);
		   Head=Head->Next;
	}
}
int main()
{
	PNODE First=NULL;
	int ret=0;

	InsertL(&First,11);
	InsertL(&First,28);
	InsertL(&First,70);
	InsertL(&First,414);
	InsertL(&First,6);
	
	Display(First);
	Maximum(First);
	
    return 0;	
}