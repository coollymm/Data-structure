/*
 * Leetcode: 25. K 个一组翻转链表
 * tag: LinkList
 * language: C
 * data: 2020/5/16
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


void reverse(struct ListNode **head, struct ListNode **tail) {
    struct ListNode *temp = *head;
    struct ListNode *cur = *head;
    struct ListNode *pre = (*tail)->next;
    struct ListNode *next;
    while(pre != *tail) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    *head = *tail;
    *tail = temp;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if (k == 1) {
        return head;
    }
    //哨兵节点
    struct ListNode *s = malloc(sizeof(struct ListNode));
    struct ListNode *pre = s;
    struct ListNode *next;
    struct ListNode *tail;
    s->next = head;
    while (head != NULL) {
        tail = pre;
        for (int i = 0; i < k; i++) {
            tail = tail->next;
            if (tail == NULL) {
                return s->next;  
            }
        }
        next = tail->next;
        reverse(&head, &tail);
        pre->next = head;
        tail->next = next;
        pre = tail;
        head = next;
    } 
    return s->next;
}

// 使用栈反转
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if (k == 1) {
        return head;
    }
    struct ListNode **stack = malloc(k * sizeof(struct ListNode*));
    struct ListNode before = {0};
    struct ListNode *pre = &before;
    pre->next = head;
    struct ListNode *cur = head;
    while (cur != NULL) {
        int cnt = 0;
        while(cnt < k && cur != NULL) {
            stack[cnt++] = cur;
            cur = cur->next;
        }
        if(cnt != k) {
            break;
        }
        while (cnt > 0) {
            pre->next = stack[--cnt];
            pre = pre->next;
        }
        pre->next = cur;
    }
    free(stack);
    return before.next;
}