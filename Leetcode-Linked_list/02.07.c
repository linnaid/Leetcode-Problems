/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* newNodeA = headA;
    while(newNodeA != NULL)
    {
        struct ListNode* newNodeB = headB;
        while(newNodeB != NULL)
        {
            if(newNodeA == newNodeB)
            return newNodeA;
            newNodeB = newNodeB->next;
        }
        newNodeA = newNodeA->next;
    }
    return NULL;
}