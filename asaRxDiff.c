#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE * fp;
    FILE * fp1;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    
    char  packetCount[100];
    int x,i;
    long  int arr1[1000] = {0};
    long int arr2[1000] = {0};
    long int arr3[1000] = {0};
    char filename[100];
    char *ret;
    char *ret1;
    char* end;
    long int result;
     
    fp = fopen("interface1", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    i = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
	
	ret = strstr(line, "RX");
	
	if(ret)
	{
		strncpy(packetCount, line+11, 12);
		/*printf("%s\n", packetCount);*/
		arr1[i] = strtoul(packetCount, &end, 10);		
		++i;

	}
    }
    
    fp1 = fopen("interface4", "r");
    if (fp1 == NULL)
        exit(EXIT_FAILURE);
    i = 0;

    while ((read = getline(&line, &len, fp1)) != -1) {

        ret = strstr(line, "RX");
        if (ret)
        {       
                strncpy(packetCount, line+11, 12);
                /*printf("%s\n", packetCount);*/
                arr2[i] = strtoul(packetCount, &end, 10);
                ++i;

        }
    }
    for(i = 0; i < 1000; ++i)
     {
	if(arr1[i] != 0)
	{
		arr3[i] = (arr2[i] - arr1[i]);
		
	}
  }
	
	printf("Second column is the RX ring number\n");
	printf("Third column is the initial count\n");
	printf("Fourth column is the final count\n");
	printf("last column is the diff\n");
        printf("\n");
	printf("\n");
	for(i = 0; i < 150; ++i)
     {  
       
		if(i < 75)
		{	
                	printf("RX%5d %15ld   %15ld  %15ld \n",i,  arr1[i], arr2[i], arr3[i] );
        	}
		else
		{
			printf("RX%5d %15ld   %15ld  %15ld \n",(i-75),  arr1[i], arr2[i], arr3[i] );
		}
  }     	
	

	result = 0;
      for(i = 0; i < 150; ++i)
	{
		result = result + arr3[i];
	}
	printf("Total packets handled by both RX ring is %ld\n", result);






	
    	
    fclose(fp);
    fclose(fp1);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
