/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:42:02 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/04/18 17:30:46 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack *lista_push_swp(stack *lista)
{
	lista = ft_calloc(1, sizeof(stack));
	return (lista);
}

static stack *añadir_nums(stack *lista, char *num)
{
	stack *nuevo_num, *aux;
	nuevo_num = (stack*)ft_calloc(1, sizeof(stack));
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

void	fillnums(char *arg, stack *lista)
{
	int		i;
	char	**nums;

	nums = ft_split(arg, 32);
	i = 0;
	while (nums[i])
	{
		lista = añadir_nums(lista, nums[i]);
		lista = lista->next;
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

int main(int argc, char **argv)
{
	int	i;
	int	j;
	stack	*aux;
	stack	*aux2;
	stack	*lista_a = NULL;
	stack	*lista_b = NULL;
	
	
	j = 1;
	lista_a = lista_push_swp(lista_a);
	lista_b = lista_push_swp(lista_b);
	lista_b = lista_b->next;
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
		fillnums(argv[j], lista_a);
		j++;
	}
	if (dobles(lista_a) == 0)
		return (0);
	lista_a = lista_a->next;
	stack *temp = lista_a;
	while (temp != NULL)
	{
		printf("%d\n",temp->data1);
		temp = temp->next;
	}
	write(1, "\n", 1);
	push_b(&lista_a, &lista_b);
	push_b(&lista_a, &lista_b);
	push_b(&lista_a, &lista_b);	
	swap_rra(&lista_a);
	aux = lista_a;
	aux2 = lista_b;
	//write(1, "c\n", 2);
	while (aux)
	{
		printf("a -> %d		b -> %d\n", aux->data1, aux2->data1);
		aux = aux->next;
		aux2 = aux2->next;
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