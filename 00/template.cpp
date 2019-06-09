#define IN "P00IN.txt"
#define OUT "P00OUT.txt"
#include <iostream>
using namespace std;
void redir();
void dir();

int main()
{
    redir();
    /***********************************/
    // Workspace
    /***********************************/
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