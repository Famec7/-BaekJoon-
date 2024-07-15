#include <iostream>
#include <queue>

int n, m;
int person1, person2;
bool isFamily[101][101];
int relatives[101]; // 촌수

void Input()
{
    std::cin >> n;
    std::cin >> person1 >> person2;
    std::cin >> m;

    int x, y;
    for (int i = 0; i < m; i++)
    {
        std::cin >> x >> y;
        isFamily[x][y] = true;
        isFamily[y][x] = true;
    }

    std::fill(relatives, relatives + n + 1, -1);
}

void Bfs(int start)
{
    std::queue<int> container;

    container.push(start);
    relatives[start]++;

    while (not container.empty())
    {
        int current = container.front();
        container.pop();

        for (int next = 1; next <= n; next++)
        {
            if (not isFamily[current][next])
                continue;
            if (relatives[next] != -1)
                continue;

            relatives[next] = relatives[current] + 1;
            container.push(next);
        }
    }
}

void Solve()
{
    Bfs(person1);

    std::cout << relatives[person2] << '\n';
}

int main()
{
    Input();
    Solve();

    return 0;
}