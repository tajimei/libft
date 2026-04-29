/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtajima <mtajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:30:28 by mtajima           #+#    #+#             */
/*   Updated: 2026/04/29 14:32:16 by mtajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
