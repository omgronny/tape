#pragma once

#include <iostream>

class Tape {
public:

    Tape() = default;

    virtual std::optional<int32_t> read_and_step() = 0;
    virtual bool write_and_step(int32_t) = 0;

    virtual ~Tape() = default;
};

