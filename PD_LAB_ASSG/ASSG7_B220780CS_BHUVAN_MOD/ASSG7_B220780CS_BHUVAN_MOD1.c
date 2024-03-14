#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack{
    int top;
    int size;
    char* a;
};
typedef struct stack* stack;
stack create_stack(int n){
    if(n==0) return NULL;
    stack stack=malloc(sizeof(struct stack));
    stack->size=n;
    stack->a=(char*)malloc(n*sizeof(char));
    stack->top=-1;
    return stack;
}
int isempty(stack stack){ return stack->top==-1;}
int isfull(stack stack){ return stack->top==stack->size-1; }

char peek(stack stack){
    if(isempty(stack))return -1; 
    return stack->a[stack->top];
}
void push(stack stack,char o){
    if(isfull(stack)){return;}
    stack->a[++stack->top]=o;
}
char pop(stack stack){
    if(isempty(stack))return-1;
    return stack->a[stack->top--];
}

int check_letter(char ch){ return (ch>='A' && ch<='Z') || (ch>='a' && ch<='z'); }

int pre(char ch){
    if(ch=='+' || ch== '-') return 9;
    else if(ch=='%' || ch=='#') return 10;
    else if(ch== '*' || ch== '/')return 7;
    else if(ch=='^')return 6;
    else return -1;
}

int isop(char val)
{
  if (val == '+' || val == '-' || val == '*' || val == '/' || val == '^' || val=='%' || val=='#') return 1;
   else return 0;
}
int check_n(char v){
    return (v>='0' && v <='9');
}

int main(){
    //int n;
    //scanf("%d",&n);
    char s[40];
    stack stack=create_stack(40);
    char ch; int j=0; char a[40]; int i;
    fgets(s,sizeof(s),stdin);
    for( i=0;s[i]!='\0';i++){
        ch=s[i];
        if(check_letter(s[i]) || check_n(s[i])) {a[j++]=s[i];}
        else if(s[i]=='(') {push(stack,s[i]);}

        else if(s[i]==')'){
            while(!isempty(stack) && peek(stack)!='(') {a[j++]=pop(stack);}
            
            if(!isempty(stack) && peek(stack)=='(')
            pop(stack);}

        else if(isop(s[i])){
            while(!isempty(stack) && peek(stack)!='(' && pre(s[i])<=pre(peek(stack)) ) { a[j++]=pop(stack); }
            push(stack,s[i]);//printf(" %c ",ch);
        }
    }
    for(int i=0;i<j;i++){ printf("%c ",a[i]);}
    
    while(!isempty(stack)){ printf("%c ",pop(stack)); }
return 1;
}