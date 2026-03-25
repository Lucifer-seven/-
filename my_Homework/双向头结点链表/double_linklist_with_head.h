#ifndef __DOUBLE_LINKLIST_WITH_HEAD__
#define __DOUBLE_LINKLIST_WITH_HEAD__
typedef int elemtype;
typedef struct dnode
{
    elemtype data;
    struct dnode *prev;
    struct dnode *next;
}dnode;

dnode *malloc_new_dnode(elemtype num);
dnode *creat_linklist_with_head(void);
void *print_linklist_with_head(dnode *head);
void tail_linklist_with_head(dnode *head,dnode **tail,dnode *pnew);
dnode *creat_linklist_with_head_arc(void);
dnode *delete_double_linklist_with_head(dnode *head,elemtype x);
dnode *destroy_double_linklist_with_head(dnode *head);

#endif