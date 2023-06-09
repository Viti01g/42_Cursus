/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:42:02 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/23 16:39:04 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	anadir_nums(t_stack **lista, char *num)
{
	t_stack	*nuevo_num;
	t_stack	*aux;

	nuevo_num = (t_stack *)malloc(sizeof(t_stack));
	if (!nuevo_num)
		ft_error_exit();
	nuevo_num->data1 = ft_atoi_ps(num);
	nuevo_num->next = NULL;
	if (!(*lista))
		*lista = nuevo_num;
	else
	{
		aux = (*lista);
		if (!aux)
			return ;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = nuevo_num;
	}
}

void	fillnums(char *arg, t_stack **lista)
{
	int		i;
	char	**nums;
	t_stack	*aux;

	aux = *lista;
	nums = ft_split(arg, 32);
	i = 0;
	while (nums[i])
	{
		anadir_nums(lista, nums[i]);
		i++;
	}
	ft_liberar(nums);
	if (dobles(*lista) == 1)
	{
		free_stack(lista);
		ft_error_exit();
	}
}

int	dobles(t_stack *lista_a)
{
	t_stack	*tmp;

	while (lista_a)
	{
		tmp = lista_a->next;
		while (tmp)
		{
			if (lista_a->data1 == tmp->data1)
				return (1);
			tmp = tmp->next;
		}
		lista_a = lista_a->next;
	}
	return (0);
}

static void	is_ordered(t_stack *lista_a)
{
	t_stack	*aux;
	int		min;

	aux = lista_a;
	min = aux->data1;
	aux = aux->next;
	while (aux != NULL)
	{
		if (aux->data1 > min)
			min = aux->data1;
		else
			return ;
		aux = aux->next;
	}
	exit(EXIT_SUCCESS);
}
void leaks()
{
	system("leaks -q push_swap");
} 

int	main(int argc, char **argv)
{
	int		j;
	t_stack	*lista_a;
	t_stack	*lista_b;
	//atexit(leaks);
	j = 1;
	ft_check_args(argc, argv);
	lista_a = NULL;
	lista_b = NULL;
	while (j < argc)
	{
		if (ft_strlen(argv[j]) < 1)
			ft_error_exit();
		fillnums(argv[j], &lista_a);
		j++;
	}
	index_stack(&lista_a);
	is_ordered(lista_a);
	check_algor(&lista_a, &lista_b);
	free_stack(&lista_a);
	free_stack(&lista_b);
	exit(0);
}


/*

El algoritmo rapido puede ser el quick sort pero alomejor es menos fiable,

hay que buscar otro tipo de algoritmos mas elaborados que puedan ser ma fiables

*/
/* void quick_sort(int f, int l) 
{
int i, j, t, p = 0;
int arreglo[MAX_SIZE];
if (f < l)
{
p = f;
i = f;
j = l;
while (i < j)
{
	while (arreglo[i] <= arreglo[p] && i < l)
	{
		i++;
		while (arreglo[j] > arreglo[p])
			j--;
		if (i < j)
		{
			t = arreglo[i];
			arreglo[i] = arreglo[j];
			arreglo[j] = t;
		}
	}
		t = arreglo[p];
		arreglo[p] = arreglo[j];
		arreglo[j] = t;
		quick_sort(f, j - 1);
		quick_sort(j + 1, l);
} */
/* 
*list
*temp = list
*list->next
---------------------
|NULL|NULL|	|	|	|
---------------------
1-> NULL */