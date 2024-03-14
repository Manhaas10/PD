#include <stdio.h>
int isfalse(int a,int b){
    if (a>b){return 0;}
    else {return 1;}
    }
int check(int l,int r){
    if (l==r)
    return 1;
    return 0;
}
int boss(int a[],int n){
    int l=0;
    int r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(m<(n-1) && m>0){
            int ans1=isfalse(a[m-1],a[m]);
            int ans2=isfalse(a[m+1],a[m]);
            if(ans1 && ans2){return a[m];}
            else {
                if(a[m-1]>a[m]){r=m-1;}
                if(a[m+1]>a[m]){l=m+1;}}
}
if(m==0 || m==n-1){return a[m];}
}}
int main(){
  int m;
    scanf("%d\n",&m);
    int sanji[m];
    for(int i=0;i<m;i++){
        scanf("%d",&sanji[i]);}
    printf("%d\n",boss(sanji,m));
    return 1;
}