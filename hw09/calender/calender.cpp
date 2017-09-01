
#include "calender.h"
int cal[13] = {0,31, 28 ,31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Date::NextDay(int n )
{
    int days;
    days = ComputeDaysFromYearStart(year_, month_, day_)+n;
    if(days <=0)
    {
        year_--;
        days += GetDaysInYear(year_);
        
    }
    else if(days>GetDaysInYear(year_))
    {
        days -= GetDaysInYear(year_);
        year_++;
    }
    int i;
    for(i=1; ;i++)
    {
        if(GetDaysInYear(year_)==366 && i==2)
        {
            if(days-cal[i]-1 >0)
                days -=cal[i]+1;
            else
                break;
        }
        else
        {
            if(days-cal[i]>0)
                days -=cal[i];
            else break;
        }
    }
    month_=i;
    day_=days;
    
}
bool Date::SetDate(int year, int month, int day)
{
    if(month<=0 || month>12 || day<=0) return false;
    if(month==2 && GetDaysInYear(year)==366)
    {
        if(day>cal[month]+1)
            return false;
    }
    else if(day>cal[month]) return false;
   
    year_=year;
    month_= month;
    day_= day;
    return true;
}

int Date::ComputeDaysFromYearStart(int year, int month, int day)
{
    int date=0;
    for(int i =1; i<month; i++)
    {
        date += cal[i];
        if(i==2 && GetDaysInYear(year)==366)
                date++;
    }

    return date+day;
}

int Date::GetDaysInYear(int year)
{
    if((year%4==0 && year%100!=0) || year%400==0)
        return 366;
    else
        return 365;
}

ostream& operator<<(ostream& os, const Date& c)
{
    os << c.year() << "." << c.month() << "." << c.day();
    return os;
 }
#include <stdio.h>
istream& operator>>(istream& is, Date& c)
{
    int yy,mm,dd;
    scanf("%d.%d.%d",&yy,&mm,&dd);
    if(c.SetDate(yy,mm,dd)==false)
        throw InvalidDateException(to_string(yy)+"."+to_string(mm)+"."+to_string(dd));
    return is;
    
}
