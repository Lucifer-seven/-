#include <stdio.h>
#include "double_linklist_with_head.h"
#include <stdlib.h>

int main()
{
    printf("开始创建双向链表:\n");
    //dnode *head=creat_linklist_with_head();
    dnode *head=creat_linklist_with_head_arc();
    print_linklist_with_head(head);
    printf("节点个数为:%d\n",head->data);

    /*
    //删除数据
    elemtype x;
    printf("请输入想要删除的元素:\n");
    scanf("%d",&x);
    head=delete_double_linklist_with_head(head,x);
    print_linklist_with_head(head);
    printf("节点个数为:%d\n",head->data);
    */

    //销毁链表
    destroy_double_linklist_with_head(head);

    return 0;
}