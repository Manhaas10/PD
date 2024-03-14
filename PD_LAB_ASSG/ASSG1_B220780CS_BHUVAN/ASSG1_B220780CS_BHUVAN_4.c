
#include <stdio.h>
int fancy(char s[]){
    int largest=1,k;
    for(int i=0;s[i]!='\0';i++){
        int count=0;
        for(int j=0;s[j]!='\0';j++){
            if (s[i]==s[j])
            count++; 
        }
        if (largest<count){
        largest=count;k=i;
        }}
        return s[k];}
int main(){
char s[100];
    gets(s);
char new_s[100];
new_s[0]=s[0];
    static int j=1;
    for(int i=1;s[i]!='\0';i++){
        for(j;j<=((i*i)+3*i)/2;j++){
             new_s[j]=s[i];
             
             }}
    new_s[j]='\0';

   printf("%c",fancy(new_s));
   return 0;

}