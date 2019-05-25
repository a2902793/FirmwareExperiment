#define OUT "P19OUT.txt"
#include <iostream>
using namespace std;
void redir();
void dir();

#include <vector>
#include <queue>
#include <set>
typedef long long LL;
const int coeff[3] = {2, 3, 5};

int main()
{
    redir();
    priority_queue<LL, vector<LL>, greater<LL> > pq;
    set<LL> s;
    pq.push(1);
    s.insert(1);
    for (int i = 1;; i++)
    {
        LL x = pq.top();
        pq.pop();
        if (i == 1500)
        {
            cout << "The 1500'th ugly number is " << x << ".\n";
            break;
        }
        for (int j = 0; j < 3; j++)
        {
            LL x2 = x * coeff[j];
            if (!s.count(x2))
            {
                s.insert(x2);
                pq.push(x2);
            }
        }
    }
    //dir();
    return 0;
}

void redir()
{
    freopen(OUT, "w", stdout);
}

void dir()
{
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
}