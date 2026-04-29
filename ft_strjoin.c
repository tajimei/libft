/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtajima <mtajima@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:41:02 by mtajima           #+#    #+#             */
/*   Updated: 2026/04/29 17:44:45 by mtajima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = malloc(len1 + len2 + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		join[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		join[i] = s2[i - len1];
		i++;
	}
	join[i] = '\0';
	return (join);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*result;

// 	// 通常ケース
// 	result = ft_strjoin("Hello", "World");
// 	printf("test1: %s\n", result);
// 	free(result);

// 	// 空文字列
// 	result = ft_strjoin("", "World");
// 	printf("test2: %s\n", result);
// 	free(result);

// 	// 空文字列
// 	result = ft_strjoin("Hello", "");
// 	printf("test3: %s\n", result);
// 	free(result);

// 	// 両方空文字列
// 	result = ft_strjoin("", "");
// 	printf("test4: %s\n", result);
// 	free(result);

// 	// スペース入り
// 	result = ft_strjoin("Hello ", "World");
// 	printf("test5: %s\n", result);
// 	free(result);

// 	return (0);
// }
