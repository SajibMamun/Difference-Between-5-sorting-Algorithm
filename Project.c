#include<stdio.h>
#include<stdlib.h>
int i,j,temp;

// this section for selection sort
void ascending_selectionsort(int arr[],int n)
{
    int min;
    for(i=0; i<n-1; i++)
    {
        min=i;
        for(j=i+1; j<n; j++)
        {
            if(arr[min]>arr[j])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    printf("\t\t\tSelection sort applied in Ascending Order : \n\n");
    printf("\t\t\t");
    for(i=0; i<n; i++)
    {
        printf(" %d ",arr[i]);
    }

    printf("\n\n");
}

void descending_selectionsort(int arr[],int n)
{

    int max;
    for(i=0; i<n-1; i++)
    {
        max=i;
        for(j=i+1; j<n; j++)
        {
            if(arr[max]<arr[j])
            {
                max=j;
            }
        }
        if(max!=i)
        {
            temp=arr[i];
            arr[i]=arr[max];
            arr[max]=temp;
        }
    }
    printf("\t\t\tSelection sort applied in Descending Order : \n\n");
    printf("\t\t\t");
    for(i=0; i<n; i++)
    {
        printf(" %d ",arr[i]);
    }

    printf("\n\n");

}




// this section for Bubble Sort
void ascennding_bubble(int arr[], int n)
{
    for(i=0; i<n-1; i++)
    {

        for(j=0; j<n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }
    }
    printf("\t\t\tBubble sort Applied in Ascending Order: \n");
    printf("\t\t\t");
    for(i=0; i<n; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n\n");
}

void descennding_bubble(int arr[], int n)
{
    for(i=0; i<n-1; i++)
    {

        for(j=0; j<n-1-i; j++)
        {
            if(arr[j]<arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }
    }
    printf("\t\t\tBubble sort Applied in Descending Order: \n");
    printf("\t\t\t");
    for(i=0; i<n; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n\n");
}


//this section for Insertion sort
void ascending_insertion(int arr[], int n)
{
    for(i=1; i<n; i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;

        }
        arr[j+1]=temp;

    }
    printf("\t\t\tInsertion sort Applied in Ascending order: \n");
    printf("\t\t\t");
    for(i=0; i<n; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n\n");
}

void descending_insertion(int arr[], int n)
{
    for(i=1; i<n; i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0&&arr[j]<temp)
        {
            arr[j+1]=arr[j];
            j--;

        }
        arr[j+1]=temp;

    }
    printf("\t\t\tInsertion sort Applied in Descending order: \n");
    printf("\t\t\t");
    for(i=0; i<n; i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n\n");
}


//this section for merge sort
void mergeSort(int arr[],int p, int r)
{
    if (p<r)
    {

        int q =((p + r)/2);
        mergeSort(arr,p,q);
        mergeSort(arr,q + 1,r);
        mergefunction(arr,p,q,r);
    }
}
void mergefunction(int arr[],int p,int q,int r)
{
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;

    int L[n1],R[n2];

    for (i=0; i<n1; i++)
        L[i]=arr[p+i];
    for (j=0; j<n2; j++)
        R[j]=arr[q+j+1];
    i=0;
    j=0;
    k=p;

    while (i<n1&&j<n2)
    {
        if (L[i]<=R[j])
        {
            arr[k]=L[i];
            i=i+1;
        }
        else
        {
            arr[k]=R[j];
            j=j+1;
        }
        k++;
    }

    while (i<n1)
    {
        arr[k]= L[i];
        i++;
        k++;
    }

    while (j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void des_Merge(int a[], int low, int high, int mid)
{

    int i=low,j=mid+1,k=0;
    int temp[high-low+1];

    while(i<=mid && j<= high)
    {
        if(a[i]>a[j])
            temp[k++]=a[i++];

        else
            temp[k++]=a[j++];

    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }

    while(j<=high)
    {
        temp[k++]=a[j++];
    }

    for(i=low; i<=high; i++)
    {

        a[i]=temp[i-low];

    }
    return;
}
void des_MergeSort(int a[],int low, int high)
{
    int mid;

    if(low<high)
    {
        mid=(low+high)/2;

        des_MergeSort(a,low,mid);
        des_MergeSort(a,mid+1,high);

        des_Merge(a,low,high,mid);
    }
    return;
}


//this section for quick sort
int partition(int arr[],int left, int right)
{
    int i,j,pivot,temp;
    pivot=arr[left];
    i=left;
    j=right;
    while(i<j)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[left];
    arr[left]=arr[j];
    arr[j]=temp;
    return j;
}
void Quicksort(int arr[],int left,int right)
{
    if(left<right)
    {
        int j;
        j=partition(arr,left,right);
        Quicksort(arr,left,j-1);
        Quicksort(arr,j+1,right);
    }
}

void descending_quickSort(int arr[], int left, int right)
{
    int i=left;
    int j=right;
    int temp=arr[i];

    if(left<right)
    {
        while(i<j)
        {
            while(arr[j]<=temp&&i<j)
            {
                j--;
            }
            arr[i]=arr[j];

            while(arr[i]>=temp&&i<j)
            {
                i++;
            }
            arr[j]=arr[i];
        }
        arr[i]=temp;
        descending_quickSort(arr,left,i-1);
        descending_quickSort(arr,j+1,right);
    }
}


int main()
{
    printf("\n\n\n\n\n\n\n\n\t\t\t......................***************........................");
    printf("\n\t\t\t|.....                                                 .....|");
    printf("\n\t\t\t|...      Comparison of different sorting algorithms     ...|");
    printf("\n\t\t\t|..........          Powered by                   ..........|");
    printf("\n\t\t\t|***....****                                     ***....****|");
    printf("\n\t\t\t|***....****         Team Quad                   ***....****|");
    printf("\n\t\t\t|***....****                                     ***....****|");
    printf("\n\t\t\t|******....*******....*******....*******....*******....*****|");
    printf("\n\t\t\t|...........................................................|\n");
    printf("\n\t\t\t...........................................................\n");

    printf("\n\n\t\t\t\t\t... Please press Enter key ...\n");
    getchar();
    system("COLOR 0A");
    int n,i,j;
    printf("Enter the Size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the %d value of the array: \n",n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n\n");
    printf("\tPlease choose a sorting Algorithm : \n");
    printf("\n");
    printf("1. Selection Sort.\n");
    printf("2. Bubble Sort.\n");
    printf("3. Insertion Sort.\n");
    printf("4. Merge Sort.\n");
    printf("5. Quick Sort.\n");
    printf("6. Exit.\n\n");

    while(1)
    {
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        {
            system("COLOR 0B");
            printf("\t1. Selection Ascending Order\n");
            printf("\t2. Selection Descending Order\n");
            printf("\t3. Return Main menu\n");
            printf("\nPlease Choose a option\n");
            while(1)
            {

                int c1;
                scanf("%d",&c1);
                if(c1==3)
                {
                    printf("\n\t\t     Now you are in main menu\n");
                    printf("\t\tPlease Choose a sorting algorithm again!!!\n");
                    break;
                }
                switch(c1)
                {
                case 1:
                {
                    ascending_selectionsort(arr,n);
                    break;
                }

                case 2:
                {

                    descending_selectionsort(arr,n);
                    break;
                }
                default:
                {
                    printf("Enter valid input\n\n");
                }


                }
            }

            break;
        }

        case 2:
        {
            system("COLOR 0C");
            printf("\t1. Bubble Ascending Order\n");
            printf("\t2. Bubble Descending Order\n");
            printf("\t3. Return Main menu\n");
            printf("\nPlease Choose a option\n");

            while(1)
            {


                int c2;
                scanf("%d",&c2);
                if(c2==3)
                {

                    printf("\n\t\t     Now you are in main menu\n");
                    printf("\t\tPlease Choose a sorting algorithm again!!!\n");
                    break;
                }
                switch(c2)
                {
                case 1:
                {
                    ascennding_bubble(arr,n);
                    break;
                }

                case 2:
                {

                    descennding_bubble(arr,n);
                    break;
                }
                default:
                {
                    printf("Enter valid input\n\n");
                }

                }
            }

            break;

        }

        case 3:
        {
            system("COLOR 0D");
            printf("\t1. Insertion Ascending Order\n");
            printf("\t2. Insertion Descending Order\n");
            printf("\t3. Return Main menu\n");
            printf("\nPlease Choose a option\n");

            while(1)
            {

                int c3;
                scanf("%d",&c3);
                if(c3==3)
                {
                    printf("\n\t\t     Now you are in main menu\n");
                    printf("\t\tPlease Choose a sorting algorithm again!!!\n");
                    break;
                }
                switch(c3)
                {
                case 1:
                {
                    ascending_insertion(arr,n);
                    break;
                }

                case 2:
                {

                    descending_insertion(arr,n);
                    break;
                }
                default:
                {
                    printf("Enter valid input\n\n");
                }

                }
            }

            break;
        }


        case 4:
        {
            system("COLOR 09");
            printf("\t1. Merge Ascending Order\n");
            printf("\t2. Merge Descending Order\n");
            printf("\t3. Return Main menu\n");
            printf("\nPlease Choose a option\n");
            while(1)
            {

                int c4;
                scanf("%d",&c4);
                if(c4==3)
                {
                    printf("\n\t\t     Now you are in main menu\n");
                    printf("\t\tPlease Choose a sorting algorithm again!!!\n");
                    break;
                }
                switch(c4)
                {
                case 1:
                {
                    mergeSort(arr,0,n-1);
                    printf("\t\t\tMerge sort Applied in Ascending Order: \n");
                    printf("\t\t\t");
                    for(i=0; i<n; i++)
                    {
                        printf(" %d ",arr[i]);
                    }
                    printf("\n\n");
                    break;
                }

                case 2:
                {
                    des_MergeSort(arr,0,n-1);
                    printf("\t\t\tMerge sort Applied in Descending Order: \n");
                    printf("\t\t\t");
                    for(i=0; i<n; i++)
                    {
                        printf(" %d ",arr[i]);
                    }
                    printf("\n\n");

                    break;
                }
                default:
                {
                    printf("Enter valid input\n\n");
                }

                }
            }

            break;
        }


        case 5:
        {
            system("COLOR 0A");
            printf("\t1. Quick Ascending Order\n");
            printf("\t2. Quick Descending Order\n");
            printf("\t3. Return Main menu\n");
            printf("\nPlease Choose a option\n");
            while(1)
            {

                int c5;
                scanf("%d",&c5);
                if(c5==3)
                {
                    printf("\n\t\t     Now you are in main menu\n");
                    printf("\t\tPlease Choose a sorting algorithm again!!!\n");

                    break;
                }
                switch(c5)
                {
                case 1:
                {
                    Quicksort(arr,0,n-1);
                    printf("\t\t\tQuick sort Applied in Ascending Order: \n");
                    printf("\t\t\t");
                    for(i=0; i<n; i++)
                    {

                        printf(" %d ",arr[i]);
                    }
                    printf("\n\n");
                    break;
                }

                case 2:
                {
                    descending_quickSort(arr,0,n-1);
                    printf("\t\t\tQuick sort Applied in Descending Order: \n");
                    printf("\t\t\t");
                    for(i=0; i<n; i++)
                    {

                        printf(" %d ",arr[i]);
                    }
                    printf("\n\n");

                    break;
                }
                default:
                {
                    printf("Enter valid input\n\n");
                }

                }
            }

            break;
        }

        case 6:
        {
            system("COLOR 0E");
            printf("\n\t\t\t\t     Thank you!!!\n\n\n");
            printf("\t\t\t\t<Powered by Team Quad>\n\n\n");

            exit(1);
            break;
        }
        default:
            system("COLOR 08");
            printf("\n\n\n\t\tInvalid Input!!! Please choose a correct option...\n\n");

        }
    }

    return 0;

}
