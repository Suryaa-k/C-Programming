#include <stdio.h>
#define CAPACITY 10

int list[CAPACITY];
int size = 0;

void insert(int index, int value) {
    if (size >= CAPACITY || index < 0 || index > size) return;
    for (int i = size; i > index; i--) {
        list[i] = list[i - 1];
    }
    list[index] = value;
    size++;
}

void deleteAt(int index) {
    if (index < 0 || index >= size) return;
    for (int i = index; i < size - 1; i++) {
        list[i] = list[i + 1];
    }
    size--;
}

int search(int value) {
    for (int i = 0; i < size; i++) {
        if (list[i] == value) return i;
    }
    return -1;
}

void update(int index, int value) {
    if (index < 0 || index >= size) return;
    list[index] = value;
}

void traverse() {
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    insert(0, 10);
    insert(1, 20);
    insert(2, 30);
    traverse();          // 10 20 30

    insert(1, 15);
    traverse();          // 10 15 20 30

    deleteAt(2);
    traverse();          // 10 15 30

    update(0, 99);
    traverse();          // 99 15 30

    printf("Search 15 -> index %d\n", search(15));
    return 0;
}