#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "files.c"

int main()
{

    zmienne_t* dane = data_init(3);
    rule_t* rules;
    read_data("dane.txt",dane);
    show_struct(dane);

    return 0;
}
