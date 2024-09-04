#include<stdio.h>

    int linearsearch(int arr[],int size,int searchvalue)
    {
        for(int i=0;i<size;i++)
        {
            if(arr[i]==searchvalue)
            {
                return i;
            }
           return -1;
        }
    }
    int binarysearch(int arr[],int size,int searchvalue)
    {
        int low=0;
        int high=size-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==searchvalue)
            {
                return mid;
            }
            else if(arr[mid]<searchvalue)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return -1;
    }
    int main()
    {
        int arr[100];
        int size;
        int searchvalue;
        char search;
        printf("enter the size of the array: ");
        scanf("%d", &size);
        printf("enter the elements of the array: ");
        for(int i=0;i<size;i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("enter the value that you want to search: ");
        scanf("%d", &searchvalue);
        printf("enter B if you want to do binary search or enter L if you want to do linear search: ");
        scanf(" %c", &search);
        switch (search)
        {
        case 'B':
            {
                printf("binary search: ");
                int resultB=binarysearch(arr,size,searchvalue);
                if(resultB!=-1)
                {
                    printf("the value is found at: %d",resultB);
                }
                else
                {
                    printf("the value is not found in the input array.");
                }
                break;
            }
        case 'L':
            {
                printf("linear search: ");
                int resultL=linearsearch(arr,size,searchvalue);
                if(resultL!=-1)
                {
                    printf("the value is found at: %d",resultL);
                }
                else
                {
                    printf("the value is not found in the input array.");
                }
                break;
            }
        default:
            {
                printf("invalid input enter 'B' or 'L'\n");
            }
            break;
        }
        return 0;
    }

