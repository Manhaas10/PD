#include <stdio.h>
int missing(int a[],int n,int k){
    int l=0;
    int r=n-1;
    int q;
    if (k<a[0]){return k;}
    if (a[0]!=1){k=k-a[0]+1;}
    for(;l<=r;){
        int m=(r+l)/2;
        q=a[m]-m-a[0];
        (k<=q)?(r=m-1):(l=m+1);}
    if(r>=0 && l<=n-1){return a[r]+k-(a[r]-a[0]-r);}
    else{return -1;}
    }
int main(){
    int s,m;
    scanf("%d\n",&s);
    int zoro[s];
    for(int i=0;i<s;i++){
        scanf("%d ",&zoro[i]);}
    scanf("%d",&m);
printf("%d",missing(zoro,s,m));
return 1;
}