#include <stdio.h>
#define MAX 5

void addFront(int *arr, int *pfront, int *prear) {
	int i, k, c, item;
	if (*pfront == 0 && *prear == MAX - 1) {
		printf("\nQueue is full.\n");
		return;
	}
  	printf("\nEnter element to insert : ");
  	scanf("%d",&item);
  	if (*pfront == -1) {
    		*pfront = *prear = 0;
    		arr[*pfront] = item;
    		return;
  	}
  	if (*prear != MAX - 1) {
    		c = count(arr);
    		k = *prear + 1;
    		for (i = 1; i <= c; i++) {
     			arr[k] = arr[k - 1];
      			k--;
    		}
    		arr[k] = item;
    		*pfront = k;
    		(*prear)++;
  	} 
	else {
    		(*pfront)--;
    		arr[*pfront] = item;
  	}
}

void addRear(int *arr, int *pfront, int *prear) {
	int i, k, item;
  	if (*pfront == 0 && *prear == MAX - 1) {
    		printf("\nQueue is full.\n");
    		return;
  	}
  	printf("\nEnter element to insert : ");
  	scanf("%d",&item);
  	if (*pfront == -1) {
    		*prear = *pfront = 0;
    		arr[*prear] = item;
    		return;
  	}
  	if (*prear == MAX - 1) {
    		k = *pfront - 1;
    		for (i = *pfront - 1; i < *prear; i++) {
      			k = i;
      			if (k == MAX - 1) arr[k] = 0;
      			else arr[k] = arr[i + 1];
    		}
    		(*prear)--;
    		(*pfront)--;
  	}
  	(*prear)++;
  	arr[*prear] = item;
}

void delFront(int *arr, int *pfront, int *prear) {
	int item;
  	if (*pfront == -1) {
    		printf("\nQueue is empty.\n");
  	}
  	else{
  		item = arr[*pfront];
  		arr[*pfront] = 0;
  		if (*pfront == *prear) *pfront = *prear = -1;
  		else (*pfront)++;
  		printf("\nremoved item: %d", item);
  	}
}

void delRear(int *arr, int *pfront, int *prear) {
	int item;
  	if (*pfront == -1) {
    		printf("\nQueue is empty.\n");
  	}
  	else{
  		item = arr[*prear];
  		arr[*prear] = 0;
  		(*prear)--;
  		if (*prear == -1) *pfront = -1;
  		printf("\nremoved item: %d", item);
  	}
}

void display(int *arr, int *pfront, int *prear) {
	int i;
  	if(*pfront==-1){
		printf("empty");
  	}
  	else{
  		for (i = *pfront; i != *prear+1; i++){
    			if(i==MAX) i=0;
    			printf("  %d", arr[i]);
  		}
  	}
}

int count(int *arr) {
	int c = 0, i;
  	for (i = 0; i < MAX; i++) {
    		if (arr[i] != 0) c++;
  	}
  	if(c==MAX) printf("\nQueue full");
  	return c;
}

void main() {
	int arr[MAX];
  	int front, rear, i, n;
  	int choice=1;
  	clrscr();
  	front = rear = -1;
  	for(i=0; i<MAX; i++) arr[i]=0;
  	printf("\nChoose operation :\n1.Insertion at front\n2.Insertion at rear\n3.Deletion at front\n4.Deletion at end\n5.Display queue\n0.EXIT\n\n");
  	while(choice){
		printf("\n\nEnter choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				addFront(arr, &front, &rear);
				printf("Queue : ");
				display(arr, &front, &rear);
				printf("\nNo. of elements = %d",count(arr));
				break;
			case 2:
				addRear(arr, &front, &rear);
				printf("Queue : ");
				display(arr, &front, &rear);
				printf("\nNo. of elements = %d",count(arr));
				break;
			case 3:
				delFront(arr, &front, &rear);
				printf("\nNo. of elements = %d",count(arr));
				break;
			case 4:
				delRear(arr, &front, &rear);
				printf("\nNo. of elements = %d",count(arr));
				break;
			case 5:
				printf("Queue : ");
				display(arr, &front, &rear);
				printf("\nNo. of elements = %d",count(arr));
				break;
			case 0:
				printf("\nExiting...");
				break;
			default:
				printf("\nInvalid choice");
		}
  	}
  getch();
}
