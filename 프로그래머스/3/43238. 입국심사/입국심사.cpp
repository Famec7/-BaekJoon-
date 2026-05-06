#include <bits/stdc++.h>

long long solution(int n, std::vector<int> times)
{
    std::sort(times.begin(), times.end());

    long long max_time = (long long)times.back() * n;
    long long min_time = 1;

    long long answer = max_time;

    while (min_time <= max_time)
    {
        const long long mid_time = (min_time + max_time) / 2;

        long long total_people = 0;
        for (const int &time : times)
        {
            total_people += mid_time / time;

            if (total_people >= n)
            {
                break;
            }
        }

        if (total_people >= n)
        {
            answer = mid_time;
            max_time = mid_time - 1;
        }
        else
        {
            min_time = mid_time + 1;
        }
    }

    return answer;
}