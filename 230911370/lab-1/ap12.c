#include<stdio.h>
//binary search
int binarysearch(int arr[],int low, int high,int target)
{
    if(low>high)
    {
        return -1;
    }
        int mid=(high+low)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]>target)
            return binarysearch(arr,low,mid-1,target);
        else
            return binarysearch(arr,mid+1,high,target);
}
//Selection Sort
void selectionSort(int arrA[], int start, int end) {
    if (start >= end)
        return;
    int minIndex = start;
    for (int i = start + 1; i <= end; i++) {
        if (arrA[i] < arrA[minIndex])
            minIndex = i;
    }
    int temp = arrA[start];
    arrA[start] = arrA[minIndex];
    arrA[minIndex] = temp;
    selectionSort(arrA, start + 1, end);
}
// Multiply using Repeated Addition
int multiply(int a, int b) {
    if (b == 0)
        return 0;
    else
        return a + multiply(a, b - 1);
}
int main()
{
    //i.binary seach
    int arr[100],n;
    int target;
    printf("enter the size of array for binary search: ");
    scanf("%d", &n);
    printf("enter the elements of the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter the value to be searched: ");
    scanf("%d", &target);
    int low=0,high=n-1;
    int result=binarysearch(arr,low,high,target);
    if(result!=-1){
        printf("the value is found at index arr[%d] \n",result);}
    else{
        printf("the value is not found in the input array.");}

    //ii.selection sort
    int arrA[100],start,nA,end;
     printf("enter the size of array for selection sort: ");
    scanf("%d", &nA);
    printf("enter the elements of the array: ");
    for(int i=0;i<nA;i++)
    {
        scanf("%d", &arrA[i]);
    }
    selectionSort(arrA,0,nA-1);
    printf("the sorted array is: ");
    for(int i=0;i<nA;i++)
    {
        printf("%d ", arrA[i]);
    }

    //multiplying repeatedly
    int a,b;
    printf("enter the value of a: \n");
    scanf("%d", &a);
    printf("enter the value of b: \n");
    scanf("%d", &b);
    printf("the value of axb is: ");
    printf("%d", multiply(a,b));
    return 0;
}


