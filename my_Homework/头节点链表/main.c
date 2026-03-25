#include <stdio.h>
#include <stdlib.h>
#include "linklist_with_head.h"

int main()
{
    node *head=NULL;
    /*
    printf("开始创建链表:\n")
    head=create_list_with_head();
    */
    printf("开始创建升序链表:\n");
    head=create_list_with_head_arc();
    printf_list_with_head(head);
    printf("创建的结点个数为:%d\n",head->data);

    /*
    //删除数据
    int x;
    printf("请输入想要删除的数据:\n");
    scanf("%d",&x);
    head=delete_node(head,x);
    printf_list_with_head(head);
    */

    //销毁链表
    int is_destroy;
    printf("是否销毁链表？(按1销毁)\n");
    head=scanf("%d",&is_destroy);
    if(is_destroy == 1)
    {
        destroy_list_with_head(head);
    }
    else
    {
        printf("已取消销毁\n");
    }

    return 0;
}