#include <stdio.h>
void gearchange(float ace[],int n,int k){
    float monkey;int i=1;
    int j;
    int x=0;
    for(;i<n;){
        monkey=ace[i];
        j=i-1;
        while(j>=0 && ace[j]>monkey && x<k){
            ace[j+1]=ace[j];
            j--;
            x++;
        }
        ace[j+1]=monkey;
        i++;
    }
} 
int main(){
int n,q,k;
scanf("%d",&n);
float luffy[n];
for(int i=0;i<n;i++){scanf("%f",&luffy[i]);}
scanf("%d",&q);
scanf("%d",&k);
gearchange(luffy,n,k);
for(int i=0;i<n;i++){printf("%.2f ",luffy[i]);}


return 0;
}