#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
int stack[SIZE];
int top=-1;
void push(int x)
{
	stack[++top]=x;
}
int pop()
{
	return stack[top--];
}
int isempty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void main()
{
	int i=0,x,y;
	char s[20],l,a[2];
        a[1]='\0';
	printf("Enter the expression");
	scanf("%s",s);
	
        while(s[i]!='\0')
           {
              if(isalpha(s[i]))
		{
                        printf("Enter the number");
                        scanf("%d",&x);
                        
			push(x);
		}
		else
		{
			y=pop();
			x=pop();
			if(s[i]=='+')
			{
		          push(x+y);
			}
			if(s[i]=='-')
			{
				 push(x-y);
			}
			if(s[i]=='*')
			{
				 push(x*y);
			}
			if(s[i]=='/')
			{
				 push(x/y);
			}	
			if(s[i]=='^')
			{
				 push(x^y);
			}
			if(s[i]=='%')
			{
				 push(x%y);
			}
		}
		i++;
	}
	printf("The result is=%d",pop());
}
