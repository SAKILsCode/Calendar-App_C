#include <stdio.h>

//func to get the first day of the year
int getFirstDayOfYear(int year){
    int day = (year*365 + ((year-1) / 4) - ((year-1) / 100) + ((year-1) / 400)) % 7;
    return day;
}

int main(){

    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int lastDayInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int i, j, totalDaysInMonth, daysLeftInWeek = 0, year;

    printf("Show me the calendar of the year of_ ");
    scanf("%d", &year);

    // Checking if it is leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        lastDayInMonth[1] = 29;
    }

    //First day of the year
    daysLeftInWeek = getFirstDayOfYear(year);
    
    for (i = 0; i < 12; i++)
    {
        printf("\n\n=================== %s ===================\n", months[i]);
        printf("\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n");
        totalDaysInMonth = lastDayInMonth[i];

        // Printing space before the day from where the month starts.
        for (int i = 0; i < daysLeftInWeek; i++)
        {
            printf("      ");
        }
        
        for (j = 1; j <= totalDaysInMonth; j++)
        {
            printf("%6d", j);

            daysLeftInWeek++;
            if (daysLeftInWeek > 6){
                daysLeftInWeek = 0;
                printf("\n");
            }
        }
        printf("\n");
        printf("\n");
    }
    

    return 0;
}