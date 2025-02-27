
typedef struct {
    int* que;
    int qTop;
    int qTail;
    int qCapacity;
} Queue;

Queue* creatQueue(int capacity)
{
    Queue* Que = malloc(sizeof(Queue));
    Que->que = malloc(sizeof(int) * capacity);
    Que->qCapacity = capacity;
    Que->qTop = 0;
    Que->qTail = 0;
    return Que;
}

void Queuepush(Queue* obj, int x)
{
    obj->que[(obj->qTail)++] = x;
}

int Queuepop(Queue* obj)
{
    obj->qTop++;
    return obj->que[obj->qTop-1];
}

int Queuepeep(Queue* obj)
{
    return obj->que[obj->qTop];
}

bool Queueempty(Queue* obj)
{
    return (obj->qTail == obj->qTop);
}

void Freequeue(Queue* obj)
{
    free(obj->que);
    obj->que = NULL;
}

typedef struct {
    Queue* queue1;
    Queue* queue2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = malloc(sizeof(MyStack));
    stack->queue1 = creatQueue(100);
    stack->queue2 = creatQueue(100);
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    if(Queueempty(obj->queue1))
    {
        Queuepush(obj->queue1, x);
        while(!Queueempty(obj->queue2))
        {
            Queuepush(obj->queue1,Queuepop(obj->queue2));
        }
    }
    else if(Queueempty(obj->queue2))
    {
        Queuepush(obj->queue2, x);
        while(!Queueempty(obj->queue1))
        {
            Queuepush(obj->queue2,Queuepop(obj->queue1));
        }
    }
}

int myStackPop(MyStack* obj) {
    if(!Queueempty(obj->queue1))
    {
        return Queuepop(obj->queue1);
    }    
        return Queuepop(obj->queue2);
}

int myStackTop(MyStack* obj) {
    if(!Queueempty(obj->queue1))
    {
        return Queuepeep(obj->queue1);
    }    
        return Queuepeep(obj->queue2);
}

bool myStackEmpty(MyStack* obj) {
    return (Queueempty(obj->queue1) && Queueempty(obj->queue2));
}

void myStackFree(MyStack* obj) {
    Freequeue(obj->queue1);
    Freequeue(obj->queue2);
    obj->queue1 = NULL;
    obj->queue2 = NULL;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/