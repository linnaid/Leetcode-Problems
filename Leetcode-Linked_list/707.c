typedef struct MyLinkedList{
    int val;
    struct MyLinkedList* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* head = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    head->next = NULL;
    return head;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(obj->next == NULL || obj == NULL)
    return -1;
    MyLinkedList* newNode = obj->next;
    if (index < 0 ) 
		return -1;
    int n = 0;
    while(1)
    {
        if(n == index)
        {
            return newNode->val;
        }
        if(newNode->next == NULL)
        {
            return -1;
        }
        newNode = newNode->next;
        n++;
    }
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* head = (MyLinkedList*)malloc(sizeof(MyLinkedList)) ;
    head->next = NULL;
    head->val = val;
    if(obj->next == NULL)
    obj->next = head;
    else
    {
        head->next = obj->next;
        obj->next = head;
    }
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* newNode = obj;
    while(newNode->next != NULL)
    {
        newNode = newNode->next;
    }
    MyLinkedList* newNodeAfter = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    newNodeAfter->val = val;
    newNodeAfter->next = NULL;
    newNode->next = newNodeAfter;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList* newNode = obj;
    MyLinkedList* newNodeFront = NULL;
    if(myLinkedListGet(obj,index) == -1)
    {
        int n = 0;
        while(newNode != NULL)
        {
            newNodeFront = newNode;
            newNode = newNode->next;
            n++;
        }
        if(n-1 == index)
        {
            MyLinkedList* p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
            p->next = NULL;
            p->val = val;
            newNodeFront->next = p;
        }
        else
        return;
    }
    else
    {
        int n = 0;
        while(newNode != NULL)
        {
            newNodeFront = newNode;
            newNode = newNode->next;
            n++;
            if(n-1 == index)
            break;
        }
        MyLinkedList* p = (MyLinkedList*)malloc(sizeof(MyLinkedList));
        p->next = NULL;
        if(newNode != NULL)
        p->next = newNode;
        newNodeFront->next = p;
        p->val = val;
    }

}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList* newNode = obj;
    MyLinkedList* newNodeFront = NULL;
    if(myLinkedListGet(obj,index) == -1)
    {
        return;
    }
    else
    {
        int n = 0;
        while(1)
        {
            newNodeFront = newNode;
            newNode = newNode->next;
            n++;
            if(n-1 == index)
            break;
        }
        if(newNode->next != NULL)
        {
            newNodeFront->next = newNode->next;
            free(newNode);
        } 
        else
        newNodeFront->next = NULL;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
