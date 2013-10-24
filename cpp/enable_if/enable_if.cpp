/* A quick demo of the usage of enable_if */

#include <iostream>
#include <type_traits>

template <bool B, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> { typedef T type; };

template <typename T, typename U>
struct is_same { static constexpr bool value = false; };

template <typename T>
struct is_same<T, T> { static constexpr bool value = true; };

template <typename T>
struct is_integral {
    static constexpr bool value =
        is_same<T, char>::value
     || is_same<T, short>::value
     || is_same<T, int>::value
     || is_same<T, long>::value
     || is_same<T, long long>::value;
};

template <typename T>
struct is_floating_point {
    static constexpr bool value =
        is_same<T, float>::value
     || is_same<T, double>::value
     || is_same<T, long double>::value;
};

template <typename T>
typename enable_if<is_integral<T>::value, T>::type foo(T n)
{
    std::cout << "I am a integral number: " << n << std::endl;
}

template <typename T>
typename enable_if<is_floating_point<T>::value, T>::type foo(T n)
{
    std::cout << "I am a float number: " << n << std::endl;
}

int main()
{
    float f = 1.0;
    double d = 2.0;
    long double ld = 3.0;

    foo(f);
    foo(d);
    foo(ld);

    foo(0);

    return 0;
}
