/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL)
    return NULL;
    struct ListNode* newNode = head;
    struct ListNode* newNodeFront = NULL;
    struct ListNode* newNodeAfter = head->next;
    while(newNodeAfter != NULL)
    {
        newNode->next = newNodeFront;
        newNodeFront = newNode;
        newNode = newNodeAfter;
        newNodeAfter = newNodeAfter->next;
    }
    newNode->next = newNodeFront;
    return newNode;
}