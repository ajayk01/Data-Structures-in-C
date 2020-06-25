#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct node
   {
     int coff;
     int pow;
     struct node *next;
   }*ad=NULL,*head=NULL,*temp=NULL,*current=NULL,*prev=NULL,*head1=NULL,*temp1=NULL,*current1,*prev1=NULL,*head2=NULL,*temp2=NULL,*current2,*prev2=NULL;
   
struct node *create(int a,int b)
   {

     current=(struct node*)malloc(sizeof(struct node));
     current->coff=a;
     current->pow=b;
     current->next=NULL;
     return current;
    }
    
struct node* insert(struct node *head)
       {
           int c,d;
          printf("Enter the coff and power\n");
           scanf( "%d%d",&c,&d);
           temp= (struct node*)malloc(sizeof(struct node*));
          temp=create(c,d);
          
          if(head==NULL)
               head=temp;
             else
                {
                   prev=head;
                   while(prev->next!=NULL)
                   prev=prev->next;
                   prev->next=temp;
                  
                 }
              return head;
          }
          
void add()
	{
	    temp1=head1;
            temp2=head2;
            
	    while((temp1!=NULL)&&(temp2!=NULL))
	      {
                temp=(struct node*)malloc(sizeof(struct node*));
		if(temp1->pow==temp2->pow)
		  {
		    temp->coff=temp1->coff+temp2->coff;
	    	    temp->pow=temp1->pow;
                    temp1=temp1->next;
                    temp2=temp2->next;  
                  }
                  else if(temp2->pow>temp1->pow)
                       {
                          
                          temp->coff= temp2->coff;
                          temp->pow=temp2->pow;
                          temp2=temp2->next;
                        }
                     else if(temp2->pow<temp1->pow)
                         {
                         
                          temp->coff= temp1->coff;
                          temp->pow=temp1->pow;
                          temp1=temp1->next;
                         }  
                   
                       if(ad==NULL)
                     ad=temp;
                    else
                {
                   current=ad;
                   while(current->next!=NULL)
                    {
                   current=current->next;
                     }
                   current->next=temp;
                  
                 }
                        
                }
	    while((temp1!=NULL)||(temp2!=NULL))
	      {
                temp=(struct node*)malloc(sizeof(struct node*));
                   if(temp1==NULL)
                       printf("poly 1 fully completed");
                      else {
                            temp->coff=temp1->coff;
	    	            temp->pow=temp1->pow;
                          }
                  if(temp2==NULL)
                       printf("poly 2 fully completed");
                      
                       else {
                            temp->coff=temp2->coff;
	    	            temp->pow=temp2->pow;
                          }
                  if(ad==NULL)
                     ad=temp;
                    else
                {
                   current=ad;
                   while(current->next!=NULL)
                    {
                   current=current->next;
                     }
                   current->next=temp;
                  
                 }
           }
      }
      
      
  void sub()
	{
	    temp1=head1;
            temp2=head2;
            
	    while((temp1!=NULL)&&(temp2!=NULL))
	      {
                temp=(struct node*)malloc(sizeof(struct node*));
		if(temp1->pow==temp2->pow)
		  {
		    temp->coff=temp1->coff-temp2->coff;
	    	    temp->pow=temp1->pow;
                    temp1=temp1->next;
                    temp2=temp2->next;  
                  }
                  else if(temp2->pow>temp1->pow)
                       {
                          
                          temp->coff= temp2->coff;
                          temp->pow=temp2->pow;
                          temp2=temp2->next;
                        }
                     else if(temp2->pow<temp1->pow)
                         {
                         
                          temp->coff= temp1->coff;
                          temp->pow=temp1->pow;
                          temp1=temp1->next;
                         }  
                   
                       if(ad==NULL)
                     ad=temp;
                    else
                {
                   current=ad;
                   while(current->next!=NULL)
                    {
                   current=current->next;
                     }
                   current->next=temp;
                  
                 }
                        
                }
	    while((temp1!=NULL)||(temp2!=NULL))
	      {
                temp=(struct node*)malloc(sizeof(struct node*));
                   if(temp1==NULL)
                       printf("poly 1 fully completed");
                      else {
                            temp->coff=temp1->coff;
	    	            temp->pow=temp1->pow;
                          }
                  if(temp2==NULL)
                       printf("poly 2 fully completed");
                      
                       else {
                            temp->coff=temp2->coff;
	    	            temp->pow=temp2->pow;
                          }
                  if(ad==NULL)
                     ad=temp;
                    else
                {
                   current=ad;
                   while(current->next!=NULL)
                    {
                   current=current->next;
                     }
                   current->next=temp;
                  
                 }
           }
      }
       

          
void display(struct node* head)
   {
      if(head==NULL)
            {
               printf("list is not found");

             }

          temp=head;
     
      while(temp!=NULL)
        {
          printf("%d^%d\n",temp->coff,temp->pow);
          temp=temp->next;
         }
     }

void main()
    {
       int a,b;
        while(1)
        {
          printf("Enter the choices\n 1. insert \n2.ADD\n 3.exit 4.display \n ");
          scanf("%d",&a);
         switch(a)
         {
        case 1 : printf(" 1- first poly\n 2-second poly\n");
                 scanf("%d",&b);
                  if(b==1)
 		   {
                 head1=insert(head1);
                  
                   }
	          else
                   {
                  head2=insert(head2);
                  
                    }
                 
                  break;
       case 2 : printf("ADD");
                add();
                display(ad);
                break;
        case 3 : printf("sub");
                sub();
                display(ad);
                break;
       case 5 : printf("Thank you"); exit(0);
                 break; 
         
        case 4 :  printf("first poly\n");
                  display(head1);
                  printf(" second poly\n");
                  display(head2);
                  break;

      default :  printf("Enter the valid number");

        }
    }
   }
















    
