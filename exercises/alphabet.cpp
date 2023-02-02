#include <algorithm>
#include <iostream>

// Utwórz lambdę, która ma wraz z każdym wywołaniem zwracać kolejną literę alfabetu,
// zaczynając od a. Gdy dojdziemy do z lambda powinna zwracać duże litery - od A do Z,
// a potem znów małe. Nie używaj zewnętrznych zmiennych statycznych lub globalnych.
// Zaimplementuj to zadanie bez używania tablicy ASCII.

int main()
{
    auto alphabet = [c('a')]() mutable -> char // -> char oznacza, że typ zwracany to char
    // mutable pozwala na modyfikacje zmiennej c
    {
        c++;
        if (c == 'z' + 1)
            c = 'A';
        else if (c == 'Z' + 1)
            c = 'a';
        return c;
    };

    for (int i = 0; i < 100; i++)
    {
        std::cout << alphabet() << " ";
    }

    return 0;
}