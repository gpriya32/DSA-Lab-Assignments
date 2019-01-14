#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define f(i,a,b) for(ll i=a;i<b;i++)

typedef struct nodeSingly {
	
	int data;

	struct nodeSingly *nextNode;

}nodeSingly;

typedef struct nodeDoubly {
	
	int data;

	struct nodeDoubly *nextNode;

	struct nodeDoubly *prevNode;

}nodeDoubly;

nodeSingly *headSingly = NULL;

nodeDoubly *headDoubly = NULL;

nodeDoubly *rearDoubly = NULL;

nodeDoubly *firstCircular = NULL;

nodeSingly *createNodeSingly(int x)
{
	nodeSingly *newNode = (nodeSingly *)malloc(sizeof(nodeSingly));

	newNode->data = x;

	newNode->nextNode = NULL;

	return newNode;
}

nodeDoubly *createNodeDoubly(int x)
{
	nodeDoubly *newNode = (nodeDoubly *)malloc(sizeof(nodeDoubly));

	newNode->data = x;

	newNode->nextNode = NULL;

	newNode->prevNode = NULL;

	return newNode;
}

nodeDoubly *createNodeCircular(int x)
{
	nodeDoubly *newNode = (nodeDoubly *)malloc(sizeof(nodeDoubly));

	newNode->data = x;

	newNode->nextNode = newNode;
	
	newNode->prevNode = newNode;

	return newNode;
}	

void insertSingly(int x)
{
	if(headSingly==NULL)

		headSingly = createNodeSingly(x);

	else{
		nodeSingly *temp = headSingly;		

		while(temp->nextNode!=NULL)

			temp = temp->nextNode;

		temp->nextNode = createNodeSingly(x);

	}
}

void insertDoubly(int x)
{
	if(headDoubly==NULL)

		headDoubly = rearDoubly = createNodeDoubly(x);

	else{
		rearDoubly->nextNode = createNodeDoubly(x);

		rearDoubly->nextNode->prevNode = rearDoubly;

		rearDoubly = rearDoubly->nextNode;

	}
}

void insertCircular(int x)
{
	if(firstCircular == NULL)

		firstCircular = createNodeCircular(x);

	else{
		nodeDoubly *lastNode = firstCircular->prevNode;

		lastNode->nextNode = createNodeCircular(x);

		lastNode->nextNode->prevNode = lastNode;

		lastNode->nextNode->nextNode = firstCircular;

		firstCircular->prevNode = lastNode->nextNode;
	}	
}

void searchEndDoubly(int k)
{
	nodeDoubly *temp = rearDoubly;

	int cnt =1;

	while(cnt<k)
	{
		if(temp!=NULL)
		{
			temp =  temp->prevNode;

			cnt++; 
		}

		else{
			printf("Value of k exceeds the limit!\n");

			return ;
		}

	}

	printf("Value in Kth node from end in Doubly linked list is: %d\n",temp->data);
}

void searchEndSingly(int k)
{
	nodeSingly *curr = headSingly;

	nodeSingly *prev = NULL;

	nodeSingly *next = NULL;

	while(headSingly !=NULL)
	{
		next = headSingly->nextNode;

		headSingly->nextNode = prev;

		prev = headSingly;

		if(next!=NULL)

			headSingly = next;

		else break;
	}

	nodeSingly *temp = headSingly;

	int cnt =1;

	while(cnt<k)
	{
		if(temp!=NULL)
		{
			temp =  temp->nextNode;

			cnt++; 
		}

		else{
			printf("Value of k exceeds the limit!\n");

			return ;
		}

	}

	printf("Value in Kth node from end in Singly linked list is: %d\n",temp->data);
}

void searchEndCircular(int k)
{
	nodeDoubly *last = firstCircular->prevNode;

	int cnt =1;

	while(cnt<k)
	{
		if(last!=firstCircular)
		{
			last =  last->prevNode;

			cnt++; 
		}

		else{
			printf("Value of k exceeds the limit!\n");

			return ;
		}

	}

	printf("Value in Kth node from end in Circular linked list is: %d\n",last->data);
}

int main()
{
	printf("Enter the elements in the list.Press enter to stop.\n");

	int data; char c;

	do{
		scanf("%d%c",&data,&c);

		insertSingly(data);

		insertDoubly(data);

		insertCircular(data);

	}while(c!='\n');

	int k;

	printf("Enter the node number to be searched from end of the lists: ");

	scanf("%d",&k);

	searchEndSingly(k);

	searchEndDoubly(k);

	searchEndCircular(k);

	return 0;
}
