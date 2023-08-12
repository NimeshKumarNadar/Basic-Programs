#include<stdio.h>
void main(){
    //matrix multiplication
    int r1, r2, c1, c2;
    int i, j, k, sum;
    int mat1[10][10], mat2[10][10], mat3[10][10];
    printf("Please provide the details asked below : \n");
    printf("Rows in matrix A ? ");
    scanf("%d",&r1);
    printf("Columnss in matrix A ? ");
    scanf("%d",&c1);
    printf("Rows in matrix B ? ");
    scanf("%d",&r2);
    printf("COlumns in matrix B ? ");
    scanf("%d",&c2);
    if(c1==r2){
        //inputting the matrices
        printf("Enter elements for the asked positions of both matrices below :\n");
        for(i=0; i<r1; i++){
            for(j=0; j<c1; j++){
                printf("A(%d)(%d) = ",i+1, j+1);
                scanf("%d",&mat1[i][j]);
            }
        }
        for(i=0; i<r2; i++){
            for(j=0; j<c2; j++){
                printf("B(%d)(%d) = ",i+1, j+1);
                scanf("%d",&mat2[i][j]);
            }
        }

        //matrix multiplication
        for(i=0; i<r1; i++){ //this loop helps iterating the rows of first matrix.
            for(j=0; j<c2; j++){ //this loop helps iterating the columns of second matrix.
                sum=0;
                for(k=0; k<r2; k++){
                    /* This loop helps access : 
                    1. each row element of matrix 1
                    2. each column element of matrix 2
                    */
                    sum+=mat1[i][k]*mat2[k][j];
                }
                mat3[i][j]=sum;
            }
        }

        //printing the results
        printf("\nMatrix A :\n");
        for(i=0; i<r1; i++){
            for(j=0; j<c1; j++){
                printf("%d  ",mat1[i][j]);
            }
            printf("\n");
        }
        printf("\nMatrix B :\n");
        for(i=0; i<r2; i++){
            for(j=0; j<c2; j++){
                printf("%d  ",mat2[i][j]);
            }
            printf("\n");
        }
        printf("\nResultant matrix :\n");
        for(i=0; i<r1; i++){
            for(j=0; j<c2; j++){
                printf("%d  ",mat3[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("Matrix multiplication not possible for given dimensions.\n");
    }
}
