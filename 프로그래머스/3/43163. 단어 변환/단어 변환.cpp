#include <bits/stdc++.h>

bool isOneDiff(const std::string &a, const std::string &b)
{
    int diffCount = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            diffCount++;
            if (diffCount > 1)
            {
                return false;
            }
        }
    }

    return true;
}

int solution(std::string begin, std::string target, std::vector<std::string> words)
{
    int answer = 0;

    const int wordsSize = words.size();
    std::queue<std::pair<std::string, int>> q;
    bool visited[wordsSize];
    std::fill(visited, visited + wordsSize, false);
    q.push({begin, 0});

    while (not q.empty())
    {
        const std::string currentWord = q.front().first;
        const int currentCount = q.front().second;
        q.pop();

        if (currentWord == target)
        {
            answer = currentCount;
            break;
        }

        for (int i = 0; i < wordsSize; i++)
        {
            if (not visited[i] and isOneDiff(currentWord, words[i]))
            {
                visited[i] = true;
                q.push({words[i], currentCount + 1});
            }
        }
    }

    return answer;
}