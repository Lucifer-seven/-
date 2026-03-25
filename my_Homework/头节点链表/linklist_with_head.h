#ifndef __LINKLIST_WITH_HEAD__
#define __LINKLIST_WITH_HEAD__
typedef int elemtype;
typedef struct node
{
    elemtype data;
    struct node *next;
}node;

node *create_list_with_head(void);
node *printf_list_with_head(node *head);
node *create_list_with_head_arc(void);
node *delete_node(node *head,elemtype x);
node *destroy_list_with_head(node *head);
node *adjustment_list_with_head(node *head);

#endif