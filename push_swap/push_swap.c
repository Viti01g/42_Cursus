/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:42:02 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/03/13 18:54:33 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char    *push_swap(int fd)
{
	void quick_sort(int f, int l) 
	{
	int i, j, t, p = 0;
	int arreglo[MAX_SIZE];
	if (f < l)
	{
	p = f;
	i = f;
	j = l;
	while (i < j) {
	while (arreglo[i] <= arreglo[p] && i < l)
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
		}
}

int main(int argc, char **argv)
{

}

/*

El algoritmo rapido puede ser el quick sort pero alomejor es menos fiable,

hay que buscar otro tippo de algoritmos mas elaboraados que puedan ser ma fiables

*/