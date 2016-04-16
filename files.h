#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED


typedef struct
{
    int cap;
    char* names;
    char* values;
}   zmienne_t;

int test();

void read_file(char*,zmienne_t*);

zmienne_t* data_init(int);

void show_struct(zmienne_t*);

#endif // FILES_H_INCLUDED
