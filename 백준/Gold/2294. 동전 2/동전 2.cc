#include <iostream>

int n, k;
int coins[100];
int dp[10001];

const int INF = 10001;

void Input()
{
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> coins[i];
    }
}

void Solve()
{
    std::fill(dp + 1, dp + k + 1, INF);

    for (int i = 0; i < n; i++)
    {
        const int &coin = coins[i];
        for (int j = coin; j <= k; j++)
        {
            dp[j] = std::min(dp[j], dp[j - coin] + 1);
        }
    }

    if (dp[k] == INF)
        std::cout << "-1\n";
    else
        std::cout << dp[k] << '\n';
}

int main()
{
    Input();
    Solve();

    return 0;
}