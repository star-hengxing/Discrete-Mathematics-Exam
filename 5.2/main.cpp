#include <iostream>

int gcd(int x, int y);

int main()
{
    printf("gcd(10881,2067)最大公约数为：%d\n", gcd(10881, 2067));
    return 0;
}

int gcd(int x,int y)
{
    return y?gcd(y,x%y):x;
}
