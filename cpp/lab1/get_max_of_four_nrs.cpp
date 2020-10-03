#include <cstdio>
#include <iostream>

/*
* Returns maximum between four numbers read from stdin
*/
int getMaxBetweenFourNumbers()
{
    int a, b, c, d;

    std::cin >> a >> b >> c >> d;

    int max = a;

    if (b > max) {
        max = b;
    }

    if (c > max) {
        max = c;
    }

    if (d > max) {
        max = d;
    }

    return max;
}