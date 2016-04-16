
bool istrue(char a, char b, bool na, bool nb, char t)
{
    if (t=='&')
    {
        if (!na and !nb)
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
        if (!na and !nb)
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
