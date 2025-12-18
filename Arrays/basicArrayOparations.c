#include<stdio.h>
int get_index(int a[], int n, int key){
    for(int i=0; i<n; i++){
        if(a[i] == key){
            return i;
        }
    }
    return -1;
}

void set_index(int a[], int n, int index, int value){
    if(index >= 0 && index < n){
        a[index] = value;
    } else{
        printf("\nIndex is invalid.\n");
    }
}

int get_max(int a[], int n){
    int max = a[0];
    for(int i=1; i<n; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    return max;
}

int get_min(int a[], int n){
    int min = a[0];
    for(int i=1; i<n; i++){
        if(a[i] < min){
            min = a[i];
        }
    }
    return min;
}

int sum(int a[], int n){
    int s = 0;
    for(int i=0; i<n; i++){
        s += a[i];
    }
    return s;
}

int main(){
    int n;
    printf("Enter the size of array:\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the element of array:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Array: \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    int g_i;
    printf("\nEnter element to get it's index:\n");
    scanf("%d", &g_i);
    int get = get_index(arr, n, g_i);
    if(get == -1){
        printf("The element not in the array.\n");
    } else {
        printf("Index of the element is %d.\n", get);
    }

    int index, value;
    printf("Enter index and new value:\n");
    scanf("%d %d", &index, &value);
    set_index(arr, n, index, value);
    printf("New Array: \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    
    int max = get_max(arr, n);
    printf("\nMax value: %d\n", max);

    int min = get_min(arr, n);
    printf("Min value: %d\n", min);

    int s = sum(arr, n);
    printf("Sum: %d", s);

    int avg = s / n;
    printf("\nAvarage: %d", avg);


    return 0;
}