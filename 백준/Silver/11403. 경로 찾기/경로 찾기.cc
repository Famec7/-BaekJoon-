#include <iostream>
#include <queue>

int N;
int graph[100][100];

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

void FloydWarshall()
{
    // k : 거쳐가는 노드
    for (int k = 0; k < N; k++)
    {
        // i : 출발 노드
        for (int i = 0; i < N; i++)
        {
            // j : 도착 노드
            for (int j = 0; j < N; j++)
            {
                if (graph[i][k] and graph[k][j])
                {
                    graph[i][j] = 1;
                }
            }
        }
    }
}

void Solve()
{
    FloydWarshall();

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            std::cout << graph[y][x] << ' ';
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