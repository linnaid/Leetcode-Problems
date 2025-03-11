/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *h = NULL;
    struct ListNode *t = NULL;
    int add = 0;
    while(l1 || l2)
    {
        int a1 = l1 ? l1->val : 0;
        int a2 = l2 ? l2->val : 0;
        int sum = a1 + a2 + add;
        if(h == NULL)
        {
            h = malloc(sizeof(struct ListNode));
            t = malloc(sizeof(struct ListNode));
            h->val = sum % 10;
            h->next = NULL;
            t = h;
        }
        else
        {
            t->next = malloc(sizeof(struct ListNode));
            t->next->val = sum % 10;
            t->next->next = NULL;
            t = t->next;
        }
        if(l1)
        {
            l1 = l1->next;
        }
        if(l2)
        {
            l2 = l2->next;
        }
        add = sum /10;
        if(add > 0)
        {
            t->next = malloc(sizeof(struct ListNode));
            t->next->val = add;
            t->next->next = NULL;
        }
    }
    return h;
}