#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char stack[20];
int top=-1;
int stack1[20];
int top1=-1;
int sum;
struct node
   {
     struct node *prev;
     char s[30];
     struct node *next;
   }*head=NULL,*temp=NULL,*current=NULL,*t,*head1=NULL,*temp1=NULL,*current1=NULL,*t1,*newhead;
 
 struct node* create()
    {
    	current = (struct node*)malloc(sizeof(struct node));
    	gets(current->s);
    	current->prev=NULL;
    	current->next=NULL;
    	return current;
    }
  void insertlast()
     {
     	
     	temp=create();
     	if(head==NULL)
     	   {
        		head=temp;
        	}
        else
           {
           	t=head;
           	while(t->next!=NULL)
           	{
           		t=t->next;
           	}
           	t->next=temp;
           	temp->prev=t;
            }
     }
    void insertlast1()
     {
     	
     	temp1->prev=NULL;
    	temp1->next=NULL;
     	if(head1==NULL)
     	   {
        		head1=temp1;
        	}
        else
           {
           	t1=head1;
           	while(t1->next!=NULL)
           	{
           		t1=t1->next;
           	}
           	t1->next=temp1;
           	temp1->prev=t1;
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
 void display()
    
    {
    if(head1==NULL)
    {
        printf("\nLinked list is empty\n");
    }
    else
    {
    	printf("\nThe postfix expression is \n");
        t1=head1;
        while(t1!=NULL)
        {
            printf("%s",t1->s);
            t1=t1->next;
        }
    }
  }
  
void push1(int x1)
  {
    stack1[++top1]=x1;
  }
int pop1()
  {
    int e;
    if(top1==-1)
    return 0;
    else
     {
       e=stack1[top1];
       top1--;
       return e;
	 }
  }
void push(char x)
{
    stack[++top]=x;
}
char pop()
{
    if(top==-1)
    return 0;
    else
    return stack[top--];
}
int priority(char x)
{
    if(x=='(')
        return 0;
    if(x=='+'||x=='-')
        return 1;
    if(x=='*'||x=='/')
        return 2;
    if(x=='^')
        return 3;
}
void postfix()
{
   char a[20],c,x;
    int i=0,n,x1;
    printf("Enter the no of character\n");
    scanf("%d",&n);
    printf("Enter the character");
    
    for(i=0;i<=n;i++)
        {
          
      	insertlast();
      }
      t=head;
    while(t!=NULL)
    {
    	printf("%s",t->s);
    	t=t->next;
    }
    }
    void s()
    {
    	
    	char a[20],c,x;
    int i=0,n,x1;
    
      t=head;
    while(t!=NULL)
         {
         	
         	c=t->s[0];
        if(isdigit(c))
        {
            
            temp1= (struct node*)malloc(sizeof(struct node));
            strcpy(temp1->s,t->s);
            insertlast1();
            t=t->next;
        }
        else if(c == '(')
        	{
            push(c);
            t=t->next;
            }
        else if(c == ')')
        {
            while((x = pop()) != '(')
            	{
                
                temp1= (struct node*)malloc(sizeof(struct node));
                a[0]=x;
                a[1]='\0';
                strcpy(temp1->s,a);
                insertlast1();
                }
                t=t->next;
        }
        else
        {
            if(priority(stack[top]) >= priority(c))
              {
                x=pop();
                
                temp1= (struct node*)malloc(sizeof(struct node));
                a[0]=x;
                a[1]='\0';
                strcpy(temp1->s,a);
                insertlast1();
              }
            push(c);
            t=t->next;
        }
    }
    
    while(top!=-1)
    {
        x=pop();
        temp1= (struct node*)malloc(sizeof(struct node));
        a[0]=x;
        a[1]='\0';
        strcpy(temp1->s,a);
        insertlast1();
    }
    //reverse1();
    //display();
}
void reverse1()
{
    
    if(head1==NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        temp=head1;
        head1=head1->next;
        temp->next=NULL;
        newhead=temp;
        while(head1!=NULL)
        {
            temp=head1;
            head1=head1->next;
            temp->next=newhead;
            newhead=temp;
        }
        head1=newhead;
    }
}

void expression()
      {
          char l;
      	int a,b,c,d;
      	//display();
	t1=head1;
	
	
   while(t1!=NULL)
	  {
	    l=t1->s[0];
	 
	    if(isdigit(t1->s[0]))
	      {
	      	d=atoi(t1->s);
	      	
      		push1(d);
      	    	
      	}
		
	      
           else if((l=='+')||(l=='-')||(l=='*')||(l=='/')||(l=='^')||(l=='%'))
		   {
		     a=pop1();
		     b=pop1();
		   
		     if(l=='+')
		      {
			c=a+b;
			push1(c);
			
		      }
		     else if(l=='-')
		      {
			c=a-b;
			push1(c);
			
		      }
             else if(l=='*')
		      {
			c=a*b;
			push1(c);
	
		       }
             else if(l=='/')
		      {
			c=a/b;
			push1(c);
			
		      }
             else if(l=='^')
		      {
			c=pow(a,b);
			push1(c);
			
		      }
             else if(l=='%')
		      {
			c=a%b;
			push1(c);
			
		      }	
		   
		}
		t1=t1->next;
		
       }
    while(top1!=-1)
       sum=pop();
      
  }
  



void main()
   {
   	postfix();
   	//s();
   	//expression();
   	reverse();
   	temp=head;
   	while(temp!=NULL)
   	{
   		
   	
   	
        	
        		if(temp->s[0]==')')
        			temp->s[0]='(';
        		else if(temp->s[0]=='(')
        		     temp->s[0]=')'; 
        	
        temp=temp->next;
        }
   	//display();
   	s();
   	reverse1();
   	display();
   	//printf("%d",sum);
   }

    
    
    
