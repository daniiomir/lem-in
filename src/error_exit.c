/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:53:41 by cnikia            #+#    #+#             */
/*   Updated: 2019/10/17 16:06:43 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//void	error(t_lem *lem, char *error)
//{
//	t_link	*wst;
//	t_path	*wsd;
//
//	if (lem)
//	{
//		if (lem->way)
//		{
//			while (lem->way)
//			{
//				if (lem->way->link)
//				{
//					while (lem->way->link)
//					{
//						wst = lem->way->link;
//						lem->way->link = lem->way->link->next;
//						if (wst)
//						{
//							free(wst);
//							wst = NULL;
//						}
//					}
//				}
//				if (lem->way->name)
//					free(lem->way->name);
//				wsd = lem->way;
//				lem->way = lem->way->next;
//				if (wsd)
//				{
//					free(wsd);
//					wsd = NULL;
//				}
//			}
//		}
//		free(lem);
//	}
//	perror(error);
//	//exit(1);
//}