#include<stdio.h>
void main(){
    int i, j, n, n1, n2, sum;
    unsigned int dist, temp;
    int arr[10];
    printf("Enter 10 elements to perform operations :\n");
    for(i=0; i<10; i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the target number : ");
    scanf("%d",&n);
    
    dist = (arr[0]+arr[1])-n;
    n1 = arr[0];
    n2 = arr[1];
    sum = n1 + n2;
    for(i=0; i<10; i++){
        for(j=1; j<10; j++){
            if(i==j)
                continue;
            temp = (arr[i]+arr[j])-n;
            if(temp < dist){
                dist = temp;
                n1 = arr[i];
                n2 = arr[j];
                sum = n1 + n2;
            }
        }
    }
    printf("The sum %d of elements %d and %d is closest to %d with distance %d", sum, n1, n2, n, dist);
}