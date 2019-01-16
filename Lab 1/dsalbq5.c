#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)

typedef struct node {
	
	int data;

	struct node *nextNode;

}node;

node *head = NULL;

node *createNode(int x)
{
	node *newNode = (node *)malloc(sizeof(node));

	newNode->data = x;

	newNode->nextNode = NULL;

	return newNode;
}

void insert(int x)
{
	if(head==NULL)

		head = createNode(x);

	else{
		node *temp = head;		

		while(temp->nextNode!=NULL)

			temp = temp->nextNode;

		temp->nextNode = createNode(x);

	}
}

void printList(node *head)
{
	node* temp = head;

	while(temp!=NULL)
	{
		printf("%i ",temp->data);

		temp = temp->nextNode;	
	}	

	printf("\n");
}

void search(int x)
{
	node *temp = head;

	int pos =0 ;

	printf("Linked list stored is:\n");

	printList(head);

	printf("Given value stored in the nodes is numbered as:\n");

	while(temp!=NULL)
	{
		if(temp->data == x)
	
			printf("%i ",pos+1);

		temp= temp->nextNode;

		pos++;
	}

	if(!pos) printf(" No node contains given data value");	
	
	printf("\n");
}

void delete(int x)
{
	int count=0;

	node *temp = head;
	
	if(temp == NULL) 
	{	
		printf("No such element present in the list\n"); 
		
		return ; 
	}

	if(temp->data == x) count++;

	while(temp->nextNode!=NULL)
	{
		if(temp->nextNode->data == x)
		
			count++;

		if(count>1)
		{
			node *newTemp = temp->nextNode;

			temp->nextNode = temp->nextNode->nextNode;

			free(newTemp);

			count--;
		}

		else
			temp = temp->nextNode;
	}

	if(!count) printf("No such element present in the list\n");

	else
	{
		printf("Linked list has been updated! New list is:\n");

		printList(head);
	}			
}

void swap(int x)
{
	node* temp = head;

	int count=0;

	while(temp!=NULL)
	{
		if(temp->data ==x)

		{
			if(temp->nextNode!=NULL)
			{
				temp->data = temp->nextNode->data;

				temp->nextNode->data = x;
			}

			count++;			

			break;
		}

		temp = temp->nextNode;
	}

	if(!count) printf("No such element present in the list\n");

	else
	{
		printf("Linked list has been updated! New list is:\n");

		printList(head);
	}
}	

int main()
{
	printf("Enter the elements in the list.Press enter to stop.\n");

	int data; char c;

	do{
		scanf("%d%c",&data,&c);

		insert(data);

	}while(c!='\n');

	int ch,val;

	printf("Choose one of the options:\n1. Search a value in list\n2. Delete occurrences of a value except 1st occurrence\n3. Swap the first occurrence of a value with next element in the list\n");

	do{
		scanf("%i",&ch);

		if(ch==-1) break;

		switch(ch)
		{
			case 1: printf("Enter a value: ");
	
				scanf("%i",&val);
			
				search(val);
	
				break;

			case 2: printf("Enter a value: ");

				scanf("%i",&val);

				delete(val);

				break;

			case 3: printf("Enter a value: ");

				scanf("%i",&val);	
	
				swap(val);
	
				break;
	
			default: printf("Invalid option.\n");
		
				break;

		}

		printf("Choose one of the previous options for more operation or -1 to exit\n");

	}while(ch || ch==0);

	return 0;
}
