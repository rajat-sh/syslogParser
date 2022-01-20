#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    long int countEmer = 0,countAlert = 0, countCritcal = 0, countWarn = 0, countNotice = 0, countInfo =0, countDebug = 0;
    char   notice[10];
    char   syslogid[10];
    int x,i;
    int arr1[100000] = {0};
    int arr2[100000] = {0};
    char filename[100];
     
    printf("Enter the name of the log file: ");
    scanf("%s", &filename);
    fp = fopen(filename, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
       /* printf("Retrieved line of length %zu:\n", read);*/
       /* printf("%.*s\n",6, line + 78);*/
	strncpy(syslogid, line+78, 6);
	int i = (atoi(syslogid)) % 100000;
	arr1[i] = atoi(syslogid);
	++arr2[i];
	strncpy(notice, line+76, 1);
	int x = atoi(notice) ;
	switch(x)
	{
		case 1:
			++countEmer;
			break;
		case 2:
			++countAlert;
			break;
		case 3:
			++countCritcal;
			break;
		case 4:
			++countWarn;
			break;
		case 5:
			++countNotice;
			break;
		case 6:
			++countInfo;
			break;
		case 7:
			++countDebug;
			break;
	}


    }	
   long    int totalSyslogs = countEmer + countAlert + countCritcal + countWarn + countNotice + countInfo + countDebug;
	
    printf("Total number of syslogs is %ld\n", totalSyslogs);
    printf("Count of Emergency syslogs is %ld\n", countEmer);
    printf("Count of Alert syslogs is %ld\n", countAlert);
   printf("Count of critical syslogs is %ld\n", countCritcal);
   printf("Count of warning syslogs is %ld\n", countWarn);
   printf("Count of notification syslogs is %ld\n", countNotice);
  printf("Count of Informational syslogs is %ld\n", countInfo);
  printf("Count of Debug syslogs is %ld\n", countDebug);	
  for(i = 0; i < 100000; ++i)
  {
	if(arr1[i] != 0)
	{
		printf("syslog ID %d Count %d\n", arr1[i], arr2[i]);
	}
  }	
    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
