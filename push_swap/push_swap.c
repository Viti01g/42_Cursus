/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: VR <VR@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:42:02 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/04/05 21:32:37 by VR               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack_a *lista_push_swp(stack_a *lista)
{
	lista = ft_calloc(1, sizeof(stack_a));
	return (lista);
}

static stack_a *añadir_nums(stack_a *lista, char *num)
{
	stack_a *nuevo_num, *aux;
	nuevo_num = (stack_a*)ft_calloc(1, sizeof(stack_a));
	nuevo_num->data1 = ft_atoi((const char *)num);//num -48;
	nuevo_num->next = NULL;
	if (!lista)
		lista = nuevo_num;
	else
	{
		aux = lista;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = nuevo_num;
	}
	return (lista);
}

void	fillnums(char *arg, stack_a *lista)
{
	int		i;
	char	**nums;

	nums = ft_split(arg, 32);
	i = 0;
	while (nums[i])
	{
		lista = añadir_nums(lista, nums[i]);
		//printf("%d\n",lista->data1);
		lista = lista->next;
		i++;
	}
}

int dobles(stack_a *lista)
{	
	stack_a	*temp1;
	stack_a	*temp2;

	temp1 = lista;
	temp1 = temp1->next->next;
	while (temp1)
	{
		temp2 = lista;
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

int main(int argc, char **argv)
{
	int	i;
	int	j;
	char **words;
	
	j = 1;
	stack_a *lista = lista_push_swp(lista);
	while (j < argc)
	{
		i = 0;
		 while (argv[j][i])
		{
			if ((argv[j][i] >= '0' && argv[j][i] <= '9') || argv[j][i] == ' ')
				i++;
			else
				return (0);
		}
		fillnums(argv[j], lista);
		j++;
	}
	if (dobles(lista) == 0)
		return (0);
	lista = lista->next;
	while (lista != NULL)
	{
		printf("%d\n",lista->data1);
		lista = lista->next;
	}
	write(1, "culo\n", 5);
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