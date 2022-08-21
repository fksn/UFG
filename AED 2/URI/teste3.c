#include <stdio.h>

int H[50];
int size = -1;
typedef struct data {
	char nome[32];
	char tel[16];
} Data;
// Function to return the index of the
// parent node of a given node
int parent(int i)
{
	return (i - 1) / 2;
}
int leftChild(int i)
{
	return ((2 * i) + 1);
}
int rightChild(int i)
{
	return ((2 * i) + 2);
}

// Function to shift up the node in order
// to maintain the heap property
void shiftUp(int i)
{
    int aux;
	while (i > 0 && H[parent(i)] < H[i]) 
    {
        aux = H[parent(i)];
        H[parent(i)] = H[i];
        H[i] = aux;
		i = parent(i);
	}
}
void shiftDown(int i)
{
	int maxIndex = i, aux;
	int l = leftChild(i);

	if (l <= size && H[l] > H[maxIndex]) {
		maxIndex = l;
	}
	int r = rightChild(i);

	if (r <= size && H[r] > H[maxIndex]) {
		maxIndex = r;
	}
	if (i != maxIndex) {
        aux = H[i];
        H[i] = H[maxIndex];
        H[maxIndex] = aux;
		shiftDown(maxIndex);
	}
}

void insert(int p)
{
	size = size + 1;
	H[size] = p;

	shiftUp(size);
}

// Function to extract the element with
// maximum priority
int extractMax()
{
	int result = H[0];

	// Replace the value at the root
	// with the last leaf
	H[0] = H[size];
	size = size - 1;

	// Shift down the replaced element
	// to maintain the heap property
	shiftDown(0);
	return result;
}

// Function to change the priority
// of an element
void changePriority(int i, int p)
{
	int oldp = H[i];
	H[i] = p;

	if (p > oldp) {
		shiftUp(i);
	}
	else {
		shiftDown(i);
	}
}

// Function to get value of the current
// maximum element
int getMax()
{

	return H[0];
}

// Function to remove the element
// located at given index
// void remove(int i)
// {
// 	H[i] = getMax() + 1;

// 	// Shift the node to the root
// 	// of the heap
// 	shiftUp(i);

// 	// Extract the node
// 	extractMax();
// }

// Driver Code
int main()
{
	insert(45);
	insert(20);
	insert(14);
	insert(12);
	insert(31);
	insert(7);
	insert(11);
	insert(13);
	insert(7);

	int i = 0;

	// Priority queue before extracting max
    printf("Priority Queue : ");
	while (i <= size) {
        printf("%d ",H[i]);
		i++;
	}

	printf("\n");
    printf("Node with maximum priority : %d\n", extractMax());

	// Priority queue after extracting max
    printf("Priority queue after extracting maximum : ");
	int j = 0;
	while (j <= size) {
        printf("%d ", H[j]);
		j++;
	}

	printf("\n");
	changePriority(2, 49);
    printf("Priority queue after priority change : ");
	int k = 0;
	while (k <= size) {
        printf("%d ", H[k]);
		k++;
	}

	printf("\n");

	// Remove element at index 3
	// remove(3);
    // printf("Priority queue after removing the element : ");
	// int l = 0;
	// while (l <= size) {
    //     printf("%d ", H[l]);
	// 	l++;
	// }
	return 0;
}
