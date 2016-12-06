#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
struct TIME{
  int seconds;
  int minutes;
  int hours;
};
void Difference(struct TIME t1, struct TIME t2, struct TIME *diff);

int main(){
    struct TIME t1,t2,diff;
      time_t rawtime;
  struct tm * timeinfo;
char hour[3];
char min[3];
FILE *fp;
char buff[5];
FILE *fp1;
char buff2[20];

   t1.hours=9;
  t1.minutes=0;
   t1.seconds=0;
  t2.minutes=4;
    
time ( &rawtime );
    timeinfo = localtime ( &rawtime );
/*
printf("[%d %d %d %d:%d:%d]",timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);*/
    
//printf("%d:%d:%d",timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
//sprintf(output, "%d:%d:%d",timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
//sprintf(output, "%d:%d",timeinfo->tm_hour, timeinfo->tm_min);
sprintf(hour, "%d",timeinfo->tm_hour);
sprintf(min, "%d",timeinfo->tm_min);


printf("\n ============%s=============== \n",hour);
printf("\n ============%s=============== \n",min);

//Difference(timeinfo->tm_min,t2.minutes,&diff);
// printf("%d:%d:%d ",t2.hours,t2.minutes,t2.seconds);
//    printf("= %d:%d:%d\n",diff.hours,diff.minutes,diff.seconds);

int dif;

 dif=timeinfo->tm_min+t2.minutes;
    printf("=%d:\n",dif);

while(1)
{
  fp = fopen("status.strm", "r");
if(fp==NULL){
      printf("Error!");   
     exit(1);             
   }
  fscanf(fp,"%s",&buff); 
if(strcmp(buff,"P")==0)
{


if(timeinfo->tm_min >=00 && timeinfo->tm_min < 8 )
//if((timeinfo->tm_hour>=16) && (timeinfo->tm_min >=50))
// && timeinfo->tm_hour<=17 && timeinfo->tm_min<=30)
//if(hour>9 && min >15 && hour<=10 && min<=30)
{
sleep(2);
printf("firts class");
system("leafpad ./sylabus/1.txt");
sleep(2);

}
else if(timeinfo->tm_min >=8 && timeinfo->tm_min <16 )
//else if(timeinfo->tm_hour>=17 && timeinfo->tm_min >=02 && (timeinfo->tm_hour<17 && timeinfo->tm_min <46)) 
//if(hour>10 && min >30 && hour<=11 && min <=15)
{
sleep(2);
printf("secord class");
system("killall leafpad");
system("leafpad ./sylabus/2.txt");
sleep(2);

}
else if(timeinfo->tm_min >=16  && timeinfo->tm_min < 24 )
//else if(timeinfo->tm_hour>=17 && timeinfo->tm_min >=46 ) 
{
sleep(2);
printf("third class");
system("killall leafpad");
system("leafpad ./sylabus/3.txt");
sleep(2);

}
else if(timeinfo->tm_min >=24  && timeinfo->tm_min < 32)
//else if(timeinfo->tm_hour>=18 && timeinfo->tm_min >=02) 
{
sleep(2);
printf("fourth class");
system("killall leafpad");
system("leafpad ./sylabus/4.txt");
sleep(2);

}
else if(timeinfo->tm_min >=32 && timeinfo->tm_min < 40)
//else if(timeinfo->tm_hour>=17 && timeinfo->tm_min >=30 && timeinfo->tm_hour<=18 && timeinfo->tm_min <=15)
{
sleep(2);
printf("FIFTH class");
system("killall leafpad");
system("leafpad ./sylabus/5.txt");
sleep(2);


}
else if(timeinfo->tm_min >=40 && timeinfo->tm_min < 48)
//else if(timeinfo->tm_hour>=19 && timeinfo->tm_min >=30 && timeinfo->tm_hour<=20 && timeinfo->tm_min <=15)
{
sleep(2);
printf("sixth class");
system("killall leafpad");
system("leafpad ./sylabus/6.txt");
sleep(2);


}
else if(timeinfo->tm_min >=48 && timeinfo->tm_min < 56)
//else if(timeinfo->tm_hour>=20 && timeinfo->tm_min >=15 && timeinfo->tm_hour<=21 && timeinfo->tm_min <=30)
{
sleep(2);
printf("seventh class");
system("killall leafpad");
system("leafpad ./sylabus/7.txt");
sleep(2);

}
else if(timeinfo->tm_min >=56 && timeinfo->tm_min < 64)
//else if(timeinfo->tm_hour>=20 && timeinfo->tm_min >=15 && timeinfo->tm_hour<=21 && timeinfo->tm_min <=30)
{
sleep(2);
printf("eighth class");
system("killall leafpad");
system("leafpad ./sylabus/8.txt");
sleep(2);

}
}
else if(strcmp(buff,"N")==0)
{
printf("teacher not present");
system("./sendclass.bin 10.0.0.13 1238");
system("./recv2.bin");

fp1 = fopen("class.strm", "r");

   fscanf(fp1, "%s", buff2);
  
 printf( "%s", buff2);




  fclose(fp1);
if(strcmp(buff,"S1")==0)
{
sleep(2);
printf("sub class1");
system("killall leafpad");
system("leafpad ./sylabus/8.txt");
sleep(2);
}
else if(strcmp(buff,"S2")==0)
{
printf("sub class2");
system("killall leafpad");
system("leafpad ./sylabus/8.txt");
sleep(2);

}


}
 
}
    return 0;
}

void Difference(struct TIME t1, struct TIME t2, struct TIME *differ){
    if(t2.seconds>t1.seconds){
        --t1.minutes;
        t1.seconds+=60;
    }
    differ->seconds=t1.seconds-t2.seconds;
    if(t2.minutes>t1.minutes){
        --t1.hours;
        t1.minutes+=60;
    }
    differ->minutes=t1.minutes-t2.minutes;
    differ->hours=t1.hours-t2.hours;
}
