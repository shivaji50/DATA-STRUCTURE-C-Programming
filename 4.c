// Function Prototype :  void Maximum( PNODE Head); 
// Input linked list : |11|->|28|->|17|->|41|->|6|->|89| 
// Output : |11|->|82|->|71|->|14|->|6|->|98
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
	int Max=0,idigit=0;
	int str[20];
	int *p=str;
	while(Head!=NULL)
	{
		Max=Head->Data;
		sum=0;
		printf("|");
		while(Max>0)
		{
			idigit=Max%10;
			*p=idigit;
			printf("%d",*p);
			p++;
			Max=Max/10;
		}
		printf("|");
		printf("\t");
        Head=Head->Next;
	}
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