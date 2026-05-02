#include <bits/stdc++.h>

int dp[1000001];

int solution(std::vector<int> money)
{
    int answer = 0;

    const int size = money.size();

    dp[0] = money[0];
    dp[1] = std::max(money[0], money[1]);
    for (int i = 2; i < size; i++)
    {
        dp[i] = std::max(dp[i - 2] + money[i], dp[i - 1]);
    }
    answer = dp[size - 2];

    std::fill(dp, dp + size, 0);
    dp[1] = money[1];

    for (int i = 2; i < size; i++)
    {
        dp[i] = std::max(dp[i - 2] + money[i], dp[i - 1]);
    }
    answer = std::max(answer, dp[size - 1]);

    return answer;
}