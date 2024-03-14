#include <stdio.h>
int shambles(float* a,float* b){
    float temp=*a;
    *a=*b;
    *b=temp;
}
int divide(float a[],int f,int l){
    float key=a[l];
    int i=f-1;
    for(int j=f;j<l;j++){
        if(a[j]<key){
            i++;
            shambles(&a[i],&a[j]);
        }
    }
    shambles(&a[i+1],&a[l]);
    return i+1;
}
int fast_sort(float a[],int f,int l){
   if(f<l){
    int p=divide(a,f,l);
    fast_sort(a,f,p-1);
    fast_sort(a,p+1,l);    
   }

}
int box_sort(float a[],int n){
    float box[n][n];
    int boxes[n];
    for(int i=0;i<n;i++){
        boxes[i]=0;
    }
    for(int i=0;i<n;i++){
     int k=n*a[i];
       box[k][boxes[k]]=a[i];
       boxes[k]++;
    }
    for(int i=0;i<n;i++){
      if(boxes[i]>0){
       fast_sort(box[i],0,boxes[i]-1);}
    }
    int x=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<boxes[i];j++){
        a[x]=box[i][j];
        x+=1;
        
    } }

}
int main(){
    int n;
    scanf("%d",&n);
       float a[n];
    for(int i=0;i<n;i++){
        scanf("%f",&a[i]);
    }
    box_sort(a,n);
    for(int i=0;i<n;i++){
        printf("%.2f ",a[i]);
    }
   
}