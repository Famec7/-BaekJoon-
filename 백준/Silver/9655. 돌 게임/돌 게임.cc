#include <iostream>

int N = 0;

void solve()
{
    if (N % 2 == 0)
    {
        std::cout << "CY\n";
    }
    else
    {
        std::cout << "SK\n";
    }
}

int main()
{
    std::cin >> N;

    solve();

    return 0;
}