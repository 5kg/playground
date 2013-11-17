#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string order[] = { "pushStack", "pushQueue", "pushFront" };

int main()
{
    int n;

    cin >> n;

    vector<int> v;
    while (n--) {
        int t;

        cin >> t;

        if (t)
            v.push_back(t);
        else {
            if (v.size() == 0)
                cout << 0 << endl;
            else if (v.size() == 1)
                cout << "pushStack" << endl <<"1 popStack" << endl;
            else if (v.size() == 2)
                cout << "pushStack" << endl << "pushQueue" << endl << "2 popStack popQueue" << endl;
            else {
                vector<int> m(v);
                sort(m.begin(), m.end());

                for (int i = m.size()-3; i < m.size(); ++i)
                    for (int j = 0; j < v.size(); ++j)
                        if (v[j] == m[i]) {
                            v[j] = -(m.size()-i-1);
                            break;
                        }

                for (int i = 0; i < v.size(); ++i)
                    if (v[i] <= 0)
                        cout << order[-v[i]] << endl;
                    else
                        cout << "pushBack" << endl;
                cout << "3 popStack popQueue popFront" << endl;
            }
            v.clear();
        }
    }
    if (v.size() != 0)
        for (int i = 0; i < v.size(); ++i)
            cout << "pushStack" << endl;
    return 0;
}
