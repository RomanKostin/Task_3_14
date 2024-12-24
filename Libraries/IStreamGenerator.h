#pragma once

#include "Generator.h"
#include <iostream>

namespace miit::algebra
{
    /*
    *@brief класс генератор по потоку ввода
    */
    class IStreamGenerator final : public Generator
    {
    private:
        std::istream& in;

    public:
        /*
        *@brief конструктор istream генератора
        *@param in - поток ввода
        */
        explicit IStreamGenerator(std::istream& in = std::cin);

        /*
        *@brief метод генерации значений вручную
        *@return введеное пользователем значение
        */
        int generate() override;
    };

}