#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>


int main() {
    char mainPath[100]="C:\\Users\\rmste\\CLionProjects\\Temp_Project\\10-31-2014\\";
    printf("Enter IP Address, CPU ID,Start Date(YYYY-MM-DD), Start Time(HH:MM),End Date (YYYY-MM-DD), End Time(HH:MM)\n"
           "Example: 192.168.1.10 1 2014-10-31 00:00 2014-10-31 00:05\n");
    char input[100];
    fflush(stdin);
    fgets(input, 500, stdin);

    int len=strlen(input);
    char targetIp[100];
    char targetCpuId[5];
    char targetStartDate[15];
    char targetStartTime[25];
    char targetEndDate[25];
    char targetEndTime[30];

    strncpy(targetIp,&input[0],12);
    targetIp[12]='\0';
    strncpy(targetCpuId,&input[13],1);
    targetCpuId[1]='\0';
    strncpy(targetStartDate,&input[15],10);
    targetCpuId[10]='\0';
    strncpy(targetStartTime,&input[26],5);
    targetCpuId[5]='\0';
    strncpy(targetEndDate,&input[32],11);
    targetEndDate[11]='\0';
    strncpy(targetEndTime,&input[43],5);
    targetEndTime[5]='\0';
    printf(targetIp);
    char format[15]=".txt";
    char path[100];
    //Creating seperate file for every IP address
    sprintf(path,"%s%s%s",mainPath,targetIp,format);
    printf(path);

}






