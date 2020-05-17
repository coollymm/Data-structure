/*
 * Leetcode: 102. 二叉树的层序遍历
 * tag: BFS
 * language: C
 * data: 2020/5/13
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    int head;
    int tail;
    int capacity;
    struct TreeNode **queue;
} MyCircularQueue;


/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *Queue = malloc(sizeof(MyCircularQueue));
    Queue->head = 0;
    Queue->tail = 0;
    Queue->capacity = k + 1;
    Queue->queue = (struct TreeNode **) malloc ((k+1) * sizeof(struct TreeNode *));
    return Queue;
}


/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->head == obj->tail;
}


/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->tail + 1) % obj->capacity == obj->head;
}


/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, struct TreeNode *value) {
    if(myCircularQueueIsFull(obj)) {
        return false;
    }
    obj->queue[obj->tail] = value;
    obj->tail = (obj->tail + 1) % obj->capacity;
    return true;
}


/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) {
        return false;
    }
    obj->head = (obj->head + 1) % obj->capacity;
    return true;
}


/** Get the front item from the queue. */
struct TreeNode * myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return NULL;
    }
    return obj->queue[obj->head];
}


/** Get the last item from the queue. */
struct TreeNode * myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return NULL;
    }
    return obj->queue[(obj->tail + obj->capacity - 1) % obj->capacity];  
}


void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    free(obj);
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    // 改进：循环队列长度动态扩展
    int **ret = (int **) malloc(sizeof(int *) * 1000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
    int count = 1;
    int level = 0;
    MyCircularQueue* queue = myCircularQueueCreate(1000);
    myCircularQueueEnQueue(queue, root);
    while(!myCircularQueueIsEmpty(queue)) {
        (*returnColumnSizes)[level] = count;
        ret[level] = (int *) malloc(count * sizeof(int));
        int temp = 0;
        for (int i = 0; i < count; i++) {
            struct TreeNode * cur = myCircularQueueFront(queue);
            ret[level][i] = cur->val;
            if (cur->left != NULL) {
                myCircularQueueEnQueue(queue, cur->left);
                temp++;
            }
            if (cur->right != NULL) {
                myCircularQueueEnQueue(queue, cur->right);
                temp++;
            }
            myCircularQueueDeQueue(queue);
        }
        count = temp;
        level++;
    }
    *returnSize = level;
    myCircularQueueFree(queue);
    return ret;
}