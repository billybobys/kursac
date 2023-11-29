#include <stdint.h>
#define MAX_MASSIVE 525600
#define MAX_NUMBERS_IN_STRING 6
#define MAX_STRING counter_str

struct data
{
    uint16_t year;
    uint8_t day;
    uint8_t month;
    uint8_t hour;
    uint8_t minute;
    int8_t temp;
};
int middle_temp_month (struct data info[],int number_month);
int min_temp_in_month(struct data info[],int number_month);
int max_temp_month(struct data info[],int number_month);
int middle_temp_year(struct data info[]);
int min_temp_year (struct data info[]);
int max_temp_year (struct data info[]);
int print_info(char* str_month,struct data info[]);
int openfile (char* str_file, struct data info[]);
