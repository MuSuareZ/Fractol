/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:08:47 by msuarez-          #+#    #+#             */
/*   Updated: 2019/10/21 14:08:48 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;

	if (!s)
		return (NULL);
	start = 0;
	while (WHITESPACES(s[start]))
		start++;
	if (s[start] == '\0')
		return (ft_strdup(s + start));
	len = ft_strlen(s) - 1;
	while (WHITESPACES(s[len]) && len > 0)
		len--;
	return (ft_strsub(s, start, len - start + 1));
}
