#include <stdio.h>
#include <math.h>

//assignment 2 

// this function will return the averege and the standard_deviation of the givven array.
//if the user will put double value, the int array will make the double value int .

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
            sum+=arr[i];
    }
    
    //the calculation of the averege
    
    averege = (double) sum/n;
    
    for(int j=0; j<n; j++)
    {
        standard_deviation_help += (arr[j]-averege)*(arr[j]-averege);
    }
    
    standard_deviation = divide*(standard_deviation_help);
    
    //the standard deviation final calculation 
    
    standard_deviation = sqrt(standard_deviation);
    
    //printing the averege and the standard_deviation final answer for the given array 
    printf("averege is: %f\n",averege);
    printf("standard deviation is: %f\n",standard_deviation);
    
    return 0;
}

//this function will get a string input from the user, 
//ans calculate the number of big letters in the given string

int part2()
{
    //get the string from user by dynamic allocation for the array 
    unsigned int length = 128;
    unsigned int current_size = 0;
    int sum=0;
    int k=0;
    
    char *arr = malloc(length);
    current_size = length;

    printf("\n please enter string (press enter when you finish):");

    if(arr != NULL)
    {
        
	int c = EOF;
	unsigned int i = 0;
        
	while(( c=getchar() ) != '\n' && c != EOF)
	{
		arr[i++]=(char)c;

		if(i==current_size)
		{
                current_size = i+length;
			    arr = realloc(arr, current_size);
		}
	}

	arr[i] = '\0';

        // sum the numbers of big letters

       for(int j=0; j<i; j++)
       {
           if(arr[j] >= 'A' && arr[j] <= 'Z')
           {
               sum++;
           }
       }
        
       //decler array with the size of big letters
       char ans[sum];
       
       for(int j=0; j<i; j++)
       {
           if(arr[j] >= 'A' && arr[j] <= 'Z')
           {
               ans[k]=arr[j];
               k++;
           }
       }
       
       //print the big letters to the user 
       
       for(int i=0; i<sum; i++)
       {
           printf("%c",ans[i]);
       }
       
	free(arr);
	arr = NULL;
	
    }
        return 0;
}

//the third part of assignment, we will get two matrix from the user and we will
//return the multiply ans of both of them.

void part3()
{
      int ROWS1=0;
      int COLS1=0;
      int ROWS2=0;
      int COLS2=0;
      int sum=0;
      
      //get the first mat from user, and print her.
      
      printf("please enter number of rows for the first matrix ");
      scanf("%d",&ROWS1);
      printf("please enter number of cols for the first matrix ");
      scanf("%d",&COLS1);
      
      int mat1[ROWS1][COLS1];
      
      printf("\nEnter matrix elements :\n");
      for(int i=0; i<ROWS1; i++)
      {
        for(int j=0; j<COLS1; j++)
        {
            printf("Enter element [%d,%d] : ",i+1,j+1);
            scanf("%d",&mat1[i][j]);
        }
      }
 
    printf("\nMatrix is :\n");
    
    for( int i=0; i<ROWS1; i++)
    {
        for(int j=0; j<COLS1; j++)
        {
            printf("%d\t",mat1[i][j]);
        }
        printf("\n");   
    }
    
      //get the second mat fron user, and print her.
    
      printf("please enter number of rows for the second matrix ");
      scanf("%d",&ROWS2);
      printf("please enter number of cols for the second matrix ");
      scanf("%d",&COLS2);
      
      int mat2[ROWS2][COLS2];
      
      printf("\nEnter matrix elements :\n");
      for(int i=0; i<ROWS2; i++)
      {
        for(int j=0; j<COLS2; j++)
        {
            printf("Enter element [%d,%d] : ",i+1,j+1);
            scanf("%d",&mat2[i][j]);
        }
      }
 
    printf("\nMatrix is :\n");
    
    for(int i=0; i<ROWS2; i++)
    {
        for(int j=0; j<COLS2; j++)
        {
            printf("%d\t",mat2[i][j]);
        }
        printf("\n");   
    }
    
    //the basic term to multiply two matrix's.
    
    if(COLS1!=ROWS2)
    {
        printf("wrong input, the matrix's could not be multiply by each other ! ");
    }
    
    //the calculation to multiply two given matrix's.
    
    else
    {
    
      int multiply[COLS1][ROWS2];
      
      for(int c=0; c<ROWS1; c++)
      {
          for(int d=0; d<COLS2; d++)
          {
              for(int k=0; k<ROWS2; k++)
              {
                sum = sum + mat1[c][k]*mat2[k][d];
              }
                  multiply[c][d] = sum;
                  sum = 0;
                  
                  printf("\nMatrix is :\n");
    
    for(int i=0; i<ROWS2; i++)
    {
        for(int j=0; j<COLS1; j++)
        {
            printf("%d\t",multiply[i][j]);
        }
        printf("\n");   
    }
          }
      }
    
    }
}

int main()
{
    int arr[]={13,8,5,2};
    
    int n = sizeof(arr) / sizeof(arr[0]); 
    part1(arr,n);
    part2();
    part3();
    return 0;
}