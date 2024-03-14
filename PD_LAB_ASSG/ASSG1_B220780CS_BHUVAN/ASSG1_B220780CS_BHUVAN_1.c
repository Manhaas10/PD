#include <stdio.h>
#include <string.h>
char blackleg(char sanji){
  if(sanji>=65&&sanji<=90){
     sanji+=32;
     }
     return sanji;
}
int main(){
    int freq=0;
    char character;
    char string[100];
    gets(string);
    scanf("%c",&character);
   char chart=blackleg(character);
   int i=0;
   while(string[i]!='\0'){
         char str=blackleg(string[i]);
        if (str==chart){
        freq+=1;
        }
        i++;
    }
     printf("%d",freq);
     return 0;
   }
