#pragma once

#include <iostream>
#include <vector>

struct MinHeapNode {

    // The element to be stored
    int32_t element;

    // index of the array from which
    // the element is taken
    uint32_t i;
};

// A class for Min Heap
class MinHeap {

    // pointer to array of elements in heap
    std::vector<MinHeapNode> harr;

    // size of min heap
    size_t heap_size;

public:

    // Constructor: creates a min
    // heap of given size
    MinHeap(std::vector<MinHeapNode> &, size_t size);

    // to heapify a subtree with
    // root at given index
    void MinHeapify(int32_t);

    [[nodiscard]] static int32_t left(int32_t i) { return (2 * i + 1); }

    [[nodiscard]] static int32_t right(int32_t i) { return (2 * i + 2); }

    [[nodiscard]] MinHeapNode getMin() const { return harr[0]; }


    void replaceMin(MinHeapNode x) {
        harr[0] = x;
        MinHeapify(0);
    }
};

