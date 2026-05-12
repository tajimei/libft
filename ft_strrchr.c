/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meitajima <mtajima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:30:28 by mtajima           #+#    #+#             */
/*   Updated: 2026/05/12 15:12:35 by meitajima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	char			*last;

	uc = (unsigned char)c;
	last = NULL;
	while (*s)
	{
		if (*s == uc)
			last = (char *)s;
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return (last);
}
