#include <queue>
#include <iostream>
#include <string>
#include <cstdio>
#include <set>

using namespace std;

char m[8][8];
int dx[] = { -2, 2, 2, -2 };
int dy[] = { 2, -2, 2, -2 };

inline bool is_goal(string &s)
{
    return (s[0] == s[2]) && (s[1] == s[3]) && (m[s[0]-'0'][s[1]-'0'] != '#');
}

inline bool is_valid(string &s)
{
    for (int i = 0; i < 4; ++i) {
        if (s[i] < '0')
            return false;
        if (s[i] >= '8')
            return false;
    }
    return true;
}

inline string get_next(string &s, int i, int j)
{
    string t = s;
    t[0] += dx[i];
    t[1] += dy[i];
    t[2] += dx[j];
    t[3] += dy[j];
    return t;
}

int main()
{
    int t;

    scanf("%d\n", &t);
    while (t--) {
        string s;
        for (int r = 0; r < 8; ++r) {
            for (int c = 0; c < 8; ++c) {
                m[r][c] = getchar();
                if (m[r][c] == 'K') {
                    s += r + '0';
                    s += c + '0';
                }
            }
            getchar();
        }

        queue<string> q;
        set<string> h;
        q.push(s);
        h.insert(s);

        bool flag = false;
        while (!q.empty()) {
            string e = q.front();
            q.pop();

            if (is_goal(e)) {
                flag = true;
                break;
            }

            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j) {
                    string next = get_next(e, i, j);
                    if (is_valid(next) && !h.count(next)) {
                        q.push(next);
                        h.insert(next);
                    }
                }
        }

        cout << (flag ? "YES" : "NO") << endl;
        getchar();
    }

    return 0;
}
