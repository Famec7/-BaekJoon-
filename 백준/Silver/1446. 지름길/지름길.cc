#include <bits/stdc++.h>

int N, D;            // 지름길의 개수 N, 고속도로 길이 D
int dp[10001] = {0}; // i까지 가는 최소 거리

typedef struct ShortCut
{
    int start;
    int end;
    int distance;
} ShortCut;

ShortCut shortcuts[12];

void input()
{
    std::cin >> N >> D;
    for (int i = 0; i < N; i++)
    {
        std::cin >> shortcuts[i].start >> shortcuts[i].end >> shortcuts[i].distance;
    }
}

void solve()
{
    for (int i = 1; i <= D; i++)
    {
        dp[i] = dp[i - 1] + 1; // 기본적으로 직진하는 경우

        for (int j = 0; j < N; j++)
        {
            // 지름길을 이용하는 경우
            if (i == shortcuts[j].end)
            {
                dp[i] = std::min(dp[i], dp[shortcuts[j].start] + shortcuts[j].distance);
            }
        }
    }

    std::cout << dp[D] << '\n';
}

int main()
{
    input();
    solve();

    return 0;
}