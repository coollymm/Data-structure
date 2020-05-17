/*
 * Leetcode: 155. 最小栈
 * tag: stack
 * language: C
 * data: 2020/5/13
 */

typedef struct {
    int *stack;
    int min;
    int capacity;
    int top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *ret = malloc(sizeof(MinStack));
    ret->capacity = 500;
    ret->min = 0;
    ret->top = 0;
    ret->stack = malloc(sizeof(int) * (ret->capacity));
    return ret;
}

void minStackPush(MinStack* obj, int x) {
    int top = obj->top;
    if (top == 0) {
        obj->stack[0] = x;
        obj->top = 1;
        obj->min = x;
        return;
    }
    int old_capacity = obj->capacity;
    if (top >= old_capacity - 1) {
        int *old = obj->stack;
        int new_capacity = 2 * old_capacity;
        int *new = malloc(sizeof(int) * new_capacity);
        for (int i = 0; i < top; i++) {
            new[i] = old[i];
        }
        obj->stack = new;
        obj->capacity = new_capacity;
        free(old);
    }
    int min = obj->min;
    if (x <= min) { 
        obj->stack[obj->top] = min;
        obj->min = x;
        obj->top += 1;
    }
    obj->stack[obj->top] = x;
    obj->top += 1;
    return;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top - 1];
}

void minStackPop(MinStack* obj) {
    if (obj->top == 1) {
        obj->top = 0;
        return;
    }
    if (minStackTop(obj) == obj->min) {
        obj->top -= 1;
        obj->min = minStackTop(obj);
    }
    obj->top -= 1;
    return;
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/