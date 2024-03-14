#include <stdio.h>
#include <stdlib.h>

struct treenode{
    int key;
    struct treenode* left;
    struct treenode* right;
};

typedef struct treenode* node;
node create_node(int key){
    node node=malloc(sizeof(struct treenode));
    node ->key=key;
    node->left=NULL;
    node->right=NULL;
    return node;
}
node in(node root,int k){
    node temp=create_node(k);
    if(root==NULL) return create_node(k);
    if(k<root->key) root->left=in(root->left,k);
    else root->right=in(root->right,k);
    return root;
}
node mini(node root){
    if(!root) return NULL;
    while(root->left) root=root->left;
    return root;
}
// node del(node root,int k){
//     if(!root)return NULL;
//     if(root->key>k) root->left=del(root->left,k);
    
//     else if(root->key<k) root->right=del(root->right,k);
//     else{
//         if(!root->right){
//             node temp=root->left;
//             free(root);
//             return temp;
//         }
//          if(!root->left){
//             node temp=root->right;
//             free(root);
//             return temp;
//         }
//         node temp=mini(root->right);
//         root->key=temp->key;
//         root->right=del(root->right,root->key);
//     }
//     return root;
// }
void print(node root){
    if(!root){
        printf("( ) ");
        return;
    }
    printf("( %d ",root->key);
    print(root->left);
    print(root->right);
    printf(") ");
}
int main(){
    int k;
    char ch;
    node root=NULL;
    
    while(ch!='e'){
        scanf(" %c",&ch);
        switch(ch){
            case 'i':
             scanf("%d",&k);
             root=in(root,k);
             break;
            case 'p':
             print(root);
             printf("\n");
             break;

        }
    }
}
