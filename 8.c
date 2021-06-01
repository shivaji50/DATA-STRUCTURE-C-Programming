// Function Prototype : void Maximum( PNODE Head); 
// Input linked list : |11|->|250|->|532|->|415| 
// Output : 1 0 2 1
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

   int iDigit=0,iMin=0,iNum=0;

	while(Head!=NULL)
	{
     iMin=9;
     iNum=Head->Data;

     while(iNum!=0)
     {
     	iDigit=iNum%10;
     	if(iDigit<iMin)
     	{
     		iMin=iDigit;
     	}
     	iNum=iNum/10;    	
     }
         printf("%d\t",iMin);
		   Head=Head->Next;
	}
}
int main()
{
	PNODE First=NULL;
	int ret=0;

	InsertL(&First,12);
	InsertL(&First,58);
	InsertL(&First,73);
	InsertL(&First,427);
	InsertL(&First,61);
	
	Display(First);
	Maximum(First);
	
    return 0;	
}