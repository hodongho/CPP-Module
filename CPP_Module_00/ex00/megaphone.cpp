/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyun <dhyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:02:51 by dhyun             #+#    #+#             */
/*   Updated: 2022/11/03 16:58:22 by dhyun            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

int	main(int argc, char *argv[])
{
	int	i;
	std::string str =  "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (argc < 2)
	{
		std::cout << str;
		return (1);
	}
	str = argv[1];
	i = 2;
	while (argv[i])
	{
		str = str + argv[i];
		i++;
	}
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	std::cout << str << std::endl;
	return (0);
}
