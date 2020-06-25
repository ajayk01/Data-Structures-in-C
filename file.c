#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void main()
 {
   FILE *fp;
   int i,j;
   char a;
   fp=fopen("s1.txt","w");
   if(fp==NULL)
    {
      printf("The write file is empty");
      exit(0);
    }
   else 
   {
    while((a=getchar())!='#')
       putc(a,fp);  
   }
  fclose(fp);
  fp=fopen("s1.txt","r");
   if(fp==NULL)
    {
      printf("The read file is empty");
      exit(0);
    }
   else 
   {
     while((a=fgetc(fp))!=EOF)
       printf("%c",a);
   }
 fclose(fp);
  
  }
