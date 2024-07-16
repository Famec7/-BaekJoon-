#include <iostream>
#include <queue>

int N;
int graph[100][100];
int result[100][100];

void Input()
{
    std::cin >> N;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            std::cin >> graph[y][x];
        }
    }
}

void Bfs(int start)
{
    std::queue<int> container;

    container.push(start);

    while (not container.empty())
    {
        int cur = container.front();
        container.pop();

        for (int next = 0; next < N; next++)
        {
            if (graph[cur][next] == 0)
                continue;
            if (result[start][next] == 1)
                continue;

            container.push(next);
            result[start][next] = 1;
        }
    }
}

void Solve()
{
    for (int i = 0; i < N; i++)
    {
        Bfs(i);
    }

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            std::cout << result[y][x] << ' ';
        }
        std::cout << '\n';
    }
}

int main()
{
    Input();
    Solve();

    return 0;
}