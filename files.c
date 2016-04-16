#include "files.h"

int test ()
{
    return 1;
}
void read_file(char* name,zmienne_t* temp)
{
    FILE *plik = fopen(name,"r");
    char c;
    c=fgetc(plik);
    int n=c - '0';
    printf("%d",n);
    c=fgetc(plik);
    int i;
    bool isvalue=false;
    int name_length=0;
    for (i=0;i<n;i++)
    {
        isvalue=false;
        name_length=0;
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

    if (fclose(plik))
        fprintf(stderr,"\nDebug: reading succesful\n");
}

zmienne_t* data_init(int number)
{
    zmienne_t *temp = malloc(sizeof *temp);
    temp->cap=number;

    temp->names = malloc(number*sizeof (char));
    temp->values = malloc(number * sizeof (char));

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
