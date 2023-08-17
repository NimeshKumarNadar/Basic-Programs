#include <stdio.h>
#include<conio.h>
#include<string.h>
struct Employee{
  int emp_id;
  char emp_name[25];
  int emp_exp;
  int emp_sal;
};
void sort_id(struct Employee *p,int n){
    int i,j,k;
    struct Employee ptr;
    for(i=1;i<n;i++){
        j=i-1;
        k=p[i].emp_id;
        ptr=p[i];
        while(j>-1&&p[j].emp_id>k){
            p[j+1]=p[j];
	    j--;
	}
        p[j+1]=ptr;
    }
}
void sort_exp(struct Employee *p,int n){
    int i,j,flag=0;
    struct Employee temp;
    for(i=0;i<n-1;i++){
        flag=0;
        for(j=0;j<n-i-1;j++){
	    if(p[j].emp_exp>p[j+1].emp_exp){
		temp=p[j];
		p[j]=p[j+1];
		p[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;

    }
}
void sort_salary(struct Employee *p,int n){
    int i,j,k;
    struct Employee temp;
    for(i=0;i<n-1;i++){
	for(j=k=i;j<n;j++){
	    if(p[k].emp_sal>p[j].emp_sal){
		k=j;
	    }
	}
	temp=p[i];
        p[i]=p[k];
        p[k]=temp;
    }
}
void search_max_sal(struct Employee *p,int n){
    int max=0,i,pos=-1;
    for(i=0;i<n;i++){
        if(p[i].emp_sal>max){
            max=p[i].emp_sal;
            pos=i;
        }
    }
    printf("\nMax Salary Details:");
    printf("\nEmployee ID : %d",p[pos].emp_id);
    printf("\nName : %s",p[pos].emp_name);
    printf("\nExperience : %d",p[pos].emp_exp);
    printf("\nSalary : %d\n\n",p[pos].emp_sal);
}
void search_emp_id(struct Employee *p,int n){
    int key,low,mid,high;
    int pos=-1;
    printf("\nEnter the Employee ID to search for :");
    scanf("%d",&key);
    sort_id(p,n);
    low=0;
    high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(p[mid].emp_id==key){
           pos=mid; 
        }
        if(p[mid].emp_id<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(pos!=-1){
        printf("\nDetails Found:");
        printf("\nEmployee ID:%d",p[pos].emp_id);
        printf("\nEmployee Name:%s",p[pos].emp_name);
        printf("\nEmployee Experience:%d",p[pos].emp_exp);
        printf("\nEmployee Salary:%d\n\n",p[pos].emp_sal);
    }
    else{
        printf("Details not found!\n");
    }
}

void printDetails(struct Employee *p,int n){
    int i;
    for(i=0;i<n;i++){
        printf("\nEmployee ID : %d",p[i].emp_id);
        printf("\nName : %s",p[i].emp_name);
        printf("\nExperience : %d",p[i].emp_exp);
        printf("\nSalary : %d\n\n",p[i].emp_sal);
    }
}
void main() {
    struct Employee emp[10];
    int n,i,j,task;
    char emp_name[25];
    printf("Enter the number of employees : ");
    scanf("%d",&n);
    printf("Enter the details as asked below :\n");
    for(i=0;i<n;i++){
        printf("ID of employee %d : ",i+1);
        scanf("%d",&emp[i].emp_id);
        printf("Name of employee %d : ",i+1);
        fflush(stdin);
        fgets(emp[i].emp_name,25,stdin);
        emp[i].emp_name[strlen(emp[i].emp_name)-1]='\0';
        printf("Experience of employee %d : ",i+1);
        scanf("%d",&emp[i].emp_exp);
        printf("Salary of employee %d : ",i+1);
        scanf("%d",&emp[i].emp_sal);
    }
    do{
        printf("\nSort by :\n1. Employee ID\n2. Experience\n3. Salary\n\nSearch for:\n4. Maximum Salary\n5. Employee ID\n\n0. Exit\n\nChoose task : ");
        scanf("%d",&task);
        switch(task){
            case 1: sort_id(emp,n);
                    printDetails(emp,n);
                break;
            case 2: sort_exp(emp,n);
                    printDetails(emp,n);
                break;
            case 3: sort_salary(emp,n);
                    printDetails(emp,n);
                break;
            case 4: search_max_sal(emp,n);
                    printDetails(emp,n);
                break;
            case 5: search_emp_id(emp,n);
                    printDetails(emp,n);
                break;
        }
    }while(task);
    getch();
}
