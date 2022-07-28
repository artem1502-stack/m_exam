#include <stdio.h>
#include <stdlib.h>

void	free_mass(int **m, int n)
{
	for (int i =0; i< n; i++)
		free(m[i]);
	free(m);
}

void	print_mass(int **m, int n)
{
	for (int i =0; i< n; i++)
	{
		for (int j =0; j < n; j++)
			printf("%d\t", m[i][j]);
		printf("\n");
	}
	printf("\n");
}

int	**get_mass(int n)
{
	int	**res;
	int	i, j;

	res = (int **)malloc(n * sizeof(int *));
	i = 0;
	while (i < n)
	{
		res[i] = (int *)malloc(n * sizeof(int));
		j = 0;
		while (j < n)
		{
			scanf("%d", &res[i][j]);
			j++;
		}
		i++;
	}
	return (res);
}

int	**task_1(int **m1, int **m2, int n)
{
	int	**res;
	int	i, j, k;

	res = (int **)malloc(n * sizeof(int *));
	i = 0;
	while (i < n)
	{
		res[i] = (int *)malloc(n * sizeof(int));
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			k = 0;
			res[i][j] = 0;
			while (k < n)
			{
				res[i][j] += m1[i][k] * m2[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (res);
}

int	**task_2(int **mas, int n, int m)
{
	int	**res;
	int	i, j;

	res = (int **)malloc(m * sizeof(int *));
	i = 0;
	while (i < m)
	{
		res[i] = (int *)malloc(n * sizeof(int));
		i++;
	}
	i = 0;
	while (i < m)
	{
		j = 0;
		while (j < n)
		{
			res[i][j] = mas[n - j - 1][i];
			j++;
		}
		i++;
	}
	return (res);
}



int	main(void)
{
	int	n = 3;

	int	**x = get_mass(n);//{{1, 2, 3}, {3, -1, 2}, {5, 5, -12}};
	//int	**y = get_mass(n);//{{-1, 5, 3}, {3, -7, 2}, {1, 7, 12}};
	int	**res = task_2(x, n, n);
	
	print_mass(x, n);
	//print_mass(y, n);
	print_mass(res, n);

	free_mass(x, n);
	//free_mass(y, n);
	free_mass(res, n);
	return (0);
}