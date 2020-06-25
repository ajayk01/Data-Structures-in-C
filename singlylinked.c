#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL,*current,*temp,*newhead,*prev,*t;
void insertfirst()
{
    int x;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter a number\n");
    scanf("%d",&x);
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}
void reverse()
{
    
    if(head==NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        temp=head;
        head=head->next;
        temp->next=NULL;
        newhead=temp;
        while(head!=NULL)
        {
            temp=head;
            head=head->next;
            temp->next=newhead;
            newhead=temp;
        }
        head=newhead;
    }
}
void sort()
{
    int t;
    struct node* i;
    struct node* j;
    for(i=head;i->next!=NULL;i=i->next)
    {
        for(j=i->next;j->next!=NULL;j=j->next)
        {
            if(i->data>j->data)
            {
                t=i->data;
                i->data=j->data;
                j->data=t;
            }
        }
    }
}
void insertmiddle()
{
   int x,y;
     printf("\n enter the number");
     scanf("%d",&y);
     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=y;
     temp->next=NULL;
   if(head==NULL)
   {
     
     head=temp;
   }
   else
   {
     
    t=head;
     if(t->next==NULL)
       {
       	t->next=temp;
       }
     else
       {
     while(t->data!=x && t->next!=NULL)
     {
        t=t->next;
     }
     if(t->next==NULL && t->data!=x)
     {
        printf("\n element is not found in the list\n");
     }
     else
     {
     
	    temp->next=t->next;
        t->next=temp;
     }
   }
  }
}

void insertlast()
{
   int x;
     printf("\n enter the number\n");
     scanf("%d",&x);
     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=x;
     temp->next=NULL;
     t=head;
     while(t->next!=NULL)
     {
       t=t->next;
     }
       t->next=temp;
}

void deletefirst()
{
   if(head==NULL)
      printf("\n Singly Linked List is empty\n");
   else if(head->next==NULL)
     {
     	printf("The list has one node only,  %d",head->data);
     	head=NULL;
     }
     else
     {
      printf("The deleted element is %d",head->data);
      temp=head;
      head=head->next;
      temp->next=NULL;
      free(temp);
     }
}

void deletelast()
{
   if(head==NULL)
      printf("\n Singly Linked List is empty\n");
     
   else
   {
     if(head->next==NULL)
     {
	printf("The deleted element is %d",head->data);
	head=NULL;
     }
     else
     {
     t=head;
     while(t->next!=NULL)
     {
       prev=t;
       t=t->next;
     }
       printf("The deleted element is %d",t->data);
       prev->next=NULL;
       free(temp);
   }
   }
}

void deletemiddle()
{
   int x;
   if(head==NULL)
      printf("\n Singly Linked List is empty\n");
   else
   {
    printf("\n enter the element to be deleted\n");
    scanf("%d",&x);
    t=head;
    while(t->next!=NULL && t->data!=x)
     {
       prev=t;
       t=t->next;
     }
     if(t->next==NULL && t->data!=x)
     {
        printf("\n element is not found in the list\n");
     }
   
     else
     {
        prev->next=t->next;
     }
  }
}

void search(void)
{

    int x,i=0;
    if(head==NULL)
     printf("\n Singly Linked List is empty\n");
   else
   {
    printf("\n enter the element to be searched\n");
    scanf("%d",&x);
    temp=head;
    while(temp!=NULL)
    {
       if(temp->data==x)
       {
	  printf("\n element is found in location %d\n",i+1);
	  break;
       }
       temp=temp->next;
       i=i+1;
    }
    if(temp==NULL)
       printf("\n element is not found\n");
     }
}
void copy()
     {
     	current=NULL;
        current=(struct node*)malloc(sizeof(struct node));
	    temp=head;
	    if(head==NULL)
         {
            printf("list empty");
         }
	    else if(head==rear)
       {
        current->data=temp->data;
        current->next=NULL;
        newhead=current;
        } 
         else 
           {
           	current->data=temp->data;
               current->next=NULL;
               newhead=current;
               temp=temp->next;
               t=newhead;
               while(temp!=head)
                 { 
                    current=(struct node*)malloc(sizeof(struct node));
                    current->data=temp->data;
                    if(1)
                      {
                      	t->next=current;
                      }
                    temp=temp->next;
                 }
                t->next=NULL;
     
           }
         }
         
void display()
{
    
    if(head==NULL)
    {
        printf("\nLinked list is empty\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("\nEnter your choice\n1.Insertbegain \n2.insertmiddle\n3.Insertlast\n4.\n 5. Exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
          case 1:
	             insertfirst();
	              break;
	       case 2:
	             insertmiddle();
	              break;
	       case 3:
	           insertlast();
	           break;
	       case 4:
	          deletefirst();
	           break;
	       case 5:
	          deletemiddle();
	          break;
	       case 6:
	          deletelast();
	          break;
	       case 7:
	           search();
	           break;
	       case 8:
	           display();
	           break;
          case 9:
          	    reverse();
                   break;
          case 10:
          	     sort();
                   break;
          case 11:
          	     copy();
                   break;
          case 12:
          	   printf("Thank you\n") ; exit(0);
                 break;
            default:printf("\nEnter a number between 1 and 5\n");
        }
        
    }
}
    
    
