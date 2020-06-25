#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int priority;
    char name[100];
    struct node *next;
}*head=NULL,*temp=NULL,*prev=NULL,*t=NULL,*rear;
void insert()
{
    int x;
    char a[100];
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the Vehicle Type😐️\n");
    scanf("%s",a);
    printf("\nEnter the priority🤔️\n");
    scanf("%d",&x);
    
    temp->priority=x;
    strcpy(temp->name,a);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        rear=temp;
    }
    else if(head->next==NULL)
    {
       if(head->priority < temp->priority)
         {
           head->next=temp;
           rear=temp;
         }
       else 
         {
           temp->next=head;
           rear=head;
           head=temp;
         }
    }
    else
    {   
        t=head;
        prev=NULL;
        while(t!=NULL && t->priority < temp->priority)
         { 
              prev=t;
              t=t->next;
         }
         if(t==head)
         {
         temp->next=t;
         head=temp;
         }
         else if(t!=NULL)
         {
         temp->next=t;
         prev->next=temp;
	 }
         else
         {
         temp->next=t;
         prev->next=temp;
         rear=temp;
         }         
    }
}
 void display()
{
	temp=head;
	
    
    while(temp!=NULL)
    {
        printf(" The Vehicle Type😌️ :%s \n The priority is🙃️ : %d\n",temp->name,temp->priority);
        temp=temp->next;
        
    }
    
}
void gethigh()
  {
    printf("The highest priority is😌️%d \n The vechical name is🙃️ %s",head->priority,head->name);
  }
void deletehigh()
  {
    printf("The deleted highest priority is😫️%d \n The vechical name is😒️ %s",head->priority,head->name);
  temp=head;
  head=head->next;
  temp->next=NULL;
 }

void main()
  {
  	 int n,ch;
	 while(1)
       {
  	 printf("\nEnter the choice 🤔️ \n1.Insert☺️ \n 2.Display🤗️ \n 3.Get the hightest priority🤑️\n4.Delete hightest priority😏️\n");
  	 scanf("%d",&ch);
	 switch(ch)
	 {         
  	  case 1 :  printf("Enter the no of request🙁️\n");
  	            scanf("%d",&n);
  	            for(int j=0;j<n;j++)
  	            insert();
		    break;
         case 2 :   display();
		    break;
	 case 3 :   gethigh();
		    break;
         case 4 :   deletehigh();
		    break;
         case 5 :   printf(" 😀️ Thank you 😇️");
		    exit(0);
		    break;
         default : printf("Enter the valid number🤨️");
        }
    
     }
   }
    
    
     
    
