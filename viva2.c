#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct game
{
    int player;
    struct game *next,*pre;
}*head=NULL,*temp,*t,*last;
struct game* create()
{
    int n;
    
    temp=(struct game*)malloc(sizeof(struct game));
    printf("\n Enter the player num");
    scanf("%d",&n);
    temp->player=n;
    temp->next=NULL;
    temp->pre=NULL;
    return temp;
};
void insert(int n)
{
    int i;
    
    for(i=0;i<n;i++)
    {
        t=create();
        if(head==NULL)
        {
            head=t;
            head->pre=t;
            head->next=t;
        }
        else
        {
            last=head->pre;
            t->next=head;
            head->pre=t;
            t->pre=last;
            last->next=t;
        }
    }
}

void game(int n)
{
 
    int m,i;
    temp=head;
    printf("\n No of pass");
    scanf("%d",&m);
    while(n!=1)
    {
        for(i=1;i<=m;i++)
        {
            temp=temp->next;
        }
        t=temp->next;
        t->pre=temp->pre;
        t=temp->pre;
        t->next=temp->next;
        temp=temp->next;
        n--;
    }
    printf("The winner is %d",temp->player);
}
void main()
{
   	int n;
       printf("\n Enter number of players");
       scanf("%d",&n);
       insert(n);
       game(n);
}
