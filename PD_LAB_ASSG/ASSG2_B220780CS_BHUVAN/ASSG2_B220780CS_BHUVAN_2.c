#include <stdio.h>
int xo;
int fax(int a[],int n,int days,int mid){
    int d=1;
    int s=0;
    int i=0;
    int j=0;
    for(;i<n;){
        if((s+a[i])>mid){
            d++;
            s=0;}
        s+=a[i];
        
        i++;}
        xo=d;
    if(d<=days){
        return 1;
    }
    else{return 0;}}
int lazy(int a[],int n,int days){
    int l=0;int r=0;int m;
    for(int i=0;i<n;i++){r+=a[i];}
    for(;l<=r;){
        m=(l+r)/2;
        int ox=fax(a,n,days,m);
        if(xo!=days && ox){
            r=m-1;}
        else if(xo==days){return m;}
        else {
            l=m+1;}}
    }
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    int ace[y];
    for(int i=0;i<y;i++){
        scanf("%d",&ace[i]);}
    printf("%d",lazy(ace,y,x));
    return 1;
}