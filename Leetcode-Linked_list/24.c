/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL)
    return NULL;
    struct ListNode m;
    m.next = head;
    struct ListNode* p = &m;
    while(p->next != NULL && p->next->next != NULL)
    {
        struct ListNode* newNode = p->next;
        struct ListNode* newNodeAfter = newNode->next;
        newNode->next = newNodeAfter->next;
        p->next = newNodeAfter;
        newNodeAfter->next = newNode;
        p = newNode;
    }
    return m.next;
}