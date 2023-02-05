//
//  function.h
//  10947 - delete linked list
//
//  Created by Brian on 2023/2/3.
//

#ifndef function_h
#define function_h

#include <stdlib.h>
#include <stdio.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void deleteNode(Node ** head, int data) {
    if(data == 1) {
        *head = (*head)->next;
        return;
    }
    Node *pre = NULL, *now = *head;
    data--;
    while(now != NULL && data--) {
        pre = now;
        now = now->next;
    }
    if(now != NULL) pre->next = now->next;
    free(now);
}

Node* createList(void) {
    Node *head, *tmp, *tail;
    int val;
    tmp = (Node*)malloc(sizeof(Node));
    scanf("%d", &val);
    tmp->data = val;
    tmp->next = NULL;
    head = tail = tmp;
    while(scanf("%d", &val) && val!= -1) {
        tmp = (Node*)malloc(sizeof(Node));
        tmp->data = val;
        tmp->next = NULL;
        tail->next = tmp;
        tail = tail->next;
    }
    return head;
}

#endif /* function_h */
