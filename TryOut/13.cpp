#define IN "P13IN.txt"
#define OUT "P13OUT.txt"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void redir();
void dir();

int main()
{
    redir();
    int kase = 0;
    int N, Q, Z, p;
    while(scanf("%d%d",&N, &Q) == 2 && N)
    {
        vector<int> a;  //這不在裡面的話 後面的會被加進來
        printf("CASE# %d:\n",++kase);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &Z);
            a.push_back(Z);
        }
        sort(a.begin(), a.end());
        while(Q--)
        {
            scanf("%d", &Z);
            p = lower_bound(a.begin(), a.end(), Z) - a.begin();
            if(p < a.size() && a[p] == Z)
                printf("%d found at %d\n", Z, p+1);
            else
                printf("%d not found\n", Z);
        }
    }
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