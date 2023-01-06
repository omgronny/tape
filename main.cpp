#include <sys/stat.h>
#include <bits/stdc++.h>

#include "gf.h"
#include "file_tape.h"

int32_t test_sort(std::string& output) {
    std::ifstream inp{output};
    int32_t prev = 0;
    int32_t this_el = 0;
    for (int32_t i = 0; i < final_count; ++i) {
        inp >> this_el;
        if (this_el < prev) {
            std::cerr << "wrong sort " << this_el << " " << prev << std::endl;
            return -1;
        }
        prev = this_el;
    }
    return 0;
}

std::tuple<std::string, std::string, int32_t> parse_arguments(int argc, const char *argv[]) {

    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <input file> <output file> <buffer size>" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string input = argv[1];
    std::string output = argv[2];
    int32_t mem = std::stoi(argv[3]);

    return { input, output, mem };

}

int main(int argc, const char *argv[]) {

    auto [input, output, memory] = parse_arguments(argc, argv);

    struct stat sb{};
    stat(input.data(), &sb);
    int64_t file_size = sb.st_size;

    // The size of each partition
    int64_t run_size = memory;

    // No. of Partitions of input file.
    int64_t num_ways = file_size / run_size;

    clock_t start = clock();

    externalSort(input, output, num_ways,
                 run_size);

    clock_t end = clock();

    std::cout << final_count << " numbers sorted in " << (double) (end - start) / CLOCKS_PER_SEC << " seconds\n";

    return test_sort(output);

}