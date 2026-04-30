/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtajima <mtajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:47:59 by mtajima           #+#    #+#             */
/*   Updated: 2026/04/30 12:59:02 by mtajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trim;

	start = 0;
	while (s1[start] && ft_inset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_inset(s1[end - 1], set))
		end--;
	trim = ft_substr(s1, start, end - start);
	return (trim);
}
