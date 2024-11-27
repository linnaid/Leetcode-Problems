/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL)
    {
        return head;
    }
    struct ListNode* newNode = head;
    struct ListNode* newNodeFront = NULL;
    while(newNode->val == val)
    {
        if(newNode->next == NULL)
        return NULL;
        newNode = newNode->next;
        struct ListNode* p = head->next;
        head->next = p->next;
        head = newNode;
    }
    while(newNode != NULL)
    {
        if(newNode->val != val)
        newNodeFront = newNode;
        newNode = newNode->next;
        if(newNode != NULL && newNode->val == val)
        {
            newNodeFront->next = newNode->next;
        }
    }
    return head;
}




