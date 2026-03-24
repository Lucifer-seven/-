#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int main()
{
    node *head=NULL;
    printf("开始创建链表:\n");
    /*
    head=creat_linklist();
    printf_linklist(head);
    //删除结点
    elemtype x;
    printf("请输入想要删除的节点:\n");
    scanf("%d",&x);
    head=delete_node(head,x);
    printf_linklist(head);
    //销毁链表
    printf("是否销毁链表？(按1进行销毁)\n");
    int is_destroy;
    scanf("%d",&is_destroy);
    if(is_destroy == 1)
    {
        destroy_list(head);
    }
    else
    {
        printf("取消销毁链表\n");
    }
    //逆置链表
    head=reverse_list(head);
    printf_linklist(head);
    */
    head=create_list_asc();
    printf_linklist(head);

    return 0;
}