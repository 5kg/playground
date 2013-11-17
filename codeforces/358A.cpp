#include <iostream>

using namespace std;

int x[1001];

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> x[i];

    for (int i = 0; i < n-1; ++i)
        for (int j = i + 1; j < n - 1; ++j) {
            int a = min(x[i], x[i+1]);
            int b = max(x[i], x[i+1]);
            int c = min(x[j], x[j+1]);
            int d = max(x[j], x[j+1]);

            if ( (a < c) && (c < b) && (b < d) ) {
                cout << "yes" << endl;
                return 0;
            }
            else if ( (c < a) && (a < d) && (d < b) ) {
                cout << "yes" << endl;
                return 0;
            }
        }
    cout << "no" << endl;
    return 0;
}
