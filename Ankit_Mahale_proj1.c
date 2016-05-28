#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000
void print_steps(int *arr, int start_index, int end_index);


/* This sort iterates, consuming one input element each repetition,
and growing a sorted output list. Each iteration, insertion sort removes
one element from the input data, finds the location it belongs within 
the sorted list,
and inserts it there. It repeats until no input elements remain.*/
void i_sort(int *a,int n)
{
    int i=0,unsorted=0,j=0,steps=1;
   for(i=1;i<n;i++)
   {
       unsorted=a[i];
       for(j=i-1;j>=0;j--)
       {
           if(unsorted<a[j])
            a[j+1]=a[j];
            else break;
       }
       a[j+1]=unsorted;
       if(n<=20)
       {   printf("Step %d:\n",steps++);
           print_steps(a,0,n);
       }

   }

}

/* This function print stars from arr[0] to arr[n-1]*/
void print_steps(int *arr, int start_index, int end_index)
{
    int i=0,count=0;

    for(i=start_index;i<end_index;i++)
    {    count=arr[i];
        while(count--)
            printf("*");
         printf("\n");
    }

}


/*In the most general case, the input to counting sort consists of a 
collection of n items,
each of which has a non-negative integer key whose maximum value is at 
most k. */
void c_sort(int *a,int n)
{
    /* Create a count array to store count of inidividual characters 
and*/
    // initialize count array as 0
    int i=0,j=0,count=0;
   int countingSortArray[100]={0};
   for(i=0;i<n;i++)
   {
       countingSortArray[a[i]]++;
   }
   int z=0,steps=1;
   for(i=0;i<100;i++)
   {
       count=countingSortArray[i];
       while(count--)
       {
           a[z++]=i;
           printf("Step %d:\n",steps++);
           print_steps(a,0,n);
       }

   }
   printf("\n");
   for(i=0;i<n;i++)
   {
       printf("%d ",a[i]);
   }
   printf("\n");
   return;

}

//Generates the random numbers array with the given input size
void random_number_array(int *arr,int n,int val)
{   int random_number=0,i;
    srand((unsigned)time(NULL));
    for(i=0;i<n;i++)
    {   random_number=(rand()%val);
        arr[i]=random_number;
    }
    return;
}

//swaps a and b element with each other.
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int split(int arr[], int p, int r)
{
    int pivotIndex = p + rand()%(r - p + 1); /*generates a random number 
as a pivot*/
    int pivot;

    int i = p - 1;
    int j;
    pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[r]);
    for (j = p; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }

    }
    swap(&arr[i+1], &arr[r]);


    return i + 1;
}
static int cn;
/*Rearrange the elements in array[p..r] so that all other elements
in array[p..r] that are less than or equal to the pivot are to its left
and all [remaining] elements in array[p..r] are to the pivot's right.*/
void q_sort(int arr[], int p, int q)
{
    int j;

    static int steps=0;
    if (p < q)
    {
        j = split(arr, p, q);
        if(cn<=20)
        {
            printf("Steps %d:\n",steps++);
            print_steps(arr,0,cn);

        }
        q_sort(arr, p, j-1);
        if(cn<=20)
        {
            printf("Steps %d:\n",steps++);
            print_steps(arr,0,cn);

        }

        q_sort(arr, j+1, q);
        if(cn<=20)
        {
            printf("Steps %d:\n",steps++);
            print_steps(arr,0,cn);

        }


    }
}
// This function prints the whole array when called.
void print_array(int *arr,int start_index, int end_index)
{
    int i=0;
    printf("\n",arr[i]);
    for(i=start_index;i<end_index;i++)
        printf("%d  ",arr[i]);
    printf("\n\n");
}

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array 
arr[] */
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;


    int L[n1], R[n2];
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void m_sort(int arr[], int l, int r,int n)
{
    static int steps=1;
    if (l < r)
    {
        int m = l+(r-l)/2;
        // recursively split runs into two halves until run size == 1,
    // then merge them and return back up the call chain
        m_sort(arr, l, m, n);
        if(n<=20)
        {
            printf("Steps %d:\n",steps++);
            print_steps(arr,0,n);

        }
        //  Left half is A[iBegin :iMiddle-1].
        // Right half is A[iMiddle:iEnd-1   ].
        m_sort(arr, m+1, r, n);
        if(n<=20)
        {
            printf("Steps %d:\n",steps++);
            print_steps(arr,0,n);

        }

        merge(arr, l, m, r);

        if(n<=20)
        {
            printf("Steps %d:\n",steps++);
            print_steps(arr,0,n);

        }
    }
}


int main()
{
    int array[MAX],n,choice;


    while(1)
    {

    
printf("---------------------------------------------------MENU-------------------------------------------\n");
    printf("1.Insertion Sort\n");
    printf("2.Counting Sort\n");
    printf("3.Merge Sort\n");
    printf("4.Randomized Quick Sort\n");
    printf("5.Exit\n");
    printf("Enter Your Choice:");
    scanf("%d",&choice);
    if(choice!=5)
    {printf("Enter the count of numbers to be sorted:");
    scanf("%d",&n);
    cn=n;
    }
    switch(choice)
    {
            case 1:if(n<=20)
                   {
                       random_number_array(array,n,16);
                   }
                   else
                   {
                       random_number_array(array,n,10000);
                   }
                   printf("\nArray before Sorting:\t");
                   print_array(array,0,n);
                   i_sort(array,n);
                   printf("\nArray After Sorting:\t");
                   print_array(array,0,n);
                   break;
            case 2:if(n<=20)
                   {
                       random_number_array(array,n,16);
                   }
                   else
                   {
                       random_number_array(array,n,100);
                   }
                   printf("\nArray before Sorting:\t");
                   print_array(array,0,n);
                   printf("\nArray After Sorting:\t");
                   c_sort(array,n);
                   break;
            case 3:if(n<=20)
                   {
                       random_number_array(array,n,16);
                   }
                   else
                   {
                       random_number_array(array,n,10000);
                   }
                   printf("\nArray before Sorting:\t");
                   print_array(array,0,n);
                   m_sort(array,0,n,n);
                   printf("\nArray After Sorting:\t");
                   print_array(array,0,n);
                   break;
            case 4:if(n<=20)
                   {
                       random_number_array(array,n,16);
                   }
                   else
                   {
                       random_number_array(array,n,10000);
                   }
                   printf("\nArray before Sorting:\t");
                   print_array(array,0,n);
                   q_sort(array,0,n);
                   printf("\nArray After Sorting:\t");
                   print_array(array,0,n);
                   break;
            case 5: exit(0);
    }

    }


}

