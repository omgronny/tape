
#include "heap.h"

// Constructor: Builds a heap from
// a given array a[] of given size
MinHeap::MinHeap(std::vector<MinHeapNode>& heap, size_t size) : heap_size(size), harr(heap) {
    int32_t i = (heap_size - 1) / 2;
    while (i >= 0) {
        MinHeapify(i);
        i--;
    }
}

// A recursive method to heapify
// a subtree with root
// at given index. This method
// assumes that the
// subtrees are already heapified
void MinHeap::MinHeapify(int32_t i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && harr[l].element < harr[i].element)
        smallest = l;

    if (r < heap_size
        && harr[r].element < harr[smallest].element)
        smallest = r;

    if (smallest != i) {
        std::swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}

