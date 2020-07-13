#include"truetable_headers.h"

//蕴含，也就是->
bool Proposition::operator-(const Proposition& x) const
{
    if(!this->value)
    {
        return true;
    }
    else
    {
        if(x.value)
        {
            return true;
        }
        else
        {
            return false;
        }  
    }   
}

//合取，也就是且 & 与运算
bool Proposition::operator&(const Proposition& x) const
{
    return this->value&x.value;
}

//析取，也就是或 | 或运算
bool Proposition::operator|(const Proposition& x) const
{
    return this->value|x.value;
}

//把变量p的值转换为非p
bool Proposition::operator!() const
{
    return !this->value;
}

//当且仅当
bool Proposition::operator=(const Proposition& x) const
{
    if(this->value==x.value)
    {
        return true;
    }
    else
    {
        return false;
    }
}