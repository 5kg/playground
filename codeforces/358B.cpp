#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;

    cin >> n;

    string s = "<3";
    for (int i = 0; i < n; ++i) {
        string w;
        cin >> w;
        s += w + "<3";
    }

    string line;
    cin >> line;

    int j = 0;
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] == s[j])
            ++j;
        if (j == s.size()) {
            cout << "yes\n";
            return 0;
        }
    }

    cout << "no\n";

    return 0;
}
