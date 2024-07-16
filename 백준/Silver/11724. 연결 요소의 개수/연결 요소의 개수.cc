#include <iostream>
#include <queue>

int N, M;
bool graph[1001][1001];
bool visited[1001];

void Input()
{
    std::cin >> N >> M;

    int node1, node2;
    for (int i = 0; i < M; i++)
    {
        std::cin >> node1 >> node2;
        graph[node1][node2] = true;
        graph[node2][node1] = true;
    }
}

void Bfs(int start)
{
    std::queue<int> container;

    container.push(start);
    visited[start] = true;

    while (not container.empty())
    {
        int cur = container.front();
        container.pop();

        for (int next = 1; next <= N; next++)
        {
            if (not graph[cur][next])
                continue;
            if (visited[next])
                continue;

            visited[next] = true;
            container.push(next);
        }
    }
}

void Solve()
{
    int result = 0;

    for (int i = 1; i <= N; i++)
    {
        if (visited[i])
            continue;

        Bfs(i);
        result++;
    }

    std::cout << result << '\n';
}

int main()
{
    Input();
    Solve();

    return 0;
}