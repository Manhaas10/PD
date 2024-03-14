#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct treenode {
    char data;
    struct treenode* left;
    struct treenode* right;
};
struct Stack {
    int top;
    struct treenode** arr;
};
typedef struct Stack* stack;
typedef struct treenode* node;
stack is(int size) {
     stack stack =malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->arr = (struct treenode**)malloc(size * sizeof(struct treenode*));
    return stack;
}
void push(stack stack, node node) {
    stack->arr[++stack->top] = node;
}
node pop(stack stack) {
    if (stack->top == -1) {
        return NULL; // Empty stack
    }
    return stack->arr[stack->top--];
}
node create_node(char data){
    node newnode = malloc(sizeof(struct treenode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
int check_n(char ch){
    return (ch>='0' && ch<='9');
}
float convert(char s[]){
    float n=atof(s);
    return n;
}
int isop(char val)
{
  return (val == '+' || val == '-' || val == '*' || val == '/' || val == '^' || val== '%');
}
int check_letter(char ch){ return (ch>='A' && ch<='Z'); }

void In(node node)  
{  
    if ( node == NULL)  
        return ;  
    else  
    {  
        In( node->left ) ;  
  

    printf ( "%c" , node->data) ;  
  
 
    In( node->right ) ;  
    }  
}  
node build_tree(char* s) {
    stack stack = is(strlen(s));

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (check_letter(ch)) {

 
            node numNode = create_node(40);
            numNode->data=ch;
            push(stack, numNode);
        } else if (isop(ch)) {
            node opNode = create_node(ch);
            opNode->right = pop(stack);
            opNode->left = pop(stack);
            push(stack, opNode);
        }
    }
    In(pop(stack));

}


int main(){
    int n;
    scanf("%d",&n);
    char s[n];
    scanf("%s",s);
    build_tree(s);

}