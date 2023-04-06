#include <iostream>
#include <string>

int main()
{
    std::string number;
    std::cout << "Input real number (-0.000): ";
    std::cin >> number;

    bool minus = number.length() > 0 && number[0] == '-';

    bool dot = false;
    int dot_position = 0;

    for (int i = 0; !dot && i < number.length(); i++) {
        if (number[i] == '.') {
            dot = true;
            dot_position = i;
        }
    }

    bool ok = true;

    int int_start = minus ? 1 : 0;
    int int_end = dot ? dot_position : number.length();
    
    for (int i = int_start; i < int_end; i++) {
        if (number[i] < '0' || number[i] > '9') ok = false;
    }

    int frac_start = dot ? dot_position + 1 : number.length();

    for (int i = frac_start; i < number.length(); i++) {
        if (number[i] < '0' || number[i] > '9') ok = false;
    }

    if ((int_end - int_start) + (number.length() - frac_start) == 0) ok = false;

    std::cout << (ok ? "Yes, it's a real namber" : "No, it isn't a real number");
}

