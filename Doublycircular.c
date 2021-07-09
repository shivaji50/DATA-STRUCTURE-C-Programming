#include<stdlib.h>
#include<stdio.h>

int iSize=0;
struct node
{
   int data;
   struct node *next;
   struct node *Prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE Head,PPNODE Tail,int iNo)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=iNo;
	newn->next=NULL;
	newn->Prev=NULL;

	if(*Head==NULL)
	{
        *Head=newn;
        *Tail=newn;
	}
	else
	{
		newn->next=*Head;
		(*Head)->Prev=newn;
		*Head=newn;
	}
	(*Tail)->next=*Head;
	(*Head)->Prev=*Tail;
	iSize++;
}


void InsertLast(PPNODE Head,PPNODE Tail,int iNo)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=iNo;
	newn->next=NULL;
	newn->Prev=NULL;

    if(*Head==NULL)
		{
			*Head=newn;
			*Tail=newn;
		}
		else
		{
			(*Tail)->next=newn;
			newn->Prev=(*Tail);
			(*Tail)=newn;
		}
		(*Tail)->next=*Head;
	    (*Head)->Prev=*Tail;
	    iSize++;
}

void InsertAtPos(PPNODE Head,PPNODE Tail,int iNo,int iPos)
{
	int i=0;
	if((iPos<1)||(iPos>iSize+1))
	{
		printf("Wrong position\n");
		return;
	}

	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=iNo;
	newn->next=NULL;
	newn->Prev=NULL;
	PNODE Temp=*Head;

	if(iPos==1)
	{
		if(*Head==NULL)
		{
			*Head=newn;
			*Tail=newn;
		}
		else
		{
			newn->next=*Head;
		    (*Head)->Prev=newn;
		    *Head=newn;
		}
	}
	else if(iPos==iSize+1)
	{
		if(*Head==NULL)
		{
			*Head=newn;
			*Tail=newn;
		}
		else
		{
			(*Tail)->next=newn;
			newn->Prev=(*Tail);
			(*Tail)=newn;
		}
	}
	else
	{
        for(i=1;i<iPos-1;i++)
        {
           Temp=Temp->next;
        }
        newn->next=Temp->next;
        Temp->next->Prev=newn;
        Temp->next=newn;
        newn->Prev=Temp;
	}
	(*Tail)->next=*Head;
	(*Head)->Prev=*Tail;
	iSize++;
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
    if(*Head==NULL)
    {
    	printf("There is no node\n");
    	return;
    }

    if(*Head==*Tail)
    {
    	free(*Head);
    	(*Head)=NULL;
    	(*Tail)=NULL;
    }
    else
    {
    	(*Head)=(*Head)->next;
    	free((*Head)->Prev);
    	(*Tail)->next=(*Head);
    	(*Head)->Prev=(*Tail);
    }
    iSize--;
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
    if(*Head==NULL)
    {
    	printf("There is no node\n");
    	return;
    }

    if(*Head==*Tail)
    {
    	free(*Head);
    	(*Head)=NULL;
    	(*Tail)=NULL;
    }
    else
    {
    	(*Tail)=(*Tail)->Prev;
    	free((*Head)->Prev);
    	(*Tail)->next=(*Head);
    	(*Head)->Prev=(*Tail);
    }
    iSize--;
}

void DeleteAtPos(PPNODE Head,PPNODE Tail,int iPos)
{
	int i=0;
	PNODE Temp=*Head;
   if((iPos<1)||(iPos>iSize))
   {
   	 printf("Wrong position\n");
   	 return;
   }

   if(iPos==1)
   {
   	   if(*Head==*Tail)
   	  {
   	 	 free(*Head);
   	 	 (*Head)=NULL;
   	 	 (*Tail)=NULL;
   	  }
   	  else
   	  {
   	  	(*Head)=(*Head)->next;
   	  	free((*Tail)->next);
   	  	(*Tail)->next=(*Head);
    	(*Head)->Prev=(*Tail);
   	  }
   }
   else if(iPos==iSize)
   {
   	   if(iSize==1)
   	   {
   	   	  free(*Head);
   	   	  (*Head)=NULL;
   	   	  (*Tail)=NULL;
   	   }
   	   else
   	   {
   	   	   (*Tail)=(*Tail)->Prev;
   	   	   free((*Tail)->next);
   	   	   (*Tail)->next=(*Head);
   	   	   (*Head)->Prev=(*Tail);
   	   }
   }
   else
   {
        for(int i=1;i<iPos-1;i++)
        {
        	Temp=Temp->next;
        }
        Temp->next=Temp->next->next;
        free(Temp->next->Prev);
        Temp->next->Prev=Temp;
   }
   iSize--;
}


void Display(PNODE Head)
{
	int i=1;
	for(i=1;i<=iSize;i++)
	{
		printf("|%d|->",Head->data);
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
	PNODE Last=NULL;
	int iChoice=1,iRet=0,iValue=0,iPos=0;

	while(iChoice!=0)
	{
        printf("Enter your choice\n");
        printf("1 :InsertFirst\n");
        printf("2 :InsertLast\n");
        printf("3 :InsertAtPosition\n");
        printf("4 :DeleteFirst\n");
        printf("5 :DeleteLast\n");
        printf("6 :DeleteAtPosition\n");
        printf("7 :Display\n");
        printf("8 :Count node\n");
        printf("0 :Exit\n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
        	case 1:
        	printf("Enter the number\n");
        	scanf("%d",&iValue);
        	InsertFirst(&First,&Last,iValue);
        	break;

        	case 2:
        	printf("Enter the number\n");
        	scanf("%d",&iValue);
        	InsertLast(&First,&Last,iValue);
        	break;

        	case 3:
        	printf("Enter the number\n");
        	scanf("%d",&iValue);
        	printf("Enter the position\n");
        	scanf("%d",&iPos);
        	InsertAtPos(&First,&Last,iValue,iPos);
        	break;

        	case 4:
        	DeleteFirst(&First,&Last);
        	break;

        	case 5:
        	DeleteLast(&First,&Last);
        	break;

        	case 6:
        	printf("Enter the position\n");
        	scanf("%d",&iPos);
        	DeleteAtPos(&First,&Last,iPos);
        	break;

        	case 7:
        	Display(First);
        	break;

        	case 8:
        	iRet=Count();
        	printf("There are %d Node\n",iRet);
        	break;

            case 0:
            printf("Thanks for using the application\n");
            break;

            default:
            printf("Wrong option\n");
            break;
        }

	}
	return 0;
}