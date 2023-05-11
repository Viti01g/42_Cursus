/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:42:02 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/11 17:42:58 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	añadir_nums(stack **lista, char *num)
{
	stack *nuevo_num, *aux;
	nuevo_num = (stack *)malloc(sizeof(stack));
	nuevo_num->data1 = ft_atoi_ps(num);//num -48;
	nuevo_num->next = NULL;
	printf("nuevo_num: %d\n", nuevo_num->data1);
	printf("la lista: %p\n", lista);
	if (!(*lista))
		*lista = nuevo_num;
	else
	{
		aux = (*lista);
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = nuevo_num;
	}
	printf("Añadido\n");
}

void	fillnums(char *arg, stack **lista)
{
	int		i;
	char	**nums;
	stack	*aux;

	aux = *lista;
	nums = ft_split(arg, 32);
	i = 0;
	while (nums[i])
	{
		//printf("kn\n");
		printf("num en i: %s\n", nums[i]);
		añadir_nums(lista, nums[i]);
		//printf("NODe content t: %d\n", aux->data1);
		//read_list(lista);
		//aux = aux->next;
		i++;
	}
}

int dobles(stack *lista_a)
{	
	stack	*temp1;
	stack	*temp2;

	temp1 = lista_a;
	temp1 = temp1->next->next;
	while (temp1)
	{
		temp2 = lista_a;
		temp2 = temp2->next;
		while (temp2 < temp1)
		{
			if(temp1->data1 == temp2->data1)
				return (0);
			temp2 =temp2->next;
		}
		temp1 = temp1->next;
	}
	return (1);
}
/* void leaks()
{
	system("leaks -q push_swap");
} */

int main(int argc, char **argv)
{
	int	j;
	stack	**lista_a;
	stack	**lista_b;
	
	//atexit(leaks);
	j = 1;
	ft_check_args(argc, argv);
	lista_a = malloc(sizeof(stack*));
	lista_b = malloc(sizeof(stack*));
	while (j < argc)
	{
		fillnums(argv[j], lista_a);
		printf("%p\n", *lista_a);
		j++;
	}
	check_algor(*lista_a, *lista_b);
	return (0);
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