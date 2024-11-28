/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int num = 0;
    struct ListNode* newNode = head;
    while(newNode != NULL)
    {
        newNode = newNode->next;
        num++;
    }
    printf("%d\n",num);
    newNode = head;
    int i = 1;
    if(num == n)
    return head->next;
    while(i < num-n)
    {
        newNode = newNode->next;
        i++;
    }
    printf("%d %d\n",i,newNode->val);
    if(newNode->next != NULL)
    {
        struct ListNode* p = newNode->next;
        newNode->next = p->next;
    }
    return head;
}