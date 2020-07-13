#ifndef PROPOSITION_H
#define PROPOSITION_H

class Proposition
{
private:
    char var;
    bool value;
public:
    Proposition(char x,bool y=true):var(x),value(y){}

    bool operator !() const;
    bool operator &(const Proposition& x) const;
    bool operator |(const Proposition& x) const;
    bool operator -(const Proposition& x) const;
    bool operator =(const Proposition& x) const;
    
    friend class true_table;
};

#endif