#include<stdio.h>
#include<conio.h>
#include<string.h>
char stack[20];
int top=-1;
void push(int x)
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
void main()
      {
      	char s[50],a;
      	int i,flag=0;
      	printf("Enter the expression\n");
      	gets(s);
      	for(i=0;s[i]!=NULL;i++)
      	    {
          		a=s[i];
          		if((a=='(')||(a=='{')||(a=='['))
          			push(a);
          			else if((a==')')||(a=='}')||(a==']'))
          			   if(top==-1)
          			      {
          			      printf("unbalanced parathesis"); 
          			      exit(0);
          			      }
          			      else if(a==')')
                     				if(stack[top]=='(')
                     					{
                     					top--;	
                     					flag=1;
                     					}
                     				else 
                     				   flag=0;
                     	    else if(a=='}')
                     				if(stack[top]=='{')
                     				  		{
                     					top--;		
                     					flag=1;
                     					}
                     				else 
                     				   flag=0;
                     	    else if(a==']')
                     				if(stack[top]=='[')
                     				  		{
                     					top--;		
                     					flag=1;
                     					}
                     				else 
                     				   flag=0;  
                     		
          	        }
          	       if(top==-1)
          	         flag=1;
          	          else
          	            flag=0;
          	         	
          	if(flag==0)
                       printf("unbalanced parathesis");
                        else  
                             printf("balanced parathesis");             
      }
