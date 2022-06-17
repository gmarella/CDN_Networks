#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

static unsgined long int get_current_unix_tsp(void) {
     return (unsigned long it) time(NULL);
}

int genrator(void){
     // Process for getting Unix timeatamp
     unsigned long int StartingTimeStamp = get_current_unix_tsp();

     //Process for generating unique IP Addresses
     int val1 = 192;
     int val2 = 168;
     int val3 = 0;
     int val4 = 0;

     // Loop for generating 1000 IP Addresses
     for (int count = 0; count < 2; count++) {
         if (val4 < 255) {
             val4 += 1;
         } else if (val3 < 255) {
             val3 += 1;
             val4 = 0;
         } else if (val2 < 255) {
             val2 += 1;
             val3 += 0;
             val4 = 0;
         } else if (val1 < 255) {
             val1 += 1;
             val2 = 0;
             val3 = 0;
             val4 = 0;
         } else
             break;

         // Variabes for storing 4 partitions of IP address
         char IP_Part1[10];
         char IP_Part2[10];
         char IP_Part3[10];
         char IP_Part4[10];

         // Converting IP address integer values to string
         sprintf(IP_Part1, "%d", val1);
         sprintf(IP_Part2, "%d", val2);
         sprintf(IP_Part3, "%d", val3);
         sprintf(IP_Part4, "%d", val4);

         // Combining all parts of IP address
         char IP_Address[100];
         sprintf(IP_Address, "%s.%s.%s.%s", IP_Part1, IP_Part2, IP_Part3, IP_Part4);

         // Assigning Utilization to every IP Address
         int total_time =60*24; // Number of minutes for a day
         //Creating a new file based on IP address and assigning a pointer to it
         char mainPath[200]="C:\\Users\\rmste\\CLionProjects\\Temp_Project\\10-31-2014\\";
         char format[15]=".txt";
         char path[100];
         //Creating seperate file for every IP address
         sprintf(path,"%s%s%s",mainPath,IP_Address,format);
         FILE *ftpr= fopen(path,"w");

         for (int minute = 0; minute < total_time; minute += 1) {
             StartingTimeStamp+=60;
             int randomUsage1,randomUsage2;
             randomUsage1=rand()%100;
             randomUsage2=rand()%100;
             char log1[500];
             char log2[500];
             char TimeStamp[10];
             char cpu1Usage[10];
             char cpu2Usage[10];
             sprintf(TimeStamp, "%d",StartingTimeStamp);
             sprintf(cpu1Usage, "%d",randomUsage1);
             sprintf(cpu2Usage,"%d",randomUsage2);
             sprintf(log1,"%s %s %s %s",TimeStamp,IP_Address,"0",cpu1Usage);
             sprintf(log2,"%s %s %s %s",TimeStamp,IP_Address,"1",cpu2Usage);
             fprintf(ftpr,"%s\n",log1);
             fprintf(ftpr,"%s\n",log2);
         }
         fclose(ftpr);
     }
     return 0;
}
