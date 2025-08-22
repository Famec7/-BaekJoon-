#include <bits/stdc++.h>

const int MAX_N = 5000;
int N, M;
int array[MAX_N];

void input()
{
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        std::cin >> array[i];
    }
}

// M개 이하로 구간 분할이 가능한지 체크
bool divisible(int mid)
{
    int min_value = array[0];
    int max_value = array[0];

    int count = 0;

    for (int i = 1; i < N; i++)
    {
        min_value = std::min(min_value, array[i]);
        max_value = std::max(max_value, array[i]);

        if (max_value - min_value > mid)
        {
            count++;
            min_value = max_value = array[i];
        }
    }

    return count < M;
}

void solve()
{
    int left = 0;
    int right = *std::max_element(std::begin(array), std::end(array));

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (divisible(mid))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    std::cout << right + 1 << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    input();
    solve();

    return 0;
}