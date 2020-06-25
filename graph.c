#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int ver;
	struct node *next;
}*head,*t,*l;
struct list
{
	int ver1;
	struct node *next1,*graph1;
}*head1,*t1,*l1;
struct node* insert() 
{
	head=NULL;
	int j,f;
	printf("Enter the total no of adj sides \n");
	scanf("%d",&j);
	for(int i=0;i<j;i++)
	{
		printf("Enter the adj vertex\n");
		scanf("%d",&f);
		t=(struct node*)malloc(sizeof(struct node));
		t->ver=f;
		t->next=NULL;
		if(head==NULL)
		 head=t;
		else
		{
		  l=head;
		  while(l->next!=NULL){
  			l=l->next;
  		}
		   
		   l->next=t;
		}
		
	}
	return head;
}
void display()
{
	t1=head1;
	while(t1!=NULL)
	{
		printf("The 1st node is \n %d->",t1->ver1);
		t=t1->next1;
		while(t!=NULL)
		 {
 			printf("%d->",t->ver);
 			t=t->next;
 		}
 		printf("\n");
 	   t1=t1->graph1;
	}
}
void main()
{
	int n,i,a;
	printf("Enter the total no of nodes \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the vertex\n");
		scanf("%d",&a);
		t1=(struct list*)malloc(sizeof(struct list));
		t1->ver1=a;
		t1->graph1=NULL;
		t1->next1 =insert();
		if(head1==NULL)
		head1=t1;
		else 
		{
		  l1=head1;
		  while(l1->graph1!=NULL)
		   l1=l1->graph1;
		   l1->graph1=t1;
		}
	}
	
	display();
}