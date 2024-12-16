
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_insertion_sort(int *arr, int arr_size)
{
	
	size_t	i;
	size_t	j;
	int		temp;

	i = 1;
	while (i < arr_size)
	{
		j = i;
		printf("%d\n", j);
		while (j >= 0)
		{
			if (arr[i] < arr[j])
			{
				ft_swap(&arr[i], &arr[j]);
				break;
			}
			j--;
		}
		i++;
	}
}

void	ft_print_arr(int *arr, int arr_size)
{
	size_t	i;

	i = 0;
	printf("{ ");
	while (i < arr_size)
	{
		if (i == arr_size - 1)
			printf("%d", arr[i]);
		else
			printf("%d, ", arr[i]);
		i++;
	}
	printf("}\n");
}

int main()
{
	int arr[] = {4,9,2,0,3,6};
	int arr_size = sizeof(arr) / sizeof(int);

	printf("||---------------------------- ft_insertion_sort ----------------------------||\n\n");
	// ft_swap(&arr[0], &arr[1]);
	ft_insertion_sort(arr, arr_size);
	ft_print_arr(arr, arr_size);
	printf("\n||---------------------------------------------------------------------------||\n");
}
