#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdint.h>
#include <stdlib.h>
#include "temp_functions.h"


int main (int argc, char *argv[])
{
    int rez = 0;                    //переменная для считывания аргументов командной строки
    char* str_file ="-1";           //переменная для записи названия файла из аргумента командной строки
    char* str_month ="-1";          //переменная для записи номера месяца из аргумента командной строки
    //struct data info[MAX_MASSIVE];
    //struct data* info = NULL;
    //(*info) = malloc(MAX_MASSIVE * sizeof(*info));
    struct data* info;
    info = malloc(MAX_MASSIVE);


    while ((rez = getopt(argc,argv,"hf: m:")) != -1)
    {
        switch (rez)
        {
        case 'h': printf ("Temperature Statistic Aplication\n -h = help\n -f = filename.csv\n -m = number month\n");break;
        case 'f': printf ("File = %s\n",optarg); str_file = optarg; break;
        case 'm': printf ("Month = %s\n",optarg); str_month = optarg; break;
        case '?': printf ("Error found\n");break;
        }
    }

    if (str_file == "-1")           // если файл не был введен
    {
        printf ("Temperature Statistic Aplication\n");
        printf ("error input file\n");
        printf ("please enter <-h> for help\n");
        getchar();
    }
    openfile (str_file, info);
    print_info(str_month, info);

    return 0;
    
}