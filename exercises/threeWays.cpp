#include <vector>
#include <algorithm>
#include <iostream>

// Użyj odpowiedniego algorytmu STL, aby sprawdzić,
// czy wszystkie elementy wektora numbers są podzielne przez 3.

// funkcja

bool byThree(int &x)
{
    if (x % 3 == 0)
    {
        std::cout << "Liczba: " << x << " jest podzielna przez 3 \n";
        return 1;
    }
    return 0;
}

int main()
{

    std::vector numbers = {18, 21, 36, 90, 27, 14, 103};


    std::for_each(numbers.begin(), numbers.end(), byThree);

    std::cout << "\n";

    // lambda

    std::for_each(numbers.begin(), numbers.end(),
                  [](auto x)
                  { if( x%3==0 ) std::cout << "Liczba: " << x << " jest podzielna przez 3 \n"; });

    // funktor

    std::cout << "\n";

    struct DivisibilityByThree
    {
        bool operator()(int x)
        {
            if (x % 3 == 0)
            {
                std::cout << "Liczba: " << x << " jest podzielna przez 3 \n";
                return x % 3 == 0;
            }
            return 0;
        }
    };

    std::for_each(numbers.begin(), numbers.end(), DivisibilityByThree{});

    return 0;
}