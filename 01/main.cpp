#define IN "P01IN.txt"
#define OUT "P01OUT.txt"
#include <stdio.h>
void redir();
void dir();

int main() {
    redir();
    int n, count = 0;
    scanf("%d", &n);
    while (n > 1) {
        n % 2 == 1 ? n = 3*n + 1 : n /= 2;
        count++;
    }
    printf("%d", count);
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