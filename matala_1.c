#include <stdio.h>

int part1()
{
  int array[11];
  int i=0;
  int j=0;
  int temp=0;
  int counter=0;
  int bool=0;
  int sum=0;
  int pure=0;
  double averege=0;

  printf("Welcome, please enter the weights of each ingredient:");
  
  for(i = 0; i < 12; i++)
  {
    
    scanf("%d",&temp);
    counter ++;
    if(counter == 12)
    {
        printf("Too many ingredients.");
        bool=1;
    }
    array[i] = temp;
    if(temp<0)
    {
        break;
    }
    
  }
  
   if(counter<4)
    {
      printf("Not enough ingredients.\n");
      bool=1;
      
    }
 
    if(bool!=1)
    {
          for(i=0; i<counter-1; i++)
            {
              sum+=array[i];
            }
    averege= (double) sum / (counter-1);
    printf("The final product weighs : %.3f and is %d percent pure.", averege , (counter-1)*10);
    
    }
}
int part2()
{
  char C;
  char sequence[1000] = "";
  char stop = '$';
  char temp;
  int count=0;
  int ans=0;
  printf("Enter char to count:\n");
  scanf("%c",&C);  
  if(C == 'm' || C == 'M' || C == 's' || C == 'S')
  {
      printf("Enter the chars sequence:");
      while(temp != stop)
      {
          scanf(" %c",&temp);
          if(temp==C)
          {
              ans++;
          }
          count++;
      }
      printf("The char with ASCII code %d appeared %d times",C,ans);
  }
  
}

int main()
{
   // part1();
    part2();
    return 0;
}