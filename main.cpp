#include <iostream>
#include <time.h>
#include <vector>

int main()
{
    int quantity;
    int loop{1};
    int first_soma{0};
    int second_soma{0};
    int m, m2;
    int first_verifier;
    int second_verifier;
    int rand_number;

    std::vector<int> numbers;

    srand(time(NULL));

    std::cout << "Quantos CPF's deseja gerar? ";
    std::cin >> quantity;

    while (loop <= quantity)
    {
        for (int i = 1; i <= 9; ++i)
        {
            rand_number = rand() % 9 + 1;
            m = rand_number * i;
            first_soma += m;

            numbers.push_back(rand_number);
        }

        std::cout << '\n';

        first_verifier = first_soma % 11;

        if (first_verifier >= 10)
        {
            first_verifier = 0;
        }

        numbers.push_back(first_verifier);

        std::vector<int> factors_2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        for (size_t j = 0; j < numbers.size(); ++j)
        {
            m2 = numbers[j] * factors_2[j];
            second_soma += m2;
        }

        second_verifier = second_soma % 11;
        if (second_verifier == 10)
        {
            second_verifier = 0;
        }

        numbers.push_back(second_verifier);

        std::cout << "CPF Gerado: ";
        for (int number : numbers)
        {
            std::cout << number;
        }

        ++loop;

        numbers.clear();
        first_soma = 0;
        second_soma = 0;
    }

    std::cout << '\n';
    std::cout << '\n';
    return 0;
}