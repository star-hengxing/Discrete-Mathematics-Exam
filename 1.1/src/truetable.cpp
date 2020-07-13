#include"truetable_headers.h"

void true_table::show_true_table() const
{
    if (variable.empty())
    {
        return;
    }
    else
    {
        srand(time(NULL));
        int variable_num = variable.size();
        int num = pow(2, variable_num);
        std::vector<bool*>table;
        bool flag = true;
        while (table.size() != num)
        {
            bool* p = new bool[variable_num];
            for (int i = 0; i < variable_num; i++)
            {
                p[i] = rand() % 2;
            }
            if (table.size() >= 1)
            {
                for (const auto& x : table)
                {
                    if (memcmp(x, p, variable_num) == 0)
                    {
                        flag = false;
                        delete[] p;
                        break;
                    }
                    else
                    {
                        flag = true;
                    }
                }
            }
            if (flag)
            {
                table.push_back(p);
            }
        }
        //打印
        for (const auto& v : variable)
        {
            std::cout << v.var << "   ";
        }
        printf("\n");
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < variable_num; j++)
            {
                std::cout << table[i][j] << "   ";
            }
            printf("\n");
        }
        //释放申请的内存
        for (const auto& x : table)
        {
            delete[] x;
        }
    }
}

//中缀表达式转换为后缀表达式
std::string true_table::transform(const std::string& infix_expression)
{
    while (s.size())
    {
        s.pop();
    }
    std::string suffix_expression;
    for (const auto& x : infix_expression)
    {
        if (s.size() > 0)
        {
            if (s.top() == '!' && x >= 'a' && x <= 'z')
            {
                suffix_expression += x;
                suffix_expression += '!';
                s.pop();
                continue;
            }
        }
        if (x == ')')
        {
            //如果匹配到右括号，输出左括号上的符号
            while (1)
            {
                if (s.top() == '(')
                {
                    s.pop();
                    if (s.size() > 0 && s.top() == '!')
                    {
                        suffix_expression += '!';
                        s.pop();
                    }
                    break;
                }
                suffix_expression += s.top();
                s.pop();
            }
            continue;
        }
        else if (x >= 'a' && x <= 'z')
        {
            //遇到命题变元则输出
            suffix_expression += x;
            continue;
        }
        s.push(x);
    }
    while (s.size())
    {
        suffix_expression += s.top();
        s.pop();
    }
    return suffix_expression;
}

//判断表达式真值
bool true_table::result(const std::string& suffix_expression)
{
    while (s.size())
    {
        s.pop();
    }
    for (const auto& x : suffix_expression)
    {
        bool temp, temp2;
        if (x >= 'a' && x <= 'z')
        {

            for (const auto& y : variable)
            {
                if (x == y.var)
                {
                    s.push(y.value);
                    continue;
                }
            }
        }
        else if (x == '!')
        {
            temp = !s.top();
            s.pop();
            s.push(temp);
            continue;
        }
        else if (x == '&')
        {
            temp = s.top();
            s.pop();
            temp2 = s.top();
            s.pop();
            s.push(temp & temp2);
            continue;
        }
        else if (x == '|')
        {
            temp = s.top();
            s.pop();
            temp2 = s.top();
            s.pop();
            s.push(temp | temp2);
            continue;
        }
        else if (x == '-')
        {
            temp = s.top();
            s.pop();
            temp2 = s.top();
            s.pop();
            if (!temp)
            {
                s.push(true);
            }
            else
            {
                if (temp2)
                {
                    s.push(true);
                }
                else
                {
                    s.push(false);
                }
            }
            continue;
        }
    }
    return s.top();
}