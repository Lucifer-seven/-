#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

node* creat_linklist()
{
    node *head=NULL; //定义头指针
    node *tail=NULL; //定义尾指针

    printf("请输入链表数据(按下-1结束输入):\n");
    while(1)
    {
        elemtype num; //要输入的链表数据
        scanf("%d",&num);
        if(num == -1)
        {
            break;
        }
        node *pnew=(node *)malloc(sizeof(node)); //创建一个节点
        pnew->data=num;
        pnew->next=NULL;

        //尾插法
        if(head == NULL) //如果一开始没有数据
        {
            head=pnew; //头尾指针都指向第一个输入的数
            tail=pnew;
        }
        else //如果有数据
        {
            tail->next=pnew; //先将数据进行链接
            tail=pnew; //然后再将尾指针更新到最后
        }
        
    }

    return head;
}

//打印函数
void printf_linklist(node *head)
{
    node *p=head; //创建一个移动指针
    while(p != NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

//尾插法函数
node *tail_insert(node *head,elemtype num)
{
    node *pnew=(node *)malloc(sizeof(node));
    node *tail=head;
    pnew->data=num;
    pnew->next=NULL;
    if(head == NULL)
    {
        head=pnew;
    }
    else
    {
        while(tail->next != NULL) //尾巴不为空就一直找下去
        {
            tail=tail->next;
        }
        tail->next=pnew;
    }

    return head;
}

//头插法函数
node *head_insert(node *head,elemtype num)
{
    node *pnew=(node *)malloc(sizeof(node));
    pnew->data=num;
    pnew->next=NULL;
    if(head == NULL)
    {
        head=pnew;
    }
    else
    {
        pnew->next=head;
        head=pnew;
    }

    return head;
}

/*在链表中查找一个值为x的节点，
在值为x的结点前面添加一个值为a的结点，
如果没有找到x，把a加入到链表的最后，并将新链表返回*/
node *add_a_node(node *head,elemtype x,elemtype a)
{
    node *pnew=(node *)malloc(sizeof(node));
    pnew->data=a;
    pnew->next=NULL;
    node *p=head; //定义一个移动指针
    node *pre=NULL; //这个指针用来保存p指针的上一位
    while(p != NULL) //开始找x,找到后跳出循环
    {
        if(p->data == x)
        {
            break;
        }
        else
        {
            pre=p;
            p=p->next;
        }
    }
    if(p != NULL) //代表找到了x,且p在链表中
    {
        if(p == head) //表示如果x是在开头的情况，头插法
        {
            pnew->next=head;
            head=pnew;
        }
        else //表示x在链表中，,且p代表x的指针，a就往链表里面插
        {
            pnew->next=p; //插在x前面
            pre->next=pnew; //a插入后重新连接前后
        }
    }
    else //没找到x
    {
        pre->next=pnew; //那就再链表结尾插入
    }

    return head;
}

//删除链表节点函数
node *delete_node(node *head,elemtype x)
{
    node *p=head; //移动指针
    node *pre=NULL;
    if(head == NULL)
    {
        printf("链表为空!\n");
        return NULL;
    }
    while(p != NULL && p->data != x)
    {
        pre=p; //pre指向p的前一个
        p=p->next;
    }
    if(p == NULL) //没找到x
    {
        printf("链表中没有节点x!\n");
    }
    //找到了x，分情况讨论
    if(pre == NULL) //当x是头节点
    {
        head=head->next; //头指针往后移
    }
    else //x是中间某个节点
    {
        pre->next=p->next; //链接p的前一个和后一个
    }
    free(p);
    p=NULL;

    return head;
}

//销毁链表函数
node *destroy_list(node *head)
{
    node *temp=NULL;
    while(head != NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
    printf("链表已销毁!\n");

    return NULL;
}

//单链表节点数目函数
int get_node_count(node *head)
{
    elemtype num=0;
    node *p=head;
    while(p != NULL)
    {
        p=p->next;
        num++;
    }

    return num;
}

//逆置单链表
node *reverse_list(node *head)
{
    node *p=head; //移动指针
    node *pre=NULL; //前一个指针
    node *tail=NULL; //后一个指针
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    while(p != NULL)
    {
        tail=p->next; //提前存入下一个节点，防止断链
        p->next=pre; //反转，让下一个节点的指向，指向前一个节点
        pre=p;
        p=tail;
    }
    head=pre;

    return head;
}

//自动创建升序链表
node *create_list_asc(void)
{
    node *head=NULL;
    node *tail=NULL;
    node *p=NULL;
    node *pre=NULL;
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

        if(head == NULL) //第一次输入数据
        {
            head=pnew;
        }
        else
        {
            p=head; //每次输入重置p指针，让其重更新指向头指针
            pre=NULL; //同理
            while(p!=NULL && (pnew->data)>(p->data)) //如果输入的数据大于p的数据就继续循环找
            {
                pre=p; //记录p遍历的前一个节点
                p=p->next;
            }
            //当找到比输入的数据大的就自动跳出循环，并分情况
            if(pre == NULL) //1、p就是头指针，用头插法
            {
                pnew->next=head;
                head=pnew;
            }
            else if(p != NULL) //2、数据在中间
            {
                pre->next=pnew;
                pnew->next=p;
            }
            else //3、输入的数据是最大的，尾插法
            {
                pre->next=pnew;
                pnew->next=NULL;
                tail=pnew;
            }
        }
    }

    return head;
}