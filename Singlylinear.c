#include <stdio.h>
#include <stdlib.h>


int iSize=0;

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

void InsertFirstNode(PPNODE Head,int no)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;

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


void InsertLastNode(PPNODE Head,int no)
{
    PNODE temp=*Head;
    PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;

    if(*Head==NULL)
    {
        *Head=newn;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    iSize++;
}

int InsertAtPos(PPNODE Head,int no,int iPos)
{
    PNODE temp=*Head;
    PNODE newn=(PNODE)malloc(sizeof(NODE));
    int i=0;

    if((iPos<=0)||(iPos>iSize+1))
    {
       return -1;
    }

    if(iPos==1)
    {
        InsertFirstNode(Head,no);
    }
    else if(iPos==iSize+1)
    {
        InsertLastNode(Head,no);
    }
    else
    {
       newn->data=no;
       newn->next=NULL;

       for(i=1;i<iPos-1;i++)
       {
           temp=temp->next;
       }

       newn->next=temp->next;
       temp->next=newn;
       iSize++;
    }
    return 0;
}

int DeleteFirst(PPNODE Head)
{
    PNODE temp=*Head;
    if(*Head==NULL)
    {
        return -1;
    }

    if((*Head)->next==NULL)
    {
        free(*Head);
        *Head=NULL;
    }
    else
    {
        (*Head)=(*Head)->next;
        free(temp);

    }
    iSize--;
    return 0;
}

int DeleteLast(PPNODE Head)
{
    PNODE temp=*Head;
    if(*Head==NULL)
    {
        return -1;
    }

    if((*Head)->next==NULL)
    {
        free(*Head);
        *Head=NULL;
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;

    }
    iSize--;
    return 0;
}

int DeleteAtPos(PPNODE Head,int iPos)
{
    PNODE temp=*Head;
     PNODE temp2=NULL;
    int i=0;

    if((iPos<=0)||(iPos>iSize))
    {
       return -1;
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
            temp=temp->next;
        }
        temp2=temp->next;
        temp->next=temp->next->next;
        free(temp2);
        iSize--;
    }
    return 0;
}

void Display(PNODE Head)
{
    while(Head!=NULL)
    {
        printf("%d\t",Head->data);
        Head=Head->next;
    }
}

int Count()
{
    return iSize;
}


int main()
{
    PNODE First=NULL;
    int iNo=0,iPos=0,iChoice=1,iRet=0;

    while(iChoice!=0)
    {
        printf("\n1.Insert First\n");
        printf("2.Insert Last\n");
        printf("3.Insert At Position\n");
        printf("4.Delete First\n");
        printf("5.Delete Last\n");
        printf("6:Delete Position\n");
        printf("7.Display\n");
        printf("8.Count Nodes\n");
        printf("0.Exit\n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
            printf("Enter the number\n");
            scanf("%d",&iNo);
            InsertFirstNode(&First,iNo);
            break;

            case 2:
            printf("Enter the number\n");
            scanf("%d",&iNo);
            InsertLastNode(&First,iNo);
            break;

            case 3:
            printf("Enter the number\n");
            scanf("%d",&iNo);
            printf("Enyer the position\n");
            scanf("%d",&iPos);
            iRet=InsertAtPos(&First,iNo,iPos);
            if(iRet==-1)
            {
                printf("Wrong Position\n");
            }
            break;

            case 4:
            iRet=DeleteFirst(&First);
            if(iRet==0)
            {
                printf("Succesfully Deleted\n");
            }
            break;

            case 5:
            iRet=DeleteLast(&First);
            if(iRet==0)
            {
                printf("Succesfully Deleted\n");
            }
            break;

            case 6:
            printf("Enter the position to delete\n");
            scanf("%d",&iPos);
            iRet=DeleteAtPos(&First,iPos);
            if(iRet==-1)
            {
                printf("Wrong Position\n");
            }
            else if(iRet==0)
            {
                printf("Succesfully Deleted\n");
            }
            break;


            case 7:
            Display(First);
            break;

            case 8:
            iRet=Count();
            printf("The Count is: %d\n",iRet);
            break;

            case 0:
            printf("Thanks for using the application\n");
            break;

            default:
            printf("Wrong input\n");
            break;
        }

    }
    return 0;
}