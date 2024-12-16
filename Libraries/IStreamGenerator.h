#pragma once

#include "Generator.h"
#include <iostream>

namespace miit::algebra
{

    class IStreamGenerator final : public Generator
    {
    private:
        std::istream& in;

    public:
        explicit IStreamGenerator(std::istream& in = std::cin);

        int generate() override;
    };

}