/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 07:16:56 by ryaoi             #+#    #+#             */
/*   Updated: 2017/05/08 07:16:57 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visu.h"

void          print_elem_dot(int counter, int i, t_mw *mw)
{
    int     j;
    int     k;

    j = 0;
    while (j < mw->multi_ratio - 2)
    {
        k = 0;
        while (k < mw->multi_ratio - 2)
        {
            mlx_pixel_put(mw->mlx, mw->win, (i * mw->multi_ratio) + k,
            (counter * mw->multi_ratio) + j, WHITE);
            k++;
        }
        j++;
    }
}

void          print_elem_o(int counter, int i, t_mw *mw)
{
    int     j;
    int     k;

    j = 0;
    if (counter == 0)
    while (j < mw->multi_ratio - 2)
    {
        k = 0;
        while (k < mw->multi_ratio - 2)
        {
            mlx_pixel_put(mw->mlx, mw->win, (i * mw->multi_ratio) + k,
            (counter * mw->multi_ratio) + j, MAGENTA);
            k++;
        }
        j++;
    }
}

void          print_elem_x(int counter, int i, t_mw *mw)
{
    int     j;
    int     k;

    j = 0;
    while (j < mw->multi_ratio - 2)
    {
        k = 0;
        while (k < mw->multi_ratio - 2)
        {
            mlx_pixel_put(mw->mlx, mw->win, (i * mw->multi_ratio) + k,
            (counter * mw->multi_ratio) + j, CYAN);
            k++;
        }
        j++;
    }
}

void          print_elem_capo(int counter, int i, t_mw *mw)
{
    int     j;
    int     k;

    j = 0;
    if (counter == 0)
    while (j < mw->multi_ratio - 2)
    {
        k = 0;
        while (k < mw->multi_ratio - 2)
        {
            mlx_pixel_put(mw->mlx, mw->win, (i * mw->multi_ratio) + k,
            (counter * mw->multi_ratio) + j, RED);
            k++;
        }
        j++;
    }
}

void          print_elem_capx(int counter, int i, t_mw *mw)
{
    int     j;
    int     k;

    j = 0;
    while (j < mw->multi_ratio - 2)
    {
        k = 0;
        while (k < mw->multi_ratio - 2)
        {
            mlx_pixel_put(mw->mlx, mw->win, (i * mw->multi_ratio) + k,
            (counter * mw->multi_ratio) + j, BLUE);
            k++;
        }
        j++;
    }
}