#include <stdio.h>
void zoro(int* luffy,int* usopp){
int temp;
temp=*usopp;
*usopp=*luffy;
*luffy=temp;
}
void sanji(int a[],int n){
    int nami;
    for(int i=0;i<n;i++){
        int vivi=i;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[vivi]){
                vivi=j;
            }
        }
        if(vivi!=i){zoro(&a[vivi],&a[i]);}
    }
}
int main(){
    int N;
    scanf("%d",&N);
    int a[N];
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    sanji(a,N);
    for(int i=1;i<=N;i++){
        printf("%d ",a[i-1]);
    }
    return 0;

}