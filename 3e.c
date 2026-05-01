#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    char data;
    int freq;
    struct Node *left, *right;
};

struct MinHeap
{
    int size;
    struct Node *arr[MAX];
};

struct Node *createNode(char data, int freq)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void swap(struct Node **a, struct Node **b)
{
    struct Node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MinHeap *heap, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left]->freq < heap->arr[smallest]->freq)
        smallest = left;

    if (right < heap->size && heap->arr[right]->freq < heap->arr[smallest]->freq)
        smallest = right;

    if (smallest != i)
    {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

struct Node *extractMin(struct MinHeap *heap)
{
    struct Node *temp = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return temp;
}

void insertHeap(struct MinHeap *heap, struct Node *node)
{
    heap->size++;
    int i = heap->size - 1;
    while (i && node->freq < heap->arr[(i - 1) / 2]->freq)
    {
        heap->arr[i] = heap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->arr[i] = node;
}

struct Node *buildHuffman(char data[], int freq[], int n)
{
    struct MinHeap heap;
    heap.size = 0;

    for (int i = 0; i < n; i++)
    {
        heap.arr[i] = createNode(data[i], freq[i]);
    }
    heap.size = n;

    for (int i = (heap.size - 2) / 2; i >= 0; i--)
    {
        heapify(&heap, i);
    }

    while (heap.size > 1)
    {
        struct Node *left = extractMin(&heap);
        struct Node *right = extractMin(&heap);
        struct Node *newNode = createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        insertHeap(&heap, newNode);
    }
    return extractMin(&heap);
}

void printCodes(struct Node *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right)
    {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
        {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    char data[MAX];
    int freq[MAX];

    printf("Enter number of characters: ");
    scanf("%d", &n);

    printf("Enter characters:\n");
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &data[i]);
    }

    printf("Enter frequencies:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &freq[i]);
    }

    struct Node *root = buildHuffman(data, freq, n);
    int arr[MAX], top = 0;
    printf("\nHuffman Codes:\n");
    printCodes(root, arr, top);

    return 0;
}