#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int a[100001];

int main()
{
    int n, k;

    cin >> n >> k;

    k = n - k;

    if (k == 0) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++i)
        a[i] = i;

    int s = 1;
    if (k & 1) {
        ++s;
        --k;
    }

    for (int i = s; k > 0; i+=2, k-=2) {
        swap(a[i], a[i+1]);
    }

    for (int i = 1; i <= n; ++i)
        cout << a[i] << ((i == n) ? "\n" : " ");

    return 0;
}
