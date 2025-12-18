#include<stdio.h>
int main(){
    int n,m;
    int a[20],b[20],c[20];
    printf("Enter the size of first array:\n");
    scanf("%d",&n);
    
    printf("Enter the elements of first array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }  
    printf("Enter the size of second array:\n");
    scanf("%d",&m);
    printf("Enter the elements of first array:\n");
    for(int j=0;j<m;j++){
        scanf("%d",&b[j]);
    }
    int p=n+m;
    for(int i=0;i<n;i++){
        c[i]=a[i];
    }
    for(int i=0;i<p;i++){
        c[i+n]=b[i];
    }   
    printf("The marge array is:\n");
    for(int i=0;i<p;i++){
        printf("%d ",c[i]);
    }
    return 0;
}