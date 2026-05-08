/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtajima <mtajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:47:17 by mtajima           #+#    #+#             */
/*   Updated: 2026/05/08 16:05:49 by mtajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size > (size_t)(-1) / nmemb)
		return (malloc(1));
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (malloc(1));
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
