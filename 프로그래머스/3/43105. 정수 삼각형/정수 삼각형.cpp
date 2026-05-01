#include <bits/stdc++.h>

int solution(std::vector<std::vector<int>> triangle)
{
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j < 1)
            {
                triangle[i][j] = triangle[i][j] + triangle[i - 1][j];
            }
            else if (j == triangle[i - 1].size())
            {
                triangle[i][j] = triangle[i][j] + triangle[i - 1][j - 1];
            }
            else
            {
                const int left = triangle[i][j] + triangle[i - 1][j - 1];
                const int right = triangle[i][j] + triangle[i - 1][j];
                triangle[i][j] = std::max(left, right);
            }
        }
    }

    int answer = 0;
    for (const auto &i : triangle[triangle.size() - 1])
    {
        answer = std::max(answer, i);
    }

    return answer;
}