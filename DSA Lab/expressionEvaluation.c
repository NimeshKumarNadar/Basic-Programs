#include<stdio.h>
#include<string.h>

char st[100], post[100], s[100];
int op[50];
int top = -1, id = 0 , oid = -1;

void push(int x){
	top ++ ;
	st[top] = x ;
}
int pop (){
	return st[top--];
}
int operand(char x){
	return (x >= '0' && x <= '9');
}
int prec(char x){
	if(x == '*' || x == '/') return 2 ;
	else if(x == '+' || x == '-') return 1 ;
	return 0 ;
}

void main(){	
	int n ;
    clrscr();
	printf("Enter the expression : ");
	scanf("%s", s);
	n = strlen(s);
	push('(');
	s[n] = ')';
	
	for(int i = 0 , j = 0; i <= n; i ++){
		if(operand(s[i])){
			post[id] = s[i];
			id ++ ;
		} else if(s[i] == '('){
			push(s[i]);
		} else if(s[i] != ')') {
			while(prec(st[top]) >= prec(s[i])){
				post[id ++] = pop();
			}	
			push(s[i]);
		} else{
			while(st[top] != '('){
				post[id ++] = pop();
			}
			pop();
		}
	}
		
	for(int i = 0 ; i < strlen(post) ; i ++){
		if(operand(post[i])){
			op[++ oid] = post[i] - '0';
		}else{
			int a = op[oid--] ;
			int b = op[oid--] ;
			if(post[i] == '+') op[++oid] = (b + a);
			if(post[i] == '-') op[++oid] = (b - a);
			if(post[i] == '*') op[++oid] = (b * a);
			if(post[i] == '/') op[++oid] = (b / a);
		}
	}
	printf("Result = %d", op[oid]);
    getch();
}
