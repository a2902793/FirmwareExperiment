#define IN "P01IN.txt"
#define OUT "P01OUT.txt"
#include <iostream>
void redir();
void dir();

int main()
{
    redir();
    int n, count = 0;
    std::cin >> n;
    while (n > 1)
    {
        n % 2 == 1 ? n = 3*n + 1 : n /= 2;
        count++;
    }
    std::cout << count << std::endl;
    dir();
    return 0;
}

void redir()
{
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
}

void dir()
{
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
}