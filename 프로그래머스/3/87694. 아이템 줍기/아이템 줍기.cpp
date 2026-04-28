#include <bits/stdc++.h>

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

const int MAX_X = 100;
const int MAX_Y = 100;

bool map[MAX_X + 1][MAX_Y + 1] = {false};

void fillMap(const std::vector<std::vector<int>> &rectangle)
{
    std::vector<std::vector<bool>> visited(MAX_X + 1, std::vector<bool>(MAX_Y + 1, false));

    for (const auto &rec : rectangle)
    {
        const int x1 = rec[0] * 2;
        const int y1 = rec[1] * 2;
        const int x2 = rec[2] * 2;
        const int y2 = rec[3] * 2;

        // 시작점부터 가로로
        for (int i = x1; i < x2 + 1; i++)
        {
            if (visited[i][y1] == false)
            {
                map[i][y1] = true;
            }
        }

        // 시작점부터 세로로
        for (int i = y1; i < y2 + 1; i++)
        {
            if (visited[x1][i] == false)
            {
                map[x1][i] = true;
            }
        }

        // 종료점부터 가로로
        for (int i = x1; i < x2 + 1; i++)
        {
            if (visited[i][y2] == false)
            {
                map[i][y2] = true;
            }
        }

        // 종료점부터 세로로
        for (int i = y1; i < y2 + 1; i++)
        {
            if (visited[x2][i] == false)
            {
                map[x2][i] = true;
            }
        }

        // 내부는 false로 채우기
        for (int i = x1 + 1; i < x2; i++)
        {
            for (int j = y1 + 1; j < y2; j++)
            {
                if (map[i][j])
                {
                    map[i][j] = false;
                }
            }
        }

        for (int i = x1; i < x2 + 1; i++)
        {
            for (int j = y1; j < y2 + 1; j++)
            {
                visited[i][j] = true;
            }
        }
    }
}

int solution(std::vector<std::vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    int answer = 0;

    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

    std::queue<std::pair<int, std::pair<int, int>>> q;
    std::vector<std::vector<bool>> visited(MAX_X + 1, std::vector<bool>(MAX_Y + 1, false));
    q.emplace(0, std::make_pair(characterX, characterY));
    visited[characterX][characterY] = true;

    fillMap(rectangle);

    while (not q.empty())
    {
        const int dist = q.front().first;
        const int x = q.front().second.first;
        const int y = q.front().second.second;
        q.pop();

        if (x == itemX and y == itemY)
        {
            return dist / 2;
        }

        for (int i = 0; i < 4; i++)
        {
            const int nx = x + dx[i];
            const int ny = y + dy[i];

            if (nx < 0 or nx > MAX_X or ny < 0 or ny > MAX_Y)
            {
                continue;
            }

            if (visited[nx][ny])
            {
                continue;
            }

            if (not map[nx][ny])
            {
                continue;
            }

            visited[nx][ny] = true;
            q.emplace(dist + 1, std::make_pair(nx, ny));
        }
    }

    return answer;
}