#include "chaining.h"

void fchain(char s, zmienne_t* dane, rule_t* rules, int rules_count)
{
    int i;
    bool known = false;
    for(i = 0 ; i<dane->cap ; i++)
    {
        if(dane->names[i]==s)
        {
            if (dane->values[i]!='?')
            {
                printf("%c",dane->values[i]);
                return;
            }
            else
            {
                known=true;
                i=dane->cap;
            }
        }
    }
    if (!known)
    {
        printf("Couldn't find you variable in data. Check dane.txt \n");
        return;
    }
    else //Actually start solving
    {
        for(i=0 ; i<rules_count ; i++)
        {

        }
    }
}


bool istrue(char a, char b, bool na, bool nb, char t)
{
    if (t=='&')
    {
        if (!na && !nb)
        {
            if (a&&b)
                return true;
            else
                return false;
        }
        else if (na)
        {
            if (!a&&b)
                return true;
            else
                return false;
        }
        else if (nb)
        {
            if (a&&!b)
                return true;
            else
                return false;
        }
    }

    else if (t=='|')
    {
        if (!na && !nb)
        {
            if (a||b)
                return true;
            else
                return false;
        }
        else if (na)
        {
            if (!a||b)
                return true;
            else
                return false;
        }
        else if (nb)
        {
            if (a||!b)
                return true;
            else
                return false;
        }
    }
    else
    {
        printf("Unknown operator: %c\n",t);
        return false;
    }
}
