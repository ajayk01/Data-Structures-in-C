#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct node
   {
     struct node *prev;
     char data[40];
     struct node *next;
   }*head=NULL,*temp=NULL,*current1=NULL,*current=NULL,*newhead=NULL;
struct node *create(char string[40])
   {

     current= (struct node*)malloc(sizeof(struct node*));

     strcpy(current->data,string);
     current->next=NULL;
     current->prev=NULL;
     return current;
    }
void insert()
       {
           char song[40];

          printf("Enter the song name\n");
           scanf(" %[^\n]",song);
          current1=create(song);
          if(head==NULL)
               head=current1;
             else
                {
                	
                   current1->next=head;
                   head->prev=current;
                   head=current1;
                   
                 }

          }

void search()
      {
          temp=NULL;
          temp=head;
          char song_name[40];
          scanf(" %[^\n]",song_name);
          if(head==NULL)
            {
               printf("list is not found");
               exit(0);
             }
            temp=head;
           while((temp!=NULL)&&strcmp(temp->data,song_name)!=0)
             {

                temp=temp->next;

              }
         
              if(temp==NULL)

            {
            	printf("The song is not present\n");
            	
              current1=create(song_name);
              if(head==NULL)

               head=current1;
             else
                {
                   current1->next=head;
                   head=current1;
                 }
                 
                printf("The song is added to the listed\n");
             }
             else
                  printf("The song is present\n");

            

         }

void play()
     {
       char song[40];
       temp=NULL;
       printf("Enter the song name\n");
       scanf(" %[^\n]",song);
       if(head==NULL)
            {
               printf("list is not found");
               exit(0);
             }
        temp=head;
       while((temp!=NULL)&&(strcmp(temp->data,song)!=0))

            {
               temp=temp->next;
            }
         
            if(temp==NULL)
         {
           printf("The song is not present\n");
         }
          else
             printf("The previous Song is %s and the next song is %s \n",temp->prev->data,temp->next->data);


    }

void display()
   {
      temp=NULL;
      if(head==NULL)
            {
               printf("list is not found");

             }

          temp=head;
      while(temp!=NULL)
        {
          printf("%s \n",temp->data);
          temp=temp->next;
         }
     }
void reverse()
     {
       temp=NULL;
       if(head==NULL)
            {
               printf("list is not found");

             }

          temp=head;
      while(temp->next!=NULL)
        {
          temp=temp->next;
         }
         
     while(temp!=NULL)
        {
          printf("%s \n",temp->data);
          temp=temp->prev;
         }
         }

void main()
    {
       int a;
        while(1)
        {
          printf("Enter the choices\n 1. insert the song \n 2. search the song and play the song \n 3. search the song and play the previous and next song \n 4 Display the songs  \n 5.exit  ");
          scanf("%d",&a);
         switch(a)
         {
        case 1 : printf(" The entered choice is insert the song\n");
                  insert();
                  break;
        case 2 : printf("The entered choice is search the song and play the song\n ");
                 search();
                 break;
        case 3 : printf("The entered choice is search the song and play the precious and next song\n");
                 play();
                 break;
        case 4 : printf("The entered choice is display the songs\n");
                 display();
                 break;
       case 6  : printf("Thank you"); exit(0);
                 break; 
                 
        case 5 : printf("The entered choice is reverse the songs\n");
                 reverse();
                 break;       
       
      default :  printf("Enter the valid number");

        }
    }
   }
















