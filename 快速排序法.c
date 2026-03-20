#include <stdio.h>

void quick_sort(int arr[],int left,int right)
{
    int pivot=arr[left];
    int L=left;
    int R=right;
    if(L>=R)
    {
        return;
    }
    while(L<R)
    {
        while(L<R && arr[R]>pivot)
        {
            R--;
        }
        if(L<R)
        {
            arr[L]=arr[R];
            L++;
        }
        while(L<R && arr[L]<=pivot)
        {
            L++;
        }
        if(L<R)
        {
            arr[R]=arr[L];
            R--;
        }
    }
    arr[L]=pivot;
    quick_sort(arr,left,L-1);
    quick_sort(arr,L+1,right);
}

int main()
{
    int a[5];
    int i;
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    quick_sort(a,0,4);
    for(i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}