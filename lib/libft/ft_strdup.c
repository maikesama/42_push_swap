/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:35:09 by mpaci             #+#    #+#             */
/*   Updated: 2021/01/18 18:35:12 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = malloc((ft_strlen(s1) + 1) * sizeof(*s1));
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
}
