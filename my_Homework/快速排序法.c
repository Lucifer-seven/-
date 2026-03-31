#include <stdio.h>

/*
    @arr[]   需要排序的数组
    @left    左指针
    @rihght  右指针
*/
void quick_sort(int arr[],int left,int right) //快速排序函数
{
    int pivot=arr[left]; //基准参数
    int L=left;
    int R=right;
    if(L>=R)
    {
        return;
    }
    while(L<R)
    {
        //右边的数比pivot大就继续往前找
        while(L<R && arr[R]>pivot) 
        {
            R--; //右指针向前移
        }
        //发现比pivot小的数就跳出循环
        if(L<R)
        {
            arr[L]=arr[R];
            L++;
        }
        //左边的数比pivot小就继续往后找
        while(L<R && arr[L]<=pivot)
        {
            L++; //左指针向后移
        }
        //发现比pivot大的数就跳出循环
        if(L<R)
        {
            arr[R]=arr[L];
            R--;
        }
    }
    //递归
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