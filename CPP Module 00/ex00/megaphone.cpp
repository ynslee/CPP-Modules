/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:09:36 by yoonslee          #+#    #+#             */
/*   Updated: 2023/11/08 16:18:18 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	int	i;
	
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for(i = 1; i < argc; i++)
	{
		std::string str = argv[i];
		for(std::string::iterator it = str.begin(); it != str.end(); ++it)
		{
    		*it = std::toupper(*it);
		}
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
