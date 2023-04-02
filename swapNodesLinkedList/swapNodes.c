/* Solution for:  
 *   Given a linked list, swap every two adjacent nodes and return its head. 
 *   You must solve the problem without modifying the values in the list's nodes 
 *   (i.e., only nodes themselves may be changed.)
 *   "https://leetcode.com/problems/swap-nodes-in-pairs/" 
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct _Node Node;
struct _Node {
    int val_;
    Node* next_;

};

void consForNode(Node* NN) {
    NN->next_ = NULL;
}

void setNodeVal(Node* NN, int* val) {
    NN->val_ = *val;
}

typedef struct _LinkedList {
    int size_;
    Node* head_;
    Node* tail_;
    
} LinkedList;

void consForLinkedList(LinkedList* LL) {
    Node* NN = (Node*)malloc(1 * sizeof(NN));
    consForNode(NN);
    LL->head_ = NN;
    LL->tail_ = NN;;
    LL->size_ = 0;
}

void addFirstNode(LinkedList* LL, int* val) {
    Node* NN = (Node*)malloc(1 * sizeof(Node));
    consForNode(NN);
    setNodeVal(NN, val);
    if(LL->size_ < 0) {
        return;
    }
    if(LL->size_ == 0) {
        LL->head_ = NN;
        LL->tail_ = NN;
    } else {
        NN->next_ = LL->head_;
        LL->head_ = NN;
    }
    ++LL->size_;
}

void addLastNode(LinkedList* LL, int* val) {
    Node* NN = (Node*)malloc(1 * sizeof(Node));
    Node* MM = (Node*)malloc(1 * sizeof(Node));
    consForNode(NN);
    setNodeVal(NN, val);
    if(LL->size_ < 0) {
        return;
    }
    if(LL->size_ == 0) {
        LL->head_ = NN;
        LL->tail_ = NN;
    } else {
        LL->tail_->next_ = NN;
        LL->tail_ = NN;
    }
    ++LL->size_;
}

Node* getNode(LinkedList* LL, int index) {
    Node* NN = (Node*)malloc(1 * sizeof(Node));
    NN = LL->head_;
    int cnt = 0;
    if(LL->size_ <= 0) {
        return NULL;
    }
    if(index == 0) {
        return NN;
    } else {
        while(cnt != index) {
            NN = NN->next_;
            ++cnt;
        }
        return NN;
    }
}

bool addNode(LinkedList* LL, int index, int* val) {
    Node* NN = (Node*)malloc(1 * sizeof(Node));
    Node* MM = (Node*)malloc(1 * sizeof(Node));
    consForNode(NN);
    setNodeVal(NN, val);
    MM = LL->head_;
    int cnt = 0;
    if(index < 0) {
        return false;
    } else {
        // Add Any Node Case
        MM = getNode(LL, index - 1);
        NN->next_ = MM->next_;
        MM->next_ = NN;
    }
    ++LL->size_;
    return true;
}

void printLinkedList(LinkedList* LL) {
    int kk = 0;
    Node* NN = (Node*)malloc(1 * sizeof(Node));
    if(LL->size_ <= 0) {
        printf("Size Error\n");
        return;
    } else {
        NN = LL->head_;
        int cnt = 0;
        while(NN != NULL) {
            if(++cnt == LL->size_) {
                printf("%d", NN->val_);
            } else {
                printf("%d -> ", NN->val_);
            }
            NN = NN->next_;
        }
        printf("\n");
    }
}

bool eraseNode(LinkedList* LL, int index) {
    Node* NN = (Node*)malloc(1 * sizeof(Node));
    Node* MM = (Node*)malloc(1 * sizeof(Node));
    NN = LL->head_;
    MM = LL->head_;
    int cnt = 0;
    if(index < 0) {
        return false;
    } else {
        if(index == 0) {           
            // Erase First Node Case
            LL->head_ = NN->next_;    
            NN = NULL;
        } 
        else if(index == LL->size_) {
            // Erase Last Node Case
            for(; cnt < LL->size_ - 2; ++cnt) {
                NN = NN->next_;
            }
            NN->next_ = NULL;
            LL->tail_ = NN;
        } else {            
            // Erase Any Node Case
            for(; cnt < index - 1; ++cnt) {
                NN = NN->next_;
            }
            MM = NN->next_;
            NN->next_ = MM->next_;
        }
    }
    --LL->size_;
    return true;
}

void swapNode(LinkedList* LL, int index1, int index2) {
    Node* NN = (Node*)malloc(1 * sizeof(Node));
    Node* MM = (Node*)malloc(1 * sizeof(Node));
    NN = getNode(LL, index1);
    MM = getNode(LL, index2);   

    int exVal = getNode(LL, index2)->val_;
    eraseNode(LL, index2);
    if(index1 == 0) {
        addFirstNode(LL, &exVal);
    } else if(index1 == LL->size_) {
        addLastNode(LL, &exVal);
    } else {
        addNode(LL, index1, &exVal);        
    }
}

void swapNodesSolution(LinkedList* LL) {
    int kk = 0;
    if(LL->size_ == 1) {
        return;
    }

    int SZ = LL->size_ - (LL->size_ % 2);
    for(; kk < SZ; kk+=2) {
        swapNode(LL, kk, kk + 1);
    }
}

void TEST1() {
    printf("***TEST1***\n");
    LinkedList* LL = calloc(1, sizeof(LinkedList));
    consForLinkedList(LL);
    const int SZ = 4;
    int* arr = calloc(SZ, sizeof(int));
    int kk = 0;
    for(; kk < SZ; ++kk) {
        arr[kk] = (SZ - kk);
        addFirstNode(LL, &arr[kk]);
    }

    printLinkedList(LL);
    swapNodesSolution(LL);
    printLinkedList(LL);    
}

void TEST2() {    
    printf("***TEST2***\n");
    LinkedList* LL = calloc(1, sizeof(LinkedList));
    consForLinkedList(LL);
    const int SZ = 1;
    int* arr = calloc(SZ, sizeof(int));
    int kk = 0;
    for(; kk < SZ; ++kk) {
        arr[kk] = (SZ - kk);
        addFirstNode(LL, &arr[kk]);
    }

    printLinkedList(LL);
    swapNodesSolution(LL);
    printLinkedList(LL);    
}

void TEST3() {    
    printf("***TEST3***\n");
    LinkedList* LL = calloc(1, sizeof(LinkedList));
    consForLinkedList(LL);
    const int SZ = 5;
    int* arr = calloc(SZ, sizeof(int));
    int kk = 0;
    for(; kk < SZ; ++kk) {
        arr[kk] = (SZ - kk);
        addFirstNode(LL, &arr[kk]);
    }

    printLinkedList(LL);
    swapNodesSolution(LL);
    printLinkedList(LL);    
}


int main() {
    TEST1();
    TEST2();
    TEST3();

    return 0;
}



