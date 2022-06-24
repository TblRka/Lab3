#pragma once
#include <iostream>

class ExceptionError {
public:
    ExceptionError(int key) {
        int number = key;
        switch (number)
        {
        case 1:
            std::cout << "IndexOutOfRange\n";
            break;
        case 2:
            std::cout << "InvalidValue\n";
            break;
        default:
            break;
        }
    }
};