#include "file_tape.h"

FILE *openFile(char *fileName, const char *mode) {
    FILE *fp = fopen(fileName, mode);
    return fp;
}

FileTape::FileTape(std::string file_) : filename(std::move(file_)), file(openFile(filename.data(), "r+")) {
}

std::optional<int32_t> FileTape::read_and_step() {
    int32_t val;
    if (fscanf(file, "%d ", &val) != 1) {
        return std::nullopt;
    }
    return val;
}

bool FileTape::write_and_step(int32_t value) {
    if (fprintf(file, "%d ", value) < 0) {
        std::cerr << "error in write_and_step" << std::endl;
        return false;
    }
    return true;
}




