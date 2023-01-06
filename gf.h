
#pragma once

#include <sys/stat.h>
#include "heap.h"
#include "file_tape.h"

void split_and_sort(const std::string& input_file, const int64_t run_size,
                    const int64_t num_ways) {

    FileTape in(input_file);

    std::vector<FileTape> out;
    out.reserve(num_ways);

    std::string filename;
    for (int i = 0; i < num_ways; i++) {
        filename = "/tmp/gfsort/" + std::to_string(i);
        out.emplace_back(filename);
    }

    std::vector<int32_t> arr(run_size);

    bool more_input = true;
    int next_output_file = 0;

    int i;
    while (more_input) {

        for (i = 0; i < run_size; i++) {
            auto maybe_value = in.read_and_step();
            if (maybe_value.has_value()) {
                arr[i] = maybe_value.value();
            } else {
                more_input = false;
                break;
            }
        }

        std::sort(arr.begin(), arr.end());

        for (int j = 0; j < i; j++) {
            out[next_output_file].write_and_step(arr[j]);
        }

        next_output_file++;
    }

}

int64_t final_count = 0;
void merge_files(const std::string& output_file, int64_t n, int64_t k) {

    std::vector<FileTape> in;
    in.reserve(k);

    std::string filename;
    for (int i = 0; i < k; i++) {
        filename = "/tmp/gfsort/" + std::to_string(i);
        in.emplace_back(filename);
    }

    // FINAL OUTPUT FILE
    FileTape out(output_file);

    std::vector<MinHeapNode> harr(k);
    int i;
    for (i = 0; i < k; i++) {
        // break if no output file is empty and
        // index i will be no. of input files
        auto maybe_value = in[i].read_and_step();
        if (maybe_value.has_value()) {
            harr[i].element = maybe_value.value();
        } else {
            break;
        }
        // Index of scratch output file
        harr[i].i = i;
    }

    MinHeap hp(harr, i);

    int count = 0;

    while (count != i) {

        MinHeapNode root = hp.getMin();
        out.write_and_step(root.element);
        final_count++;

        auto maybe_value = in[root.i].read_and_step();
        if (!maybe_value.has_value()) {
            root.element = INT_MAX;
            count++;
        }


        hp.replaceMin(root);
    }

}

void externalSort(const std::string& input_file, const std::string& output_file,
                  int64_t num_ways, int64_t run_size) {

    split_and_sort(input_file, run_size, num_ways);

    merge_files(output_file, run_size, num_ways);
}


