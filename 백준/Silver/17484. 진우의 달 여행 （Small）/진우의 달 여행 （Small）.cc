#include <climits>
#include <iostream>

int N, M;
int board[100][100];
int dp[100][100];
int dx[3] = {-1, 0, 1};

const int INF = INT_MAX;

// Print board for debugging
void PrintBoard()
{
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            std::cout << board[y][x] << ' ';
        }
        std::cout << '\n';
    }
}

int FindPath(int x, int y, int prevDirection)
{
    if (y == N)
    {
        return 0;
    }

    int ret = INF;
    for (int direction = 0; direction < 3; direction++)
    {
        // 이전 방향과 같은 방향으로는 이동할 수 없음.
        if (direction == prevDirection)
        {
            continue;
        }

        int nx = x + dx[direction];
        int ny = y + 1;

        if (nx < 0 || nx >= M)
        {
            continue;
        }

        ret = std::min(ret, board[y][x] + FindPath(nx, ny, direction));
    }

    return ret;
}

void Input()
{
    std::cin >> N >> M;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            std::cin >> board[y][x];
        }
    }
}

void Solve()
{
    int result = INT_MAX;
    for (int x = 0; x < M; x++)
    {
        result = std::min(result, FindPath(x, 0, -1));
    }

    std::cout << result << '\n';
}

int main()
{
    Input();
    Solve();

    return 0;
}