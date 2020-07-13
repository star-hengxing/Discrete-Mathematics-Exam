#include"truetable_headers.h"

using namespace std;

int main()
{
    true_table x, y, z,u;

    Proposition a('p', 0);
    Proposition b('p', 1);
    Proposition c('q', 0);
    Proposition d('q', 1);

    printf("%15c", 'p');
    printf("%15c", 'q');
    printf("%15s", "p-q");
    printf("%15s", "q-p");
    printf("%20s", "(p-q) & (q-p)");
    printf("%10s", "p=q");

    x.add(a);
    x.add(c);
    printf("\n");
    printf("%15d", 0);
    printf("%15d", 0);
    printf("%15d", (a - c));
    printf("%15d", (c - a));
    printf("%15d", x.result(x.transform("(p-q) & (q-p)")));
    printf("%15d", (a = c));
    
    y.add(b);
    y.add(c);
    printf("\n");
    printf("%15d", 1);
    printf("%15d", 0);
    printf("%15d", (b - c));
    printf("%15d", (c - b));
    printf("%15d", y.result(x.transform("(p-q) & (q-p)")));
    printf("%15d", (b = c));

    z.add(a);
    z.add(d);
    printf("\n");
    printf("%15d", 0);
    printf("%15d", 1);
    printf("%15d", (a - d));
    printf("%15d", (d - a));
    printf("%15d", z.result(x.transform("(p-q) & (q-p)")));
    printf("%15d", (a = d));

    u.add(b);
    u.add(d);
    printf("\n");
    printf("%15d", 1);
    printf("%15d", 1);
    printf("%15d", (b - d));
    printf("%15d", (d - b));
    printf("%15d", u.result(x.transform("(p-q) & (q-p)")));
    printf("%15d", (b = d));

    return 0;
}