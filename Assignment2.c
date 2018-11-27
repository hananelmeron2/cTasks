#include <stdio.h>
#include <math.h>

// this function will return the averege and the standard_deviation of the givven array.
//we need to make sure that in the array the user will put correct input

int  part1(int arr[],int n)
{
    int sum=0;
    double averege;
    double standard_deviation_help;
    double standard_deviation;
    double divide=(double) 1/n;
    char term;
    
    for(int i=0; i<n; i++)
    {
        
        if(arr[i] % 1 != 0)
        {
            printf("wrong input !");
        }
            sum+=arr[i];
    }
    
    averege = (double) sum/n;
    
    for(int j=0; j<n; j++)
    {
        standard_deviation_help+=(arr[j]-averege)*(arr[j]-averege);
    }
    
    standard_deviation = divide*(standard_deviation_help);
    standard_deviation = sqrt(standard_deviation);
    
    printf("%f\n",averege);
    printf("%f",standard_deviation);
    
    return 0;
}



int part2()

{
    unsigned int length = 128;
    unsigned int current_size = 0;
    
    char *arr = malloc(length);
    current_size = length;

    printf("\n please enter string (press enter when you finish):");

    if(arr != NULL)
    {
	int c = EOF;
	unsigned int i = 0;
        
	while(( c = getchar() ) != '\n' && c != EOF)
	{
		arr[i++]=(char)c;

		if(i==current_size)
		{
                current_size = i+length;
			    arr = realloc(arr, current_size);
		}
	}

	arr[i] = '\0';

        //printf("\nLong String value:%s \n\n",arr);
        
	free(arr);
	arr = NULL;
	
    }
        return 0;
   
}


int main()
{
    int arr[]={13,8,5,2};
    
    int n = sizeof(arr) / sizeof(arr[0]); 
   // part1(arr,n);
   part2();
    
    return 0;
}