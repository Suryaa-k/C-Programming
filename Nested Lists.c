#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} Row;

typedef struct {
    Row* rows;
    int rowCount;
    int rowCapacity;
} NestedList;

void initRow(Row* r, int cap) {
    r->capacity = cap;
    r->size = 0;
    r->data = (int*)malloc(cap * sizeof(int));
}

void initNested(NestedList* nl) {
    nl->rowCapacity = 2;
    nl->rowCount = 0;
    nl->rows = (Row*)malloc(nl->rowCapacity * sizeof(Row));
}

void resizeNested(NestedList* nl) {
    nl->rowCapacity *= 2;
    Row* newRows = (Row*)malloc(nl->rowCapacity * sizeof(Row));
    for (int i = 0; i < nl->rowCount; i++) newRows[i] = nl->rows[i];
    free(nl->rows);
    nl->rows = newRows;
}

void addRow(NestedList* nl, int arr[], int n) {
    if (nl->rowCount == nl->rowCapacity) resizeNested(nl);
    Row r;
    initRow(&r, n);
    for (int i = 0; i < n; i++) r.data[i] = arr[i];
    r.size = n;
    nl->rows[nl->rowCount++] = r;
}

int get(NestedList* nl, int row, int col) {
    return nl->rows[row].data[col];
}

void set(NestedList* nl, int row, int col, int value) {
    nl->rows[row].data[col] = value;
}

void traverse(NestedList* nl) {
    for (int i = 0; i < nl->rowCount; i++) {
        for (int j = 0; j < nl->rows[i].size; j++) {
            printf("%d ", nl->rows[i].data[j]);
        }
        printf("\n");
    }
}

void flatten(NestedList* nl, int* out, int* outSize) {
    int idx = 0;
    for (int i = 0; i < nl->rowCount; i++) {
        for (int j = 0; j < nl->rows[i].size; j++) {
            out[idx++] = nl->rows[i].data[j];
        }
    }
    *outSize = idx;
}

int main() {
    NestedList nl;
    initNested(&nl);

    int r1[] = {1, 2, 3};
    int r2[] = {4, 5};
    int r3[] = {6, 7, 8, 9};
    addRow(&nl, r1, 3);
    addRow(&nl, r2, 2);
    addRow(&nl, r3, 4);

    traverse(&nl);

    printf("get(2,1) = %d\n", get(&nl, 2, 1));
    set(&nl, 0, 0, 99);
    traverse(&nl);

    int flat[20], flatSize;
    flatten(&nl, flat, &flatSize);
    printf("Flattened: ");
    for (int i = 0; i < flatSize; i++) printf("%d ", flat[i]);
    printf("\n");

    return 0;
}