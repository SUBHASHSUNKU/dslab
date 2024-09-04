#include <stdio.h>

typedef struct{
  int hour;
  int min;
  int sec;
}time;
//function to read time
void readtime(time *t){
     printf("enter hour:");
     scanf("%d", &t->hour);
     printf("enter min:");
     scanf("%d", &t->min);
     printf("enter sec:");
     scanf("%d", &t->sec);
}
//function to display time
time displaytime(time t){
printf("%02d:%02d:%02d",t.hour,t.min,t.sec);
}
//function to add time
time addtime(time t1,time t2)
{
    time result;
    result.sec=t1.sec+t2.sec;
    result.min=t1.min+t2.min+result.sec/60;
    result.hour=t1.hour+t2.hour+result.min/60;
    result.sec %= 60;
    result.min %= 60;
    result.hour %= 24;
    return result;
}
//function to find diff of time
time timediff(time t1,time t2)
{
       time result1;
    result1.sec = t1.sec - t2.sec;
    result1.min = t1.min - t2.min + (result1.sec < 0 ? 1 : 0);
    result1.hour = t1.hour - t2.hour + (result1.min < 0 ? 1 : 0);
    result1.sec += (result1.sec < 0 ? 60 : 0);
    result1.min += (result1.min < 0 ? 60 : 0);
    result1.hour += (result1.hour < 0 ? 24 : 0);
    result1.hour %= 24;
    return result1;
}

int main()
{
    time t1,t2,sumtime,difftime;
    printf("enter time t1\n");
    readtime(&t1);
    printf("enter time t2\n");
    readtime(&t2);

    sumtime=addtime(t1,t2);
    difftime=timediff(t1,t2);

    printf("sum: ");
    displaytime(sumtime);
    printf("\ndiff: ");
    displaytime(difftime);

    return 0;
}




