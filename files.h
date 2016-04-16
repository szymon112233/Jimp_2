#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED


typedef struct
{
    int cap;
    char* names;
    char* values;
}   zmienne_t;

typedef struct
{
    int nvar,nops;
    char* names;//last name = name of result
    char* operators;
    bool* negations;
}   rule_t;

void read_data(char*,zmienne_t*);

void read_rules(char*,rule_t*);

zmienne_t* data_init(int);

rule_t* rule_init(int ,int );

void show_struct(zmienne_t*);

#endif // FILES_H_INCLUDED
