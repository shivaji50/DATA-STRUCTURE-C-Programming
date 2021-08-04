#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int iSize = 0;
typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}NODE,*PNODE,**PPNODE;

void InsertNode(PPNODE Head,int iNo)
{
	PNODE temp = *Head;
	PNODE newn = NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->lchild = NULL;
	newn->rchild = NULL;

	if(*Head == NULL)
	{
		*Head = newn;
		iSize++;
	}
	else
	{
		while(1)
		{
			if(iNo > temp->data)
			{
				if(temp->rchild == NULL)
				{
					temp->rchild = newn;
					iSize++;
					break;
				}
				temp = temp->rchild;
			}
			else if(iNo < temp->data)
			{
				if(temp->lchild == NULL)
				{
					temp->lchild = newn;
					iSize++;
					break;
				}
				temp =temp->lchild;
			}
			else if(iNo == temp->data)
			{
				printf("Dupplicate elememnts\n");
				free(newn);
				break;
			}
		}
	}
}

void Inorder(PNODE Head)    // LDR                  //      21      11      51
{
    if(Head != NULL)
    {
        Inorder(Head->lchild);      // L
        printf("%d\t",Head->data);  // D
        Inorder(Head->rchild);  // R
    }
}

void Preorder(PNODE Head)
{
	if(Head!=NULL)
	{
		printf("%d\t",Head->data);
		Preorder(Head->lchild);
		Preorder(Head->rchild);
		
	}
}

void Postorder(PNODE Head)
{
	if(Head!=NULL)
	{
       Postorder(Head->lchild);
       Postorder(Head->rchild);
       printf("%d\t",Head->data);
	}
}

void Count(PNODE Head,int *i)
{


	if(Head!=NULL)
	{
		(*i)++;
		Count(Head->lchild,i);
		Count(Head->rchild,i);
	}
	
}


void CountParents(PNODE Head,int *i)
{
	if(Head!=NULL)
	{
		if((Head->lchild!=NULL)||(Head->rchild!=NULL))
		{
			(*i)++;			
		}
		CountParents(Head->lchild,i);
		CountParents(Head->rchild,i);
	}
}


void CountLeaf(PNODE Head,int *i)
{
	if(Head!=NULL)
	{
		if((Head->lchild==NULL) && (Head->rchild==NULL))
		{
			(*i)++;
		}
		CountLeaf(Head->lchild,i);
		CountLeaf(Head->rchild,i);
	}
}

bool SearchRecursion(PNODE Head,int iNo)
{
	if(Head!=NULL)
	{
		if(iNo > Head->data)
		{
			return SearchRecursion(Head->rchild,iNo);
		}
		else if(iNo < Head->data)
		{
			return SearchRecursion(Head->lchild,iNo);
		}
		else if(iNo==Head->data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool SearchNormal(PNODE Head,int iNo)
{
	if(Head==NULL)
	{
		return false;
	}
	else
	{
		while(1)
		{
			if(iNo > Head->data)
			{
				if(Head->rchild==NULL)
				{
					break;
				}
				Head=Head->rchild;
			}
			else if(iNo < Head->data)
			{
				if(Head->lchild==NULL)
				{
					break;
				}
				Head=Head->lchild;
			}
			else if(iNo==Head->data)
			{
				break;
			}
		}
	}

	if(iNo==Head->data)
	{
		return true;
	}
	else
	{
		return false;
	}

}



int Globalcount()
{
	return iSize;
}

int main()
{
    PNODE Root = NULL;
    int iChoice = 1, iNo = 0, iRet = 0,i=0;
    while(iChoice != 0)
    {
        printf("Enter your choice\n");
        printf("1 : Insert node\n");
        printf("2 : Display Inorder\n");
        printf("3 : Display Preorder\n");
        printf("4 : Display Postorder\n");
        printf("5 : Searching using Recursion\n");
        printf("6 : Normal Searching\n");
        printf("7 : CountLeaf Node\n");
        printf("8 : CountParents Node\n");
        printf("9 : Count nodes using Recursion\n");
        printf("10 : Global Count\n");
        printf("0 : Terminate the appplication");
        
        scanf("%d",&iChoice);
        
        switch(iChoice)
        {
            case 1 :
                printf("Enter number\n");
                scanf("%d",&iNo);
                InsertNode(&Root,iNo);
                break;
                
            case 2 :
                printf("Inorder traversal\n");
                Inorder(Root);
                printf("\n");
                break;
                
            case 3:
                printf("Preorder traversal\n");
                Preorder(Root);
                printf("\n");
                break;
            
            case 4:
                printf("Postorder traversal\n");
                Postorder(Root);
                printf("\n");
                break;
             

            case 5:
                printf("Enter the number to search\n");
                scanf("%d",&iNo);
                iRet=SearchRecursion(Root,iNo);
                if(iRet==true)
                {
                	printf("%d present in BST\n",iNo);
                }
                else
                {
                	printf("%d Not present in BST\n",iNo);
                }
                break;

            case 6:
                printf("Enter the number to search\n");
                scanf("%d",&iNo);
                iRet=SearchNormal(Root,iNo);
                if(iRet==true)
                {
                	printf("%d present in BST\n",iNo);
                }
                else
                {
                	printf("%d Not present in BST\n",iNo);
                }
                break;


            case 7:
                i=0;
                CountLeaf(Root,&i);
                printf("Number of Leafnodes are : %d\n",i);
                break;


            case 8:
                i=0;
                CountParents(Root,&i);
                printf("Number of Parentsnodes are : %d\n",i);
                break;          

            case 9:
                i=0;
                Count(Root,&i);
                printf("Number of nodes are : %d\n",i);
                break;

            case 10:
                iRet=Globalcount();
                printf("Number of nodes are : %d\n",iRet);
                break;   
                
            case 0:
                printf("Thank you for using appplication\n");
                break;
                
            default:
                printf("Please enter proper choice\n");
                break;
        } //End of switch
    }  // End of while
    return 0;
}   // End of main