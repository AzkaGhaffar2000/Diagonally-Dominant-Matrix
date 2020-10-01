#include <stdio.h>
#include <stdlib.h>

void DiagDom(int *M, int size);

int main(int argc, char *argv[])
{
   int size;
   int i, j;

   size = atoi(argv[1]);     

   int *M = (int *) malloc(size * size * sizeof(int));
   
	printf("\nThis program determines if the entered matrix is"); 
	printf("\ndynamically-dominant and prints the result of each row"); 
	printf("\nso if the whole matrix is not dynamically-dominant but some row is dd,"); 
	printf("\nthe program will tell which row that is. ");
	
   for (i=0; i<size; i++)
	for (j=0; j<size; j++)
	{
		printf("\nPlease enter M[%d][%d]:", i, j);
 	  		scanf("%d", (M+i*size+j));
	}
	DiagDom(M, size);
	return 0;
 
}
void DiagDom(int *M, int size)
{
    for (int i = 0; i < size; i++) 
   {   
        int sum = 0; 
        for (int j = 0; j < size; j++)             
            sum= sum + abs(M[i*size + j]); 
            printf("\nThe sum of row %d is %d", i, sum);       
        sum = sum - abs(M[i*size + i]); 
        printf("\nThe sum of row %d after removing diagonal is %d", i, sum); 
  		
  		 if (abs(M[i*size + i]) < sum) {
            printf("\nThe matrix is not dynamically dominant\n");
         } else {
         printf("\nThe matrix is dynamically dominant\n");
         }
    }  
} 

