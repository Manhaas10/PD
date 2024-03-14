#include <stdio.h>
void gearchange(int ace[],int n){
    int monkey;int i=1;
    int j;
    for(;i<n;){
        monkey=ace[i];
        j=i-1;
        while(j>=0 && ace[j]>monkey){
            ace[j+1]=ace[j];
            j--;
        }
        ace[j+1]=monkey;
        i++;
    }
}
int main(){
int n;
scanf("%d",&n);
int luffy[n];
for(int i=0;i<n;i++){scanf("%d",&luffy[i]);}
gearchange(luffy,n);
for(int i=0;i<n;i++){printf("%d ",luffy[i]);}


return 0;
}