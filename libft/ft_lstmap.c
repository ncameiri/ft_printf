/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <ncameiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:42:06 by ncameiri          #+#    #+#             */
/*   Updated: 2021/02/12 17:44:05 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*do_func(t_list *lst, void *(*f)(void *),
	void (*del)(void *), t_list *new_lst)
{
	t_list	*new_elem;

	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (new_elem == NULL)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&new_lst, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, new_elem);
	}
	return (new_lst);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	if (!lst || !f)
		return (NULL);
	new_elem = ft_lstnew(f(lst->content));
	if (new_elem == NULL)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new_lst = new_elem;
	lst = lst->next;
	new_lst = do_func(lst, f, del, new_lst);
	return (new_lst);
}
