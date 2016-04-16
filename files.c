#include "files.h"


void read_data(char* name,zmienne_t* temp)
{
    FILE *plik = fopen(name,"r");
    char c;
    c=fgetc(plik);
    int n=c - '0';
    printf("%d",n);
    c=fgetc(plik);
    int i;
    bool isvalue=false;
    //int name_length=0;
    for (i=0;i<n;i++)
    {
        isvalue=false;
        printf("\n%d. ",i);
        c=fgetc(plik);
        while (c!='\n')
        {
            printf("%c",c);
            if(c!='=')
            {
                if (isvalue)
                    temp->values[i]=c;
                else
                {

                    temp->names[i]=c;
                    //to do wpisywanie nazw wieloznakowych
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
    fprintf(stderr,"\nDebug: reading %s succesful\n",name);
}

void read_rules(char* name,rule_t* rules)
{
    FILE *plik = fopen(name,"r");
    char c;
    c=fgetc(plik);
    int n=c - '0';
    printf("%d",n);
    int i;
    for (i=0;i<n;i++)
    {

        c=fgetc(plik);
        rules->nvar=c-'0';
        c=fgetc(plik);
        c=fgetc(plik);
        rules->nops=c-'0';
        int a=0,b=0;
        printf("\n%d. ",i);
        c=fgetc(plik);
        while (c!='\n')
        {
            printf("%c",c);
            if(c!='=' && c!='&' && c!='|' && c!='!')
            {
                rules[i].names[a]=c;
                a++;

            }
            else if (c!='!')
            {
                rules[i].negations[a]=c;
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
    fprintf(stderr,"\nDebug: reading %s succesful\n",name);
}

zmienne_t* data_init(int number)
{
    zmienne_t *temp = malloc(sizeof *temp);
    temp->cap=number;

    temp->names = malloc(number*sizeof (char));
    temp->values = malloc(number * sizeof (char));

    return temp;
}

rule_t* rule_init(int a,int b)
{
    rule_t *temp= malloc(sizeof *temp);
    temp->nvar=a;
    temp->nops=b;

    temp->names = malloc(a* sizeof (char));
    temp->negations = malloc(a* sizeof (bool));
    temp->operators = malloc(b* sizeof(char));

    return temp;
}

void show_struct(zmienne_t *temp)
{
    int n=temp->cap+1;
    printf("%d\n",n);
    int i;
    for (i=0 ; i<n ; i++)
    {
        printf("%c=%c\n",temp->names[i],temp->values[i]);
    }

}
