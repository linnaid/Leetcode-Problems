
typedef struct{
    int *st;
    int stSize;
    int stcapacity;
} Stack;

Stack* creatStack(int capacity)
{
    Stack* stk = (Stack*)malloc(sizeof(Stack));
    stk->st = (int*)malloc(sizeof(int)*capacity);
    stk->stcapacity = capacity;
    stk->stSize = 0;
    return stk;
}

void Stackpush(Stack* stk, int x)
{
    stk->st[stk->stSize] = x;
    stk->stSize++;
}

void Stackpop(Stack* stk)
{
    stk->stSize--;
}

int Stacktop(Stack* stk)
{
    return stk->st[stk->stSize - 1];
}

bool Stackempty(Stack* stk)
{
    if(stk->stSize == 0)
    return true;
    else
    return false;
}

void Stackfree(Stack* stk)
{
    free(stk->st);
}

typedef struct {
    Stack* inStack;
    Stack* outStack;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* stk = malloc(sizeof(MyQueue));
    stk->inStack = creatStack(100);
    stk->outStack = creatStack(100);
    return stk;
}

void myQueuePush(MyQueue* obj, int x) {
    Stackpush(obj->inStack,x);
}

int myQueuePop(MyQueue* obj) {
    if(Stackempty(obj->outStack))
    {
        while(!Stackempty(obj->inStack))
        {
            Stackpush(obj->outStack, Stacktop(obj->inStack));
            Stackpop(obj->inStack);
        }
    }
    Stackpop(obj->outStack);
    return obj->outStack->st[obj->outStack->stSize];

}

int myQueuePeek(MyQueue* obj) {
    if(Stackempty(obj->outStack))
    {
        while(!Stackempty(obj->inStack))
        {
            Stackpush(obj->outStack, Stacktop(obj->inStack));
            Stackpop(obj->inStack);
        }
    }
    return Stacktop(obj->outStack);
}

bool myQueueEmpty(MyQueue* obj) {
    return (Stackempty(obj->outStack) && Stackempty(obj->inStack));
}

void myQueueFree(MyQueue* obj) {
    Stackfree(obj->outStack);
    Stackfree(obj->inStack);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/