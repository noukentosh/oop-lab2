#include "application.h"

TApplication::TApplication () {

}


int TApplication::exec () {
    int input_char;

    number coef_a = 1,
           coef_b = 2,
           coef_c = 1;

    number x;

    do {
        std::cout << "0 - Exit" << std::endl;
        std::cout << "1 - Input coefficients" << std::endl;
        std::cout << "2 - Print" << std::endl;
        std::cout << "3 - Value" << std::endl;
        std::cout << "4 - Find roots" << std::endl;
        std::cin >> input_char;

        switch (input_char) {
            case 1: {
                std::cout << "a = ";
                std::cin >> coef_a;

                std::cout << "b = ";
                std::cin >> coef_b;

                std::cout << "c = ";
                std::cin >> coef_c;

                break;
            }

            case 2: {
                TPolinom polinom (coef_a, coef_b, coef_c);

                std::cout << polinom << std::endl;
                break;
            }

            case 3: {
                TPolinom polinom (coef_a, coef_b, coef_c);

                std::cout << "x = ";
                std::cin >> x;

                std::cout << polinom.value(x) << std::endl;
                break;
            }

            case 4: {
                TPolinom polinom (coef_a, coef_b, coef_c);

                number* roots = new number;

                unsigned int roots_count = polinom.roots(roots);

                switch (roots_count) {
                case 0: {
                    std::cout << "no roots" << std::endl;
                    break;
                }
                case 1: {
                    std::cout << "x1 = x2 = " << roots[0] << std::endl;
                    break;
                }
                case 2: {
                    std::cout << "x1 = " << roots[0] << std::endl;
                    std::cout << "x2 = " << roots[1] << std::endl;
                    break;
                }
                default: break;
                }

                break;
            }

            default: break;
        }

        std::cout << std::endl;

    } while (input_char != 0);

    return 0;
}
