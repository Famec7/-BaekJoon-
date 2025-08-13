#include <bits/stdc++.h>

const int MAX_NODE = 1000000 * 4 + 1;
int N = 0, M = 0;
long long tree[MAX_NODE] = {0};

void input()
{
    std::cin >> N >> M;
}

long long sum(int current_node, int start, int end, const int &left, const int &right)
{
    if (right < start or left > end)
    {
        return 0;
    }
    else if (left <= start and end <= right)
    {
        return tree[current_node];
    }

    const int mid = (start + end) / 2;

    long long left_sum = sum(current_node * 2, start, mid, left, right);
    long long right_sum = sum(current_node * 2 + 1, mid + 1, end, left, right);
    return left_sum + right_sum;
}

void modify(int current_node, int start, int end, const int &index, const int &value)
{
    if (start >= end)
    {
        tree[current_node] = value;
        return;
    }

    int mid = (start + end) / 2;
    if (start <= index and index <= mid)
    {
        modify(current_node * 2, start, mid, index, value);
    }
    else
    {
        modify(current_node * 2 + 1, mid + 1, end, index, value);
    }

    tree[current_node] = tree[current_node * 2] + tree[current_node * 2 + 1];
}

void solve()
{
    int op = 0;
    int param1 = 0, param2 = 0;
    while (M--)
    {
        std::cin >> op >> param1 >> param2;

        if (op == 0)
        {
            if (param1 > param2)
            {
                std::swap(param1, param2);
            }
            std::cout << sum(1, 1, N, param1, param2) << '\n';
        }
        else if (op == 1)
        {
            modify(1, 1, N, param1, param2);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    input();
    solve();

    return 0;
}