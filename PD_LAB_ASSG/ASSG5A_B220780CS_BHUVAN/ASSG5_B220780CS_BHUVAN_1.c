#include <stdio.h>
void Merge(int a[],int p,int q,int r){
int i,j,k;
int n1=q-p+1;
int n2=r-q;

int l[n1],R[n2];

for(i=0;i<n1;i++){l[i]=a[p+i];}
for(j=0;j<n2;j++){R[j]=a[q+1+j];}
i=0;j=0;
for(k=p;k<=r;k++){
    if(i<n1 && (j>=n2||l[i]<=R[j])){a[k]=l[i];i++;}

else {
    a[k]=R[j];
    j++;
}}}
void Merge_Sort(int a[],int l,int r){
    if (l<r) {
        int m=l+(r-l)/2;
        Merge_Sort(a,l,m);
        Merge_Sort(a,m+1,r);
        Merge(a,l,m,r);
        
    }
}
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ",a[i]);
}
int main(){
    int n;
    scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++){scanf("%d",&a[i]);}
  Merge_Sort(a,0,n-1);

  printArray(a,n);  
}
