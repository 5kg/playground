/*
 * Codeforces 1A
 * TAG: Math
 * NOTE: `ceiling(a/b) = (a+b-1)/b` if `a > 0 and b > 0`
 *       Choose proper variable type by estimating range of values.
 * STATUS: AC/2226754/1348231145/C++/31ms/1500KB
*/

#include <iostream>

int main()
{
    unsigned long long n, m, a;

    std::cin >> n >> m >> a;
    std::cout << ((n+a-1)/a)*((m+a-1)/a) << std::endl;

    return 0;
}
