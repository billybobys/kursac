#include "temp_functions.h"
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdint.h>
#include <stdlib.h>

unsigned int counter_str = 0;   //счетчик строк в файле

int middle_temp_month (struct data info[],int number_month)
{   
    int sum_temp_month = 0;
    int mean_month = 0;
    int counter_str_month = 0;
    for (int cnt_mon = 0;cnt_mon < MAX_STRING;cnt_mon ++)
    {
        if (info[cnt_mon].month == number_month)
        {
            sum_temp_month += info[cnt_mon].temp;
            counter_str_month++;
        }
    }
    mean_month = sum_temp_month / counter_str_month;
    return (mean_month);
}

int min_temp_in_month(struct data info[],int number_month)
{
    int min_temp_month =99;
    for (int cnt_min_mon = 0;cnt_min_mon < MAX_STRING;cnt_min_mon ++)
    {
        if (info[cnt_min_mon].month == number_month)
        {
            if (info[cnt_min_mon].temp < min_temp_month)
            {
                min_temp_month = info[cnt_min_mon].temp;
            }
        }
    }
    return (min_temp_month);
}

int max_temp_month(struct data info[],int number_month)
{
    int max_temp_month = -99;
    for (int cnt_max_mon = 0;cnt_max_mon < MAX_STRING;cnt_max_mon ++)
    {
        if (info[cnt_max_mon].month == number_month)
        {
            if (info[cnt_max_mon].temp > max_temp_month)
            {
                max_temp_month = info[cnt_max_mon].temp;
            }
        }
    }
    return (max_temp_month);
}

int middle_temp_year(struct data info[])
{
    int mean_temp_year = 0;
    int cnt_max_year = 0;
    for (;cnt_max_year < MAX_STRING;cnt_max_year ++)
    {
        mean_temp_year += info[cnt_max_year].temp;
    }
    mean_temp_year /= cnt_max_year;
    return (mean_temp_year);
}

int min_temp_year (struct data info[])
{
    int min_temp_year = 99;
    for (int cnt_min_year = 0; cnt_min_year < MAX_STRING; cnt_min_year++)
    {
        if (min_temp_year > info[cnt_min_year].temp)
        {
            min_temp_year = info[cnt_min_year].temp;
        }
    }
    return (min_temp_year);
}

int max_temp_year (struct data info[])
{
    int max_temp_year = -99;
    for (int cnt_max_year = 0;cnt_max_year < MAX_STRING;cnt_max_year++)
    {
        if (info[cnt_max_year].temp > max_temp_year)
        {
            max_temp_year = info[cnt_max_year].temp;
        }
    }
    return (max_temp_year);
}

int print_info(char* str_month, struct data info[])
{   
    int month = 0;
    month = strtol(str_month, NULL, 10);
    int number_month = 1;
    int number_year = 0;
    if (month == -1)
    {
        printf ("Year\tMonth\t\tMonthAvg\tMonthMax\tMonthMin\n");
        for (int cnt = 0;cnt < 12;cnt++)
        {
            for (int cnt2 = 0;cnt2 < MAX_STRING;cnt2++)
            {
                if (info[cnt2].month == number_month)
                {
                    number_year = info[cnt2].year;
                }
            }
            printf ("%d\t%d\t\t%d\t\t%d\t\t%d\n", number_year, number_month, middle_temp_month(info,number_month),max_temp_month (info,number_month),min_temp_in_month (info,number_month));
            number_month++;
        }
        printf("Year statistic:\taverage = %d,minimum = %d, maximum = %d\n",middle_temp_year(info),min_temp_year(info),max_temp_year(info));
    }
    else
    {
        number_month = month;
        printf ("Year\tMonth\t\tMonthAvg\tMonthMax\tMonthMin\n");
        for (int cnt3 = 0;cnt3 < MAX_STRING;cnt3++)
            {
                if (info[cnt3].month == number_month)
                {
                    number_year = info[cnt3].year;
                }
            }
        printf ("%d\t%d\t\t%d\t\t%d\t\t%d\n", number_year, number_month, middle_temp_month(info,number_month),max_temp_month (info,number_month),min_temp_in_month (info,number_month));
    }
    
}

int openfile (char* str_file, struct data info[])
{
    int y=0,m=0,d=0,h=0,min=0,t=0;  //переменные для записи чисел из файла в массив
    int r = 0;                      //переменная для сравнения считаных чисел с define MAX_NUMBERS_IN_STRING
    int i = 0;                      //счетчик для записи чисел в массив

    FILE *openfile;
    openfile = fopen (str_file, "r");
    if (openfile == NULL)
        perror("cant open file");
    
    while((r=fscanf(openfile,"%d;%d;%d;%d;%d;%d",&y,&m,&d,&h,&min,&t))>0)
    {   
        counter_str++;
        if (r < MAX_NUMBERS_IN_STRING)                      //проверка на ошибки в строчках
        {
            char s[20];
            r = fscanf (openfile,"%[^\n]",s);
            printf ("IN STRING %d ERROR!\n",counter_str);
        }

        info[i].year = y;
        info[i].month = m;
        info[i].day = d;
        info[i].hour = h;
        info[i].minute = min;
        info[i].temp = t;
        i++;

    }
}