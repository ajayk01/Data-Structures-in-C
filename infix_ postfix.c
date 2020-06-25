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
void main()
{
    char exp[20],c,x;
    int i,j;
    printf("Enter the character");
    gets(exp);
    for(i=0;exp[i]!='\0';i++)
         {
         	c=exp[i];
        if(isalnum(c))
            printf("%c",c);
        else if(c == '(')
            push(c);
        else if(c == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(c))
                printf("%c",pop());
            push(c);
        }
    }
    
    while(top!=-1)
    {
        printf("%c",pop());
        j--;
    }
}

    
