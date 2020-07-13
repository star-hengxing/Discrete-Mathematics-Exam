#include"truetable_headers.h"

using namespace std;

int main()
{
    Proposition q('q', 1);
    string p;
    for (int i = 0; i < 30; i++)
    {
        if (i == 29)
        {
            p += "q";
            break;
        }
        p += "q&";
    }
    true_table x(q);
    cout << "命题变元为：" << p << endl;
    printf("\n");
    printf("现在，所有证据都为真，那么命题变元真值为：%d\n", x.result(x.transform(p)));
    return 0;
}