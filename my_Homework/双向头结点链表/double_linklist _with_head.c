#include <stdio.h>
#include "double_linklist_with_head.h"
#include <stdlib.h>

//创建结点函数
dnode *malloc_new_dnode(elemtype num)
{
    dnode *pnew=(dnode *)malloc(sizeof(dnode));
    pnew->data=num;
    pnew->prev=NULL;
    pnew->next=NULL;

    return pnew;
}

//创建双向链表
dnode *creat_linklist_with_head(void)
{
    //创建头结点
    dnode *head=(dnode *)malloc(sizeof(dnode));
    head->data=0;
    head->prev=NULL;
    head->next=NULL;
    dnode *tail=NULL;
    
    printf("请输入数据:\n");
    elemtype num;
    while(1)
    {
        scanf("%d",&num);
        if(num == -1)
        {
            break;
        }
        dnode *pnew=malloc_new_dnode(num);

        //尾插法
        if(head->next == NULL) //第一次链接结点
        {
            head->next=pnew;
            pnew->prev=head;
            tail=pnew; //尾结点更新
            head->data++; //记录结点个数
        }
        else //非第一次链接结点
        {
            tail->next=pnew;
            pnew->prev=tail;
            tail=pnew; //更新尾结点位置
            head->data++; //记录结点个数
        }
    }

    return head;
}

//双向链表打印函数
void *print_linklist_with_head(dnode *head)
{
    if(head == NULL || head->next == NULL)
    {
        printf("链表为空,打印结束!\n");
        return NULL;
    }

    dnode *p=head->next;
    dnode *pre=head;
    //正向打印
    while(p != NULL)
    {
        printf("%d ",p->data);
        pre=p;
        p=p->next;
    }
    printf("\n");
    //反向打印
    while(pre != head)
    {
        printf("%d ",pre->data);
        pre=pre->prev;
    }
    printf("\n");
}

//尾插函数
void tail_linklist_with_head(dnode *head,dnode **tail,dnode *pnew)
{
    if(head->next == NULL) //第一次链接结点
    {
        head->next=pnew;
        pnew->prev=head;
        *tail=pnew; //尾结点的地址更新，指向新的尾部
        head->data++; //记录结点个数
    }
    else //非第一次链接结点
    {
        (*tail)->next=pnew;
        pnew->prev=*tail;
        *tail=pnew; //更新尾结点位置
        head->data++; //记录结点个数
    }
}

//升序双向链表创建函数
dnode *creat_linklist_with_head_arc(void)
{
    elemtype num;
    dnode *head=NULL;
    dnode *tail=NULL;
    /*
    printf("按0创建头结点:\n");
    if(scanf("%d",&num) != 1 || num !=0)
    {
        printf("头结点创建取消!\n");
        return NULL;
    }
    */
    head=malloc_new_dnode(0);

    printf("请输入结点数据(按下-1退出):\n");
    while(1)
    {
        scanf("%d",&num);
        if(num == -1)
        {
            break;
        }
        dnode *pnew=malloc_new_dnode(num);
        if(head->next == NULL) //第一次链接结点，尾插法
        {
            tail_linklist_with_head(head,&tail,pnew);
        }
        else //非第一次链接结点
        {
            dnode *p=head->next; //移动指针
            while(p!=NULL && pnew->data>p->data) //pnew不是最大值,且p的值小于pnew就往下一直找
            {
                p=p->next;
            }
            //退出代表有两种情况
            if(p == NULL) //没找到比pnew大的数据，尾插法
            {
                tail_linklist_with_head(head,&tail,pnew);
            }
            else //pnew在中间某一位置,中间插入
            {
                dnode *temp=p->prev;
                temp->next=pnew;
                pnew->prev=temp;
                pnew->next=p;
                p->prev=pnew;
                head->data++; //记录结点个数
            }
        }
    }

    return head;
}

//删除函数
dnode *delete_double_linklist_with_head(dnode *head,elemtype x)
{
    if(head == NULL)
    {
        printf("错误,链表头结点为空!\n");
        return NULL;
    }
    if(head->next ==NULL)
    {
        printf("链表为空!\n");
        return head;
    }

    dnode *p=head->next;
    dnode *pnext=NULL;
    int count=0; //记录删除数据的个数
    while(p != NULL) //寻找要删除的数据，找到或遍历完后就跳出
    {
        pnext=p->next; //让其保存p的下一个地址，防止断链
        if(p->data == x) //删除目标数据
        {
            p->prev->next=pnext;
            if(pnext != NULL) //判断是不是尾结点，不是就继续操作
            {
                pnext->prev=p->prev;
            }
            free(p);
            p=NULL;
            head->data--; //每删除一个目标数据，结点数就减少一个
            count++;
        }
        p=pnext; //并继续循环找
    }
    if(count == 0) //没有要删除的元素
    {
        printf("没有要删除的元素!\n");
        return head;
    }
    return head;
}

//销毁链表
dnode *destroy_double_linklist_with_head(dnode *head)
{
    if(head == NULL)
    {
        printf("链表本身为空，无需销毁！\n");
        return NULL;
    }
    dnode *p=head->next;
    dnode *pnext=NULL;
    while(p != NULL)
    {
        pnext=p->next;
        free(p);
        p=pnext;
    }
    free(head);
    head=NULL;
    printf("链表销毁成功!\n");

    return NULL;
}