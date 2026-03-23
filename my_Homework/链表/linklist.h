#ifndef __LINKLIST_H__
#define __LINKLIST_H__
typedef int elemtype;
typedef struct node
{
    elemtype data;
    struct node *next;
}node;

//函数声明
node* creat_linklist(void);
void printf_linklist(node *head);
node *tail_insert(node *head,elemtype num);
node *head_insert(node *head,elemtype num);
node *add_a_node(node *head,elemtype x,elemtype a);
node *delete_node(node *head,elemtype x);
node *destroy_list(node *head);
int get_node_count(node *head);
node *reverser_list(node *head);

#endif