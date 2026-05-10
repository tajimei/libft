/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtajima <mtajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:20:23 by mtajima           #+#    #+#             */
/*   Updated: 2026/05/10 21:39:21 by mtajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	if (start >= slen)
		return (NULL);
	if (len > slen - start)
		len = slen - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *result;

// 	// 通常ケース
// 	result = ft_substr("Hello World", 6, 5);
// 	printf("test1: %s\n", result);
// 	free(result);

// 	// len が残り文字数より大きい
// 	result = ft_substr("Hello", 1, 100);
// 	printf("test2: %s\n", result);
// 	free(result);

// 	// start が範囲外
// 	result = ft_substr("Hello", 10, 5);
// 	printf("test3: %s\n", result);
// 	free(result);

// 	// start が0
// 	result = ft_substr("Hello", 0, 3);
// 	printf("test4: %s\n", result);
// 	free(result);

// 	// 空文字列
// 	result = ft_substr("", 0, 5);
// 	printf("test5: %s\n", result);
// 	free(result);

// 	return (0);
// }
