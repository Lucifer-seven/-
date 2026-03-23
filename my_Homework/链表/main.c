#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int main()
{
    node *head=NULL;
    head=creat_linklist();
    printf_linklist(head);

    return 0;
}