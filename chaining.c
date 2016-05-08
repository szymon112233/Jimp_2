#include "chaining.h"

bool istrue(char aa, char bb, bool na, bool nb, char t)
{
    bool a = aa-48;
    bool b = bb-48;

    if (t=='&')
    {
        if (!na && !nb)
        {
            if (a && b)
                return true;
            else
                return false;
        }
        else if (na && nb)
        {
            if (!a&&!b)
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
        if (na && nb)
        {
            if (!a||!b)
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


void fchain(char s, zmienne_t* dane, rule_t* rules, int rules_count)
{
    int i;
    char value= get_value(s, dane);
    bool tempv;
    if (value=='X')
    {
        printf("Couldn't find your variable in data. Check dane.txt \n");
        return;
    }
    else if (value!='?')
    {
        if(value=='1')
            printf("%c = true\n",s);
        else if(value=='0')
            printf("%c = false\n",s);
    }
    else //Actually start solving
    {
        printf("%c unknown, chaining forward...\n",s);
        for(i=0 ; i<rules_count ; i++)
        {
            printf("Counting rule number %d...\n",i+1);
            show_rule(rules,rules_count,i);
            int j;
            for (j=1 ; j<rules[i].nvar-1 ; j++)
            {
                if (j==1)
                    tempv = istrue( get_value(rules[i].names[j-1], dane) , get_value(rules[i].names[j], dane) , rules[i].negations[j-1] , rules[i].negations[j], rules[i].operators[j-1]);
                else
                    tempv = istrue( tempv , get_value(rules[i].names[j], dane) , false , rules[i].negations[j], rules[i].operators[j-1]);
            }

            printf("Rule number %d counted, %c = %d\n", i+1, rules[i].names[rules[i].nvar-1], tempv);

            if(rules[i].names[rules[i].nvar-1]==s)
                i=rules_count;

        }
        if (tempv)
            set_value('1', s , dane);
        else
            set_value('0', s , dane);


        value= get_value(s, dane);
        if(value=='1')
            printf("%c = true\n",s);
        else if(value=='0')
            printf("%c = false\n",s);
        else
            printf("Something went terribly wrong...\n");
    }
}


