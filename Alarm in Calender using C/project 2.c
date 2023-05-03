#include<stdio.h>

int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]={" ","\n\n\nJanuary","\n\n\nFebruary","\n\n\nMarch","\n\n\nApril","\n\n\nMay","\n\n\nJune","\n\n\nJuly","\n\n\nAugust","\n\n\nSeptember","\n\n\nOctober","\n\n\nNovember","\n\n\nDecember"};
int inputyear()
{
    int year;
    printf("Please enter a year");
    scanf("%d",&year);
    return year;
}
int determinedaycode (int year)
{
    int daycode;
    int d1,d2,d3;
    d1=(year-1)/4.0;
    d2=(year-1)/100;
    d3=(year-1)/400;
    daycode=(year+d1-d2+d3)%7;
    return daycode;
}
int determineleapyear(int year)
{
    if(year%4==0 && year%100 !=0 || year%400==0)
       {
        days_in_month[2]=29;
        return 1;
       }

    else
       {
          days_in_month[2]=28;
        return 0;
       }
}
void calender(int year,int daycode)
{
    int month,day;
    for(month=1;month<=12;month++)
    {
       printf("%s",months[month]);
       printf("\n....................");
       printf("\n\n Sun  Mon  Tue  Wed  Thus  Fri  Sat\n\n") ;
       for(day=1;day<=1+daycode*5;day++)
       {
           printf(" ");
       }
       for(day=1;day<=days_in_month[month];day++)
       {
           printf(" %2d",day);
           if((day+daycode)%7>0)
            printf("  ");
           else
            printf("\n ");
       }
       daycode=(daycode+days_in_month[month])%7;

    }

}
int main()
{
    int daycode,year,leapyear;
    year=inputyear();
    daycode=determinedaycode(year);
    determineleapyear(year);
    calender(year,daycode);
    printf("\n");
    printf("Enter date & month to see event");
    int d,m;
    scanf("%d%d",&d,&m);
    if(d==16 && m==12)
    {
        printf("\a\a\a\a\a\a\a\a\a");
        printf("Event:Victory Day");
    }
    else if(d==26 && m==3)
    {
        printf("\a\a\a\a\a\a\a\a\a");
        printf("Event:Independence Day ");
    }
    else if(d==25 && m==12)
    {
        printf("\a\a\a\a\a\a\a\a\a");
        printf("Event:Christmas Day");
    }
    else if(d==1 && m==5)
    {
        printf("\a\a\a\a\a\a\a\a\a");
        printf("Event:May Day");
    } else if(d==21 && m==2)
    {
        printf("\a\a\a\a\a\a\a\a\a");
        printf("Event:International Mother Language Day");
    }
    else {

            printf("no event found");
    }

}

