#include <stdio.h>

int main()
{
    int year_birth,month_birth,day_birth; //出生日期
    int year_now,month_now,day_now; //今天的日期
    int remaining_days=0; //定义一个剩余天数（出生那天到当年年末的天数）
    int passed_day=0; //定义今年走过的天数（从今年年初到现在的天数）
    int survival_days;//最后存活的天数
    int day_sum=0; //定义中间那些年的天数总和
    int i; //小哨兵

    //输入所需的出生年月日和今天的年月日
    printf("请按顺序输入自己出生的年、月、日:\n");
    scanf("%d %d %d",&year_birth,&month_birth,&day_birth);
    printf("请按顺序输入今天的年、月、日:\n");
    scanf("%d %d %d",&year_now,&month_now,&day_now);
    //由于构思框架对目前的我来说较为复杂，所以暂不重点考虑所输入的年、月、日是否合理的情况

    //首先计算出生那天距离年末的天数
    switch(month_birth)
    {
        case 1:
        {
            remaining_days+=31;
        }
        case 2:
        {
            if(((year_birth%4==0) && (year_birth%100!=0)) || (year_birth%400==0)) //满足此条件就为闰年
            {
                remaining_days+=29;
            }
            else
            {
                remaining_days+=28;
            }
        }
        case 3:
        {
            remaining_days+=31;
        }
        case 4:
        {
            remaining_days+=30;
        }
        case 5:
        {
            remaining_days+=31;
        }
        case 6:
        {
            remaining_days+=30;
        }
        case 7:
        {
            remaining_days+=31;
        }
        case 8:
        {
            remaining_days+=31;
        }
        case 9:
        {
            remaining_days+=30;
        }
        case 10:
        {
            remaining_days+=31;
        }
        case 11:
        {
            remaining_days+=30;
        }
        case 12:
        {
            remaining_days+=31;
        }
    }
    remaining_days=remaining_days-day_birth;

    //计算中间年的天数
    for(i=(year_birth+1);i<year_now;i++)
    {
        if(((i%4==0) && (i%100!=0)) || (i%400==0)) //判断中间年份哪些是闰年
        {
            day_sum+=366;
        }
        else
        {
            day_sum+=365;
        }
    }

    //计算从今年年初到现在的天数
    switch(month_now-1)
    {
        case 11:
        {
            passed_day+=30;
        }
        case 10:
        {
            passed_day+=31;
        }
        case 9:
        {
            passed_day+=30;
        }
        case 8:
        {
            passed_day+=31;
        }
        case 7:
        {
            passed_day+=31;
        }
        case 6:
        {
            passed_day+=30;
        }
        case 5:
        {
            passed_day+=31;
        }
        case 4:
        {
            passed_day+=30;
        }
        case 3:
        {
            passed_day+=31;
        }
        case 2:
        {
            if(((year_now%4==0) && (year_now%100!=0)) || (year_now%400==0)) //满足此条件就为闰年
            {
                passed_day+=29;
            }
            else
            {
                passed_day+=28;
            }
        }
        case 1:
        {
            passed_day+=31;
        }
    }
    passed_day+=day_now;

    //想不出其他办法了，用蠢办法
    /*if((month_now==1)||(month_now==3)||(month_now==5)||(month_now==7)||(month_now==8)||(month_now==10)||(month_now==12))
    {
        passed_day-=(31-day_now);
    }
    else if((month_now==4)||(month_now==6)||(month_now==9)||(month_now==11))
    {
        passed_day-=(30-day_now);
    }
    else if(month_now==2)
    {
        if(((year%4==0) && (year%100!=0)) || (year%400==0))
        {
            passed_day-=(29-day_now);
        }
        else
        {
            passed_day-=(28-day_now);
        }
    }*/

    //最后让三个天数相加
    survival_days=remaining_days+passed_day+day_sum;
    printf("恭喜，你已经存活了%d天!\n",survival_days);

    return 0;
}