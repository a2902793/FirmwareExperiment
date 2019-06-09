#define IN "P14IN.txt"
#define OUT "P14OUT.txt"
#include <iostream>
void redir();
void dir();
using namespace std;

int main()
{
    redir();

    //dir();
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