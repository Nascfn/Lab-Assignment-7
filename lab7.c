#include <stdio.h>
#include <stdlib.h>

/*
Paulo Fernandes Nascimento 
Lab Assignment 7

This code will print how many times each value was swapped for each array and how many swaps in total were there
*/

//prints array needs array and length
void printArray(int ar[], int len);
//sorts the array using bubble sort and prints sorted version
void bubbleSort(int ar[], int len);
//prints the number of sorts in each array
void printSortAmounts(int doubleAr[9][2], int ar[], int len);
//sorts the array ussing selecton sort and prints sorted version
void selectionSort(int ar[], int len);

int main(){ 

    //array1 info
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int ar1Length = 9;

    //array2 info
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20 ,10};
    int ar2Length = 9;

    //Perform bubble sort on both arrays
    printf("BUBBLE SORT \n");
    printf("\nARRAY 1\n");
    bubbleSort(array1, ar1Length);
    printf("\nARRAY 2\n");
    bubbleSort(array2, ar2Length);

    //Perform selection sort on both arrays
    printf("SELECTION SORT \n");
    printf("\nARRAY 1\n");
    selectionSort(array1,ar1Length);
    printf("\nARRAY 2\n");
    selectionSort(array2,ar2Length);

    return 0;
}




//FUNCTION DECLARATIONS


void printArray(int ar[], int len)
{
    printf("array is: ");
    for(int i = 0; i  < len; i++)
    {
        if(i == len -1)
        {
            printf("%d",ar[i]);
            continue;
        }
        printf("%d, ", ar[i]);
    }
    printf("\n");
    return;
}

void bubbleSort(int arTrue[], int len)
{
    //declare and set up counters
    int counters[9][2];
    int totalSwaps = 0;
    for(int i = 0; i < len; i++)
    {
        counters[i][0] =  arTrue[i];
        counters[i][1] = 0;
    }

    //copies the array so it does edit the original
    int ar[len];
    for(int i = 0; i < len; i++)
    {
        ar[i] = arTrue[i];
    }
   
   for(int i = 0; i < len - 1; i ++)
   {
        //loops thorough array but stopping one index less each time
        for(int j = 0; j < len - i - 1; j++)
        {
            //checks if its in order
            if(ar[j] > ar[j + 1])
            {
                //performs the swap
                int temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = temp;

                //increases swap counters
                totalSwaps++;
                for(int x = 0; x < len; x++)
                {
                    if(counters[x][0] == ar[j])
                    {
                        counters[x][1] += 1;
                        break;
                    }
                }
                for(int x = 0; x < len; x++)
                {
                    if(counters[x][0] == ar[j+1])
                    {
                        counters[x][1] += 1;
                        break;
                    }
                }
            }
            else
            {
                continue;
            }
        }
   }
   //Prints info
   printArray(ar,len);
   printSortAmounts(counters,ar,len);
   printf("The total number of swaps is: %d \n", totalSwaps);
}

void printSortAmounts(int doubleAr[9][2], int ar[], int len)
{
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(ar[i] == doubleAr[j][0])
            {
                printf("%d: was swapped %d times. \n", doubleAr[j][0],doubleAr[j][1]);
                break;
            }
        }
    }
}

void selectionSort(int arTrue[], int len)
{
    //declare and set up counters
    int counters[9][2];
    int totalSwaps = 0;
    for(int i = 0; i < len; i++)
    {
        counters[i][0] =  arTrue[i];
        counters[i][1] = 0;
    }

    //copies the array so it does edit the original
    int ar[len];
    for(int i = 0; i < len; i++)
    {
        ar[i] = arTrue[i];
    }

    //performs sorting
    for(int i = 0; i < len; i++)
    {
        int minVal = ar[i];
        int tempI = 0;
        for(int j = i + 1; j < len; j++)
        {
            if(ar[j] < minVal)
            {
                minVal = ar[j];
                tempI = j;
            }
        }

        if(minVal < ar[i])
        {
            ar[tempI] = ar[i];
            ar[i] = minVal;

            //Increases counters
            totalSwaps++;
            for(int x = 0; x < len; x++)
            {
                if(counters[x][0] == ar[tempI])
                {
                    counters[x][1] += 1;
                    break;
                }
            }
            for(int x = 0; x < len; x++)
            {
                if(counters[x][0] == ar[i])
                {
                    counters[x][1] += 1;
                    break;
                }
            }
        }
    }
    //prints information
    printArray(ar,len);
    printf("The total number of swaps is: %d \n", totalSwaps);
    printSortAmounts(counters, ar, len);
    

}