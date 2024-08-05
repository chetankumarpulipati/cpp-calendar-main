#include <iostream>
#include <iomanip>  // Corrected include statement

using namespace std;

#define TRUE 1
#define FALSE 0

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *months[] = {  // Changed to const char*
    " ",
    "\n\n\nJanuary", "\n\n\nFebruary", "\n\n\nMarch",
    "\n\n\nApril", "\n\n\nMay", "\n\n\nJune", "\n\n\nJuly",
    "\n\n\nAugust", "\n\n\nSeptember", "\n\n\nOctober",
    "\n\n\nNovember", "\n\n\nDecember"
};

int inputyear(void)
{
    int year;
    cout << "Please enter a year (example: 1999): ";
    cin >> year;
    cout << "Year entered: " << year << endl;  // Debugging statement
    return year;
}

int determinedaycode(int year)
{
    int daycode;
    int d1, d2, d3;
    d1 = (year - 1) / 4;
    d2 = (year - 1) / 100;
    d3 = (year - 1) / 400;
    daycode = (year + d1 - d2 + d3) % 7;
    cout << "Day code for the year " << year << ": " << daycode << endl;  // Debugging statement
    return daycode;
}

int determineleapyear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        days_in_month[2] = 29;
        cout << year << " is a leap year." << endl;  // Debugging statement
        return TRUE;
    }
    else
    {
        days_in_month[2] = 28;
        cout << year << " is not a leap year." << endl;  // Debugging statement
        return FALSE;
    }
}

void calendar(int year, int daycode)
{
    int month, day;
    for (month = 1; month <= 12; month++)
    {
        cout << months[month];
        cout << "\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n";

        // Correct spacing before the first day of the month
        for (int i = 0; i < daycode; i++)
        {
            cout << "     ";
        }

        for (day = 1; day <= days_in_month[month]; day++)
        {
            cout << setw(2) << day << "   ";
            if (++daycode > 6)
            {
                daycode = 0;
                cout << "\n";
            }
        }
        if (daycode != 0)
        {
            cout << "\n";
        }
    }
}

int main(void)
{
    int year, daycode;
    year = inputyear();
    daycode = determinedaycode(year);
    determineleapyear(year);
    calendar(year, daycode);
    cout << "\n";
    return 0;
}