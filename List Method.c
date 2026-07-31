#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} List;

void initList(List* l) {
    l->capacity = 2;
    l->size = 0;
    l->data = (int*)malloc(l->capacity * sizeof(int));
}

void resize(List* l) {
    l->capacity *= 2;
    int* newData = (int*)malloc(l->capacity * sizeof(int));
    for (int i = 0; i < l->size; i++) newData[i] = l->data[i];
    free(l->data);
    l->data = newData;
}

void append(List* l, int value) {
    if (l->size == l->capacity) resize(l);
    l->data[l->size++] = value;
}

void insert(List* l, int index, int value) {
    if (index < 0 || index > l->size) return;
    if (l->size == l->capacity) resize(l);
    for (int i = l->size; i > index; i--) l->data[i] = l->data[i - 1];
    l->data[index] = value;
    l->size++;
}

int indexOf(List* l, int value) {
    for (int i = 0; i < l->size; i++) if (l->data[i] == value) return i;
    return -1;
}

void removeValue(List* l, int value) {
    int idx = indexOf(l, value);
    if (idx == -1) return;
    for (int i = idx; i < l->size - 1; i++) l->data[i] = l->data[i + 1];
    l->size--;
}

int pop(List* l, int index) {
    if (index < 0 || index >= l->size) return -1;
    int val = l->data[index];
    for (int i = index; i < l->size - 1; i++) l->data[i] = l->data[i + 1];
    l->size--;
    return val;
}

void reverse(List* l) {
    int left = 0, right = l->size - 1;
    while (left < right) {
        int temp = l->data[left];
        l->data[left] = l->data[right];
        l->data[right] = temp;
        left++; right--;
    }
}

int isEmpty(List* l) { return l->size == 0; }

void printList(List* l) {
    for (int i = 0; i < l->size; i++) printf("%d ", l->data[i]);
    printf("\n");
}

int main() {
    List l;
    initList(&l);
    append(&l, 10); append(&l, 20); append(&l, 30);
    printList(&l);              // 10 20 30

    insert(&l, 1, 15);
    printList(&l);              // 10 15 20 30

    removeValue(&l, 20);
    printList(&l);              // 10 15 30

    int popped = pop(&l, 0);
    printf("Popped: %d\n", popped);
    printList(&l);              // 15 30

    reverse(&l);
    printList(&l);              // 30 15

    printf("Size: %d, Empty: %d\n", l.size, isEmpty(&l));
    free(l.data);
    return 0;
}