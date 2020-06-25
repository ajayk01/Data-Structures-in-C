#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

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
   FILE *fp;
   int i=0,j;
   int flag=0;
   char b;
   char s[50],a;
   fp=fopen("s3.txt","w");
   if(fp==NULL)
    {
      printf("The write file is empty");
      exit(0);
    }
   else 
   {
    while((b=getchar())!='#')
       putc(b,fp);  
   }
  fclose(fp);
  fp=fopen("s3.txt","r");
   if(fp==NULL)
    {
      printf("The read file is empty");
      exit(0);
    }
   else 
   {
     while((b=fgetc(fp))!=EOF)
      {
         printf("%c",b);
       if((b=='(')||(b=='{')||(b=='[')|(b==')')||(a=='}')||(a==']'))
          {
            s[i]=b;
             i++; 
          }
  }
   s[i]='\0';
   printf("The obtain string is ");
     
     puts(s);
 }
 fclose(fp);

     
      	for(i=0;s[i]!='\0';i++)
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
