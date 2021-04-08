#include<iostream>
#include<ctime>
#include<cstdlib>
#include<omp.h>
using namespace std;

int k=0;

class array
{
public:
int partition(int arr[], int low_index, int high_index)
{
	int i, j, temp, key;
	key = arr[low_index];
	i= low_index + 1;
	j= high_index;
	while(1)
	{
		while(i < high_index && key >= arr[i])
			i++;
		while(key < arr[j])
			j--;
		if(i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		else
		{
			temp= arr[low_index];
			arr[low_index] = arr[j];
			arr[j]= temp;
			return(j);
		}
	}
}

void quicksort(int arr[], int low_index, int high_index)
{
	int j;

	if(low_index < high_index)
	{
		j = partition(arr, low_index, high_index);
		cout<<"Pivot element "<<j<<"\t thread "<<k<<endl;
		#pragma omp parallel sections
		{
			#pragma omp section
			{
				k=k+1;
				quicksort(arr, low_index, j - 1);
			}

			#pragma omp section
			{
				k=k+1;
				quicksort(arr, j + 1, high_index);
			}

		}
	}
}

};

int main()
{
	srand(time(NULL));
	array a;
	int arr[10000];
	for(int i=0; i<10000;i++)
	{
		arr[i]=rand();
	}
	a.quicksort(arr, 0, 9999);
	cout<<"Elements of array after sorting \n";
	for(int i=0;i<10000;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";
}
