#include <stdio.h>
#include <stdlib.h>
#include "linklist_with_head.h"

//创建链表函数
node *create_list_with_head(void)
{
    //创建头节点
    node *head=(node *)malloc(sizeof(node));
    head->data=0;
    head->next=NULL;
    node *tail=NULL;
    elemtype num;
    printf("请输入链表数据:\n");
    while(1)
    {
        scanf("%d",&num);
        if(num == -1)
        {
            break;
        }
        node *pnew=(node *)malloc(sizeof(node));
        pnew->data=num;
        pnew->next=NULL;
        if(head->next == NULL) //只有在第一次输入数据时才进行头的连接
        {
            head->next=pnew;
            tail=pnew;
            head->data++;
        }
        else //尾插法
        {
            tail->next=pnew;
            tail=pnew;
            head->data++;
        }
    }

    return head;
}

//打印函数
node *printf_list_with_head(node *head)
{
    node *p=head->next;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

//创建升序带头节点链表函数
node *create_list_with_head_arc(void)
{
    //创建头结点
    node *head=(node *)malloc(sizeof(node));
    head->data=0;
    head->next=NULL;
    node *tail=NULL; //定义一个尾指针

    //输入数据创建结点
    while(1)
    {
        elemtype num;
        scanf("%d",&num); //输入数据
        if(num == -1)
        {
            break;
        }
        node *pnew=(node *)malloc(sizeof(node)); //创建结点
        pnew->data=num;
        pnew->next=NULL;

        //将头结点与数据进行链接(只在第一次时)
        if(head->next == NULL)
        {
            head->next=pnew;
            tail=pnew; //尾指针也指向新数据
            head->data++;
        }
        else //非第一次时分情况讨论
        {
            node *p=head->next; //定义一个移动指针
            node *pre=head;
            while(p!=NULL && (pnew->data)>(p->data)) //当输入的数据比当前数据大就继续找
            {
                pre=p;
                p=p->next; //移动指针继续比较
            }
            //分找到和没找到的情况
            if(p == NULL) //没找到，尾插法
            {
                tail->next=pnew;
                tail=pnew;
                head->data++; //记录结点个数
            }
            else //找到了,中间插
            {
                pre->next=pnew;
                pnew->next=p;
                head->data++; //记录结点个数
            }
        }
    }

    return head;
}

//删除函数
node *delete_node(node *head,elemtype x)
{
    node *p=head->next;
    node *pre=head;
    while(p!=NULL && p->data!=x) //分找到和没找到两种情况
    {
        pre=p;
        p=p->next;
    }
    if(p == NULL) //没找到x
    {
        printf("没有数据%d",x);
        return head;
    }
    else //找到了，遍历全部结点，把所有x都删除
    {
        while(p->next != NULL) //p的下一个不为空就一直找
        {
            //判断当前是否是要删除的元素
            if(p->data == x) //1、是要删除的元素
            {
                node *temp=p; //定义一个临时变量指向p，方便free
                p=p->next;
                pre->next=p;
                free(temp);
                temp=NULL;
                head->data--;       
            }
            else //2、不是要删除的元素
            {
                p=p->next; //指针往后移，并直接进行下一次循环
                continue;
            }
            
        }
    }

    return head;
}

//销毁函数
node *destroy_list_with_head(node *head)
{
    node *p=head;
    node *pre=NULL;
    while(p != NULL)
    {
        pre=p;
        p=p->next;
        free(pre);
        pre=NULL;
    }
    printf("链表已销毁!\n");

    return head;
}

//调整函数
node *adjustment_list_with_head(node *head)
{
    //如果是空链表或者只有头结点那么就不用调整了
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    node *positive_head=NULL; //正数头指针
    node *positive_tail=NULL; //正数尾指针

    node *negative_head=NULL; //负数头指针
    node *negative_tail=NULL; //负数尾指针

    node *p=head->next; //移动指针
    head->next=NULL; //断开链接

    while(p != NULL)
    {
        node *temp=p->next;
        p->next=NULL;
        if(p->data>=0) //遇到非负数
        {
            if(positive_head == NULL) //第一次遇到非负数
            {
                positive_head=p;
                positive_tail=p;
            }
            else //之后的非负数，尾插
            {
                positive_tail->next=p;
                positive_tail=p;
            }
        }
        else //遇到负数
        {
            if(negative_head == NULL) //第一次遇到负数
            {
                negative_head=p;
            } 
            else //之后的负数，尾插
            {
                negative_tail->next=p;
                negative_tail=p;
            }   
        }
        p=temp;
    }

    //开始拼接
    if(negative_head != NULL) //有负数
    {
        head->next=negative_head; //头结点链接负数头部
        negative_tail->next=positive_head; //负数链表尾部链接非负数头部
    }
    else //没有负数
    {
    head->next=positive_head //头结点链接非负数头部
    }

    return head;
}