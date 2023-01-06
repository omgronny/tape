#include <catch.hpp>

#include "../gf.h"

int32_t test_sort(const std::string& output) {
    std::ifstream inp{output};
    int32_t prev = 0;
    int32_t this_el = 0;
    for (int32_t i = 0; i < final_count; ++i) {
        inp >> this_el;
        REQUIRE(this_el >= prev);
        prev = this_el;
    }
    return 0;
}

TEST_CASE("Simple test") {

    std::string input = "input.txt";
    std::string output = "output.txt";

    struct stat sb{};
    stat(input.data(), &sb);
    int64_t file_size = sb.st_size;

    int64_t run_size = 10;
    int64_t num_ways = file_size / run_size + (file_size % run_size != 0);

    externalSort(input, output, num_ways,
                 run_size);

    test_sort(output);

}


