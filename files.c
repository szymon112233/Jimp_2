#include "files.h"

int get_data_cap(char* name)
{
    FILE *plik = fopen(name,"r");
    char c;
    c=fgetc(plik);
    int n=c - '0';
    fclose(plik);
    return n;
}

void read_data(char* name,zmienne_t* temp)
{
    FILE *plik = fopen(name,"r");
    char c;
    c=fgetc(plik);
    int n=c - '0';
    if (debug)
        printf("%d",n);
    c=fgetc(plik);
    int i;
    bool isvalue=false;
    //int name_length=0;
    for (i=0;i<n;i++)
    {
        isvalue=false;
        if (debug)
            printf("\n%d. ",i);
        c=fgetc(plik);
        while (c!='\n')
        {
            if (debug)
                printf("%c",c);
            if(c!='=')
            {
                if (isvalue)
                    temp->values[i]=c;
                else
                {

                    temp->names[i]=c;
                    //TODO wpisywanie nazw wieloznakowych
                }
            }
            else
            {
                //printf("%s",temp->names[i]);
                isvalue = true;
            }
            c=fgetc(plik);
        }
    }

    fclose(plik);
    if (debug)
        fprintf(stderr,"\nDebug: reading %s succesful\n",name);
}

void read_rules(char* name,rule_t* rules)
{
    FILE *plik = fopen(name,"r");
    char c;
    c=fgetc(plik);
    int n=c - '0';
    if (debug)
        printf("%d",n);
    int i;
    c=fgetc(plik);
    for (i=0;i<n;i++)
    {
        c=fgetc(plik);

        int nvar=c-'0';
        c=fgetc(plik);
        c=fgetc(plik);
        int nops=c-'0';
        rules[i] = rule_init(nvar,nops);
        int a=0,b=0;
        for (a=0 ; a<nvar ; a++)
        {
            rules[i].negations[a]=false;
        }
        a=0;
        if (debug)
            printf("\n%d. ",i);
        c=fgetc(plik);
        while (c!='\n' && c!=EOF)
        {
            if (debug)
                printf("%c",c);
            if(c!='=' && c!='&' && c!='|' && c!='!' && c!=' ')
            {
                rules[i].names[a]=c;
                a++;

            }
            else if (c=='!')
            {
                rules[i].negations[a]=true;
            }
            else if (c=='&' || c=='|')
            {
                rules[i].operators[b]=c;
                b++;
            }
            c=fgetc(plik);
        }
    }
    fclose(plik);
    if (debug)
        fprintf(stderr,"\nDebug: reading %s succesful\n",name);
}

zmienne_t* data_init(int number)
{
    zmienne_t *temp = malloc(sizeof(zmienne_t));
    temp->cap=number;

    temp->names = malloc(number* sizeof (char));
    temp->values = malloc(number* sizeof (char));

    return temp;
}

rule_t rule_init(int a,int b)
{
    rule_t *temp= malloc(sizeof *temp);
    temp->nvar=a;
    temp->nops=b;
    temp->counted=false;

    temp->names = malloc(a* sizeof (char));
    temp->negations = malloc(a* sizeof (bool));
    temp->operators = malloc(b* sizeof(char));

    return *temp;
}

void show_struct(zmienne_t *temp)
{
    int n=temp->cap;
    printf("%d\n",n);
    int i;
    for (i=0 ; i<n ; i++)
    {
        printf("%c=%c\n",temp->names[i],temp->values[i]);
    }

}
void show_rule(rule_t* rules, int n , int s)
{
    int j, k =0;
    if (s>n)
    {
        printf("There's no such rule!");
        return;
    }
    for (j = 0 ; j<rules[s].nvar ; j++)
        {
            if(rules[s].negations[j]==true)
                printf("!");

            printf("%c ",rules[s].names[j]);

            if (k<rules[s].nops)
                printf("%c ", rules[s].operators[k]);
            else if (k==rules[s].nops)
                printf("= ");

            k++;
        }
    printf("\n");
}
void show_rules(rule_t* rules, int n)
{
    int i;
    for(i=0 ; i<n ; i++)
    {
        show_rule(rules,n,i);
    }
}

char get_value(char s, zmienne_t* dane)
{
    int i;
    for(i = 0 ; i<dane->cap ; i++)
    {
        if(dane->names[i]==s)
        {
            return dane->values[i];
        }
    }
    return 'X';//Sth went wrong
}

void set_value(char v , char s, zmienne_t* dane)
{
    int i;
    for(i = 0 ; i<dane->cap ; i++)
    {
        if(dane->names[i]==s)
        {
            dane->values[i] = v;
        }
    }
}
