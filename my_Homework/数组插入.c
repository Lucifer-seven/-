#include <stdio.h>

int main()
{
    int a;
    int b[6]={1,2,4,5,6,7};
    int c[7]={0};
    int index=6;
    int low=0; //数组左下标
    int high=5; //数组右下标
    int mid;
    int i;
    printf("请输入a的值:\n");
    scanf("%d",&a);
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a>b[mid])
        {
            low=mid+1;
        }
        else if(a<=b[mid])
        {
            index=mid;
            high=mid-1;
        }
    }

    //分三部分赋值，防止越界
    for(i=0;i<index;i++)
    {
        c[i]=b[i];
    }
    c[index]=a;
    for(i=index;i<6;i++)
    {
        c[i+1]=b[i];
    }

    for(i=0;i<7;i++)
    {
        printf("%d ",c[i]);
    }
    printf("\n");

    return 0;
}