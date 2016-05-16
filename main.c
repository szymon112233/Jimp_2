#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include<conio.h>
#include "files.c"
#include "chaining.c"



int main(int argc, char* argv[])
{
    if( argc !=4) {
		fprintf( stderr, "Wrong number of arguments !" );
		return EXIT_FAILURE;
	}
	char chaining = 'f'; // forward chaining

    if (strcmp(argv[3],"-b")==0)
    {
        chaining = 'b';
    }


	int rules_count=get_data_cap(argv[2]);
	zmienne_t* dane = data_init(get_data_cap(argv[1]));
	read_data(argv[1],dane);
	rule_t rules[rules_count];
    read_rules(argv[2],rules);
    char question;

    printf("Decision engine: Forward and backward Chaining \nWhat are you looking for ?\n");

    while(question=getch())
    {
        //show_struct(dane);
        //show_rules(rules,rules_count);

        if (chaining=='b')
            bchain(question, dane, rules, rules_count);
        else
            fchain(question, dane, rules, rules_count);
    }
    return 0;
}
