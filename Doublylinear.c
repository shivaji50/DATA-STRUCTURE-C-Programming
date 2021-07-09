#include<stdio.h>
#include<stdlib.h>

int iSize=0;

typedef struct node
{
	int Data;
	struct node *next;
	struct node *prev;
}NODE,*PNODE,**PPNODE;

void InsertFirst(PPNODE Head,int iNo)
{
  PNODE newn=(PNODE)malloc(sizeof(NODE));
  newn->Data=iNo;
  newn->next=NULL;
  newn->prev=NULL;

  if(*Head==NULL)
  {
     *Head=newn;
  }
  else
  {
  	newn->next=*Head;
  	*Head=newn;
  }
  iSize++;
}

void InsertLast(PPNODE Head,int iNo)
{
  PNODE newn=(PNODE)malloc(sizeof(NODE));
  newn->Data=iNo;
  newn->next=NULL;
  newn->prev=NULL;
  PNODE Temp=*Head;

  if(*Head==NULL)
  {
     *Head=newn;
  }
  else
  {
  	while(Temp->next!=NULL)
  	{
  		Temp=Temp->next;
  	}
  	Temp->next=newn;
  	newn->prev=Temp;
  }
  iSize++;

}

void InsertAtPos(PPNODE Head,int iNo,int iPos)
{
	PNODE Temp=*Head;
	int i=1;
	if((iPos<1)||(iPos>iSize+1))
	{
		printf("Please enter valid position\n");
		return;
	}

	if(iPos==1)
	{
		InsertFirst(Head,iNo);
	}
	else if(iPos==iSize+1)
	{
		InsertLast(Head,iNo);
	}
	else
	{
		PNODE newn=(PNODE)malloc(sizeof(NODE));
        newn->Data=iNo;
        newn->next=NULL;
        newn->prev=NULL;
       for(i=1;i<iPos-1;i++)
       {
       	 Temp=Temp->next;
       }
       newn->next=Temp->next;
       Temp->next->prev=newn;
       newn->prev=Temp;
       Temp->next=newn;
       iSize++;
	}
}

void DeleteFirst(PPNODE Head)
{
     if(*Head==NULL)
     {
     	return;
     }

     if((*Head)->next==NULL)
     {
     	free(*Head);
     	*Head=NULL;
     }
     else
     {
     	(*Head)=(*Head)->next;
     	free((*Head)->prev);
     	(*Head)->prev=NULL;
     }
     iSize--;
}

void DeleteLast(PPNODE Head)
{
	 PNODE Temp=*Head;
    if(*Head==NULL)
     {
     	return;
     }

     if((*Head)->next==NULL)
     {
     	free(*Head);
     	*Head=NULL;
     }
     else
     {
     	  while(Temp->next->next!=NULL)
     	  {
     	  	 Temp=Temp->next;
     	  }
     	  free(Temp->next);
     	  Temp->next=NULL;
     }
     iSize--;
}

void DeleteAtPos(PPNODE Head,int iPos)
{
	int i=1;
	PNODE Temp=*Head;
    if((iPos<0)||(iPos>iSize))
    {
    	printf("Wrong position\n");
    	return;
    }

    if(iPos==1)
    {
    	DeleteFirst(Head);
    }
    else if(iPos==iSize)
    {
    	DeleteLast(Head);
    }
    else
    {
    	for(i=1;i<iPos-1;i++)
    	{
         Temp=Temp->next;
    	}
    	Temp->next=Temp->next->next;
    	free(Temp->next->prev);
    	Temp->next->prev=Temp;
    	iSize--;
    }
}

void Display(PNODE Head)
{
   while(Head!=NULL)
	{
		printf("|%d|->",Head->Data);
		Head=Head->next;
	}
	printf("NULL\n");
}

int Count()
{
	return iSize;
}


int main()
{
	PNODE First=NULL;
	int iChoice=1,no=0,iPos=0,iRet=0;

	while(iChoice!=0)
	{
		printf("Enter your choice\n");
		printf("1:Insert First\n");
		printf("2:Insert Last\n");
		printf("3:Insert at position\n");
		printf("4:Delete First\n");
		printf("5:Delete Last\n");
		printf("6:Delete At position\n");
		printf("7:Display node\n");
		printf("8:Count node\n");
		printf("0:EXIT\n");
		scanf("%d",&iChoice);

		switch(iChoice)
		{
			case 1:
			printf("Enter the number\n");
			scanf("%d",&no);
			InsertFirst(&First,no);
			break;

			case 2:
			printf("Enter the number\n");
			scanf("%d",&no);
			InsertLast(&First,no);
			break;

			case 3:
			printf("Enter the number\n");
			scanf("%d",&no);
			printf("Enter the position\n");
			scanf("%d",&iPos);
			InsertAtPos(&First,no,iPos);
			break;

			case 4:
			DeleteFirst(&First);
			break;

			case 5:
			DeleteLast(&First);
			break;

			case 6:
			printf("Enter the position\n");
			scanf("%d",&iPos);
			DeleteAtPos(&First,iPos);
			break;

			case 7:
			Display(First);
			break;

            case 8:
            iRet=Count();
            printf("The Counts of nodes are %d \n",iRet);
            break;

            case 0:
            printf("Thanks for using the Application\n");
            break;

            default:
            printf("Wrong Choice\n");
            break;
		}
	}
	return 0;
}