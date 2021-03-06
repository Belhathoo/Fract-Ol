/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 20:19:25 by belhatho          #+#    #+#             */
/*   Updated: 2019/05/21 20:19:27 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if ((*(str + i) >= 65) && (*(str + i) <= 90))
			*(str + i) += 32;
		i++;
	}
	return (str);
}
