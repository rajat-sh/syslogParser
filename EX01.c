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
    char  noBufferCount[100];
    char  lowCount[100];
    char  currentCount[100];
    char  cpuCount[100];
    char  cpu1Count[100];
    char  cpu2Count[100];
    char  datapathCount[100];
    char  numhogCount[100];
    char  maxhogCount[100];
    char  datapath1Count[100];
    char  numhog1Count[100];
    char  maxhog1Count[100];
    int x,i,j,k,l,m;
    long  int arr1[1000] = {0};
    long int arr2[1000] = {0};
    long int arr3[1000] = {0};
    long int arr4[10] = {0};
    long int arr5[10] = {0};
    long int arr6[1000] = {0};
    long int arr7[1000] = {0};
    long int arr8[1000] = {0};
    long int arr9[1000] = {0};
    long int arr10[200] = {0};
    long int arr11[200] = {0};
    long int arr12[200] = {0};
    long int arr13[200] = {0};
    long int arr14[200] = {0};
    long int arr15[200] = {0};
    long int arr16[200] = {0};
    long int arr17[200] = {0};
    long int arr18[200] = {0};
    long int arr19[200] = {0};
    long int arr20[200] = {0};
    long int arr21[200] = {0};
    long int arr22[200] = {0};
    long int arr23[200] = {0};
    long int arr24[200] = {0};
    long int arr25[200] = {0};
    long int arr26[200] = {0};
    long int arr27[200] = {0};
    char filename[100];
    char *ret;
    char *ret1;
    char* end;
    long int result;
    long int nobufferTotal = 0;
    
     
    fp = fopen("interface1", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    i = 0;
    j = 0;
    k = 0;
    l = 0;
    m = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
	
	ret = strstr(line, "RX");
	
	if(ret)
	{
		strncpy(packetCount, line+11, 12);
		/*printf("%s\n", packetCount);*/
		arr1[i] = strtoul(packetCount, &end, 10);		
		++i;

	}
	ret = strstr(line, "no buffer");
	if(ret)
        {
                strncpy(noBufferCount, line+56, 12);
                
                arr4[j] = strtoul(noBufferCount, &end, 10);
                ++j;

        }
	ret = strstr(line, "Blocks free curr");
        if(ret)
        {
                strncpy(lowCount, line+37, 3);

                arr6[k] = strtoul(lowCount, &end, 10);
                ++k;

        }
	ret = strstr(line, "Blocks free curr");
        if(ret)
        {
                strncpy(currentCount, line+33, 3);

                arr8[l] = strtoul(currentCount, &end, 10);
                ++l;

        }
	


	

    }
    
    fp1 = fopen("interface2", "r");
    if (fp1 == NULL)
        exit(EXIT_FAILURE);
    i = 0;
    j = 0;
    k = 0;
    l = 0;
    m = 0;

    while ((read = getline(&line, &len, fp1)) != -1) {

        ret = strstr(line, "RX");
        if (ret)
        {       
                strncpy(packetCount, line+11, 12);
                /*printf("%s\n", packetCount);*/
                arr2[i] = strtoul(packetCount, &end, 10);
                ++i;

        }
	ret = strstr(line, "no buffer");
        if(ret)
        {
                strncpy(noBufferCount, line+56, 12);
                
                arr5[j] = strtoul(noBufferCount, &end, 10);
                ++j;

        }
	ret = strstr(line, "Blocks free curr");
        if(ret)
        {       
                strncpy(lowCount, line+37, 3);
                
                arr7[k] = strtoul(lowCount, &end, 10);
                ++k;
        
        }
	ret = strstr(line, "Blocks free curr");
        if(ret)
        {
                strncpy(currentCount, line+33, 3);

                arr9[l] = strtoul(currentCount, &end, 10);
                ++l;

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


	printf("\nNo buffer Diff\n");
	for(i = 0; i < 5; ++i)
	{
		printf("%ld\n", arr5[i] - arr4[i]);
		nobufferTotal = nobufferTotal + (arr5[i] - arr4[i]);
	}
	printf("\nNo buffer Percentage is %f\n",(nobufferTotal * 100.0)/result );
	
	printf("\nRX ring LOW counter count and diff\n");
	for(i = 0; i < 214; ++i)
        {
		if(i < 64 || i > 149)
		{
			if(i < 64)
			{
                		printf("RX RING%d  %ld\t%ld\t%ld\n",i,  arr6[i], arr7[i], arr7[i] - arr6[i]);
			}
			else
			{
				printf("RX RING%d  %ld\t%ld\t%ld\n",i -150,  arr6[i], arr7[i], arr7[i] - arr6[i]);
			}
                }
		
		
        }
	printf("\nRX ring CUR counter count and diff\n");
	for(i = 0; i < 214; ++i)
        {
                if(i < 64 || i > 149)
                {
                        if(i < 64)
                        {
                                printf("RX RING%d  %ld\t%ld\t%ld\n",i,  arr8[i], arr9[i], arr9[i] - arr8[i]);
                        }
                        else
                        {
                                printf("RX RING%d  %ld\t%ld\t%ld\n",i -150,  arr8[i], arr9[i], arr9[i] - arr8[i]);
                        }
                }


        }
    fclose(fp);
    fclose(fp1);
    m = 0;
    j = 0;
    i = 0;
    fp = fopen("file1", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

      while ((read = getline(&line, &len, fp)) != -1) {

		ret = strstr(line, "+");
       		 if(ret)
        	{	       
                	strncpy(cpuCount, line+32, 2);
                	arr10[m] = strtoul(cpuCount, &end, 10);
                	++m;
			strncpy(cpu1Count, line+13, 2);
                        arr12[i] = strtoul(cpu1Count, &end, 10);
                        ++i;
			strncpy(cpu2Count, line+51, 2);
                        arr14[j] = strtoul(cpu2Count, &end, 10);
                        ++j;
			
        
        	}

	}
     m = 0;
     i = 0;
     j = 0;	
     fp1 = fopen("file2", "r");
        if (fp1 == NULL)
        	exit(EXIT_FAILURE);

        while ((read = getline(&line, &len, fp1)) != -1) {

                ret = strstr(line, "+");
                 if(ret)
                {
                        strncpy(cpuCount, line+32, 2);
    
                        arr11[m] = strtoul(cpuCount, &end, 10);
                        ++m;
			strncpy(cpu1Count, line+13, 2);
                        arr13[i] = strtoul(cpu1Count, &end, 10);
                        ++i;
                        strncpy(cpu2Count, line+51, 2);
                        arr15[j] = strtoul(cpu2Count, &end, 10);
                        ++j;

                }

        }
	printf("\n\n\n\nCPU usage for 1 min");
	printf("\nCPU NUM         Init  Final   Diff \n");
	
	for(i = 0; i < 86; ++i)
        {       
                
        	printf("CPUCORE%d\t %ld\t%ld\t%ld\n",i,  arr10[i], arr11[i], (arr11[i] - arr10[i]));

        }
	printf("\n\nCPU usage for 5 sec");
       printf("\nCPU NUM         Init  Final   Diff \n");

        for(i = 0; i < 86; ++i)
        {

                printf("CPUCORE%d\t %ld\t%ld\t%ld\n",i,  arr12[i], arr13[i], (arr13[i] - arr12[i]));

        }
	printf("\n\nCPU usage for 5 min");

	printf("\nCPU NUM         Init  Final   Diff \n");

        for(i = 0; i < 86; ++i)
        {

                printf("CPUCORE%d\t %ld\t%ld\t%ld\n",i,  arr14[i], arr15[i], (arr15[i] - arr14[i]));

        }




	
    	
    fclose(fp);
    fclose(fp1);

	m = 0;
	j = 0;
	k = 0;
	l = 0;

	fp = fopen("cpuhog1", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

      while ((read = getline(&line, &len, fp)) != -1) {

                ret = strstr(line, "DATAPATH-");
		ret1 =  strstr(line, "NUMHOG");
                 if(ret && ret1)
                {
                        strncpy(datapathCount, line+23, 2);
			arr16[m] = strtoul(datapathCount, &end, 10);
			
			strncpy(numhogCount, line+40, 10);
                        arr18[m] = strtoul(numhogCount, &end, 10);
			strncpy(maxhogCount, line+58, 4);
                        arr20[m] = strtoul(maxhogCount, &end, 10);

        		++m;                
			
                


                }

        }

fp1 = fopen("cpuhog2", "r");
    if (fp1 == NULL)
        exit(EXIT_FAILURE);

      while ((read = getline(&line, &len, fp1)) != -1) {

                ret = strstr(line, "DATAPATH-");
		ret1 = strstr(line, "NUMHOG");
                 if(ret && ret1)
                {       
                        strncpy(datapathCount, line+23, 2);
                        arr17[j] = strtoul(datapathCount, &end, 10);
                       strncpy(numhogCount, line+40, 10);
			arr19[j] = strtoul(numhogCount, &end, 10);
			strncpy(maxhogCount, line+58, 4);
			arr21[j] = strtoul(maxhogCount, &end, 10);
			++j;
                
                
                }

        }




    fclose(fp);
    fclose(fp1);
	printf("\nCPU hog analysis for NUMHOG values");
	printf("\n\nDP      DP     initNumhog     finalNumhog      DIFF    iMHOG  fMHOG  DIFF\n");
	for(i = 0; i < 86; ++i)
	{
		printf("\n%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld", arr16[i], arr17[i], arr18[i], arr19[i], (arr19[i] - arr18[i]), arr20[i], arr21[i],(arr21[i] - arr20[i]));
	}
	printf("\n");




m = 0;
	j = 0;
	k = 0;
	l = 0;

	fp = fopen("cpuhog1", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

      while ((read = getline(&line, &len, fp)) != -1) {

                ret = strstr(line, "DATAPATH-");
		ret1 =  strstr(line, "PROC_PC_TOTAL");
                 if(ret && ret1)
                {
                        strncpy(datapathCount, line+23, 2);
			arr22[m] = strtoul(datapathCount, &end, 10);
			
			strncpy(numhogCount, line+47, 10);
                        arr24[m] = strtoul(numhogCount, &end, 10);
			strncpy(maxhogCount, line+66, 4);
                        arr26[m] = strtoul(maxhogCount, &end, 10);
        		++m;                
			
                


                }

        }

m = 0;
	j = 0;
	k = 0;
	l = 0;


fp1 = fopen("cpuhog2", "r");
    if (fp1 == NULL)
        exit(EXIT_FAILURE);
      while ((read = getline(&line, &len, fp1)) != -1) {
                ret = strstr(line, "DATAPATH-");
		ret1 =  strstr(line, "PROC_PC_TOTAL:");
                 if(ret && ret1)
                {
                        strncpy(datapathCount, line+23, 2);
			arr23[m] = strtoul(datapathCount, &end, 10);
			
			strncpy(numhogCount, line+47, 10);
                        arr25[m] = strtoul(numhogCount, &end, 10);
			strncpy(maxhogCount, line+66, 4);
                        arr27[m] = strtoul(maxhogCount, &end, 10);
			
        		++m;                
			
                


                }

        }



    fclose(fp);
    fclose(fp1);


printf("\nCPU hog analysis for PROC_PC_TOTAL values");
	printf("\n\nDP      DP     initNumhog     finalNumhog      DIFF    iMHOG  fMHOG  DIFF\n");
	for(i = 0; i < 86; ++i)
	{
		printf("\n%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld", arr22[i], arr23[i], arr24[i], arr25[i], (arr25[i] - arr24[i]), arr26[i], arr27[i],(arr27[i] - arr26[i]));
	}
	printf("\n");




    
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
