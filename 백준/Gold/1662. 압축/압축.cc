#include <bits/stdc++.h>

std::string S;
std::stack<int> st;

void input()
{
    std::cin >> S;
}

void solve()
{
    for (int i = 0; i < S.length(); i++)
    {
        // K에 해당하는 숫자
        if (i < S.length() - 1 && S[i + 1] == '(')
        {
            st.push(S[i] - '0');
        }
        else if (S[i] == ')')
        {
            int sum = 0;
            // '('가 나올때까지 문자열의 길이 총합
            while (!st.empty() && st.top() != -1)
            {
                sum += st.top();
                st.pop();
            }
            st.pop(); // '('제외

            // K(Q) 계산
            if (!st.empty())
            {
                sum *= st.top();
                st.pop();
                st.push(sum);
            }
        }
        // 현재 문자가 '('이면 -1을 스택에 넣음
        else if (S[i] == '(')
        {
            st.push(-1);
        }
        // Q에 해당하는 문자열 (문자열 길이를 구하므로 1을 스택에 넣음)
        else
        {
            st.push(1);
        }
    }

    int result = 0;
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    std::cout << result << '\n';
}

int main()
{
    input();
    solve();

    return 0;
}