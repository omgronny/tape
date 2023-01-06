#pragma once

#include <iostream>
#include <fstream>
#include <optional>

#include "tape.h"

// так как лень может быть несколько
// можно принимать уже открытый и развернутый файл, а внутри FileTape работать только с lseek()
class FileTape : Tape {
public:

    explicit FileTape(std::string);

    std::optional<int32_t> read_and_step() override;
    bool write_and_step(int32_t) override;

    ~FileTape() {
        if (file != NULL) {
            fclose(file);
        }
    }

private:
    std::string filename;
    FILE* file;
};

