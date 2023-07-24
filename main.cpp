/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:49:42 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/23 23:52:52 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caster.hpp"

bool	is_char_displayable(char c)
{
	return ((32 <= c && c < 48) || (58 <= c && c < 127));
}

bool	is_all_space(const std::string& str)
{
	return (str.find_first_not_of(' ') == str.npos);
}

enum e_cast_type    find_base_type(const std::string& arg)
{
	if (std::isdigit(arg[0]))
	{
		// is not char
		if (arg.find('.') == arg.npos)
			return (INT_TYPE);
		else if (arg.find('f') != arg.npos)
			return (FLOAT_TYPE);
		else
			return (DOUBLE_TYPE);
	}
	else
	{
		if (arg.compare(0, 3, "nan") == 0)
		{
			// float or double
			if (arg[3] == 'f')// float
				return (FLOAT_TYPE);
			else// double
				return (DOUBLE_TYPE);
		}
		else if (arg.compare(1, 4, "inf") == 0)
		{
			// float or double
			if (arg[4] == 'f')// float
				return (FLOAT_TYPE);
			else// double
				return (DOUBLE_TYPE);
		}
		else if (arg.length() < 1 || !is_char_displayable(arg[0]))
			//!((32 <= arg[0] && arg[0] < 48) || (58 <= arg[0] || arg[0] < 127)))
			return (ERROR_TYPE);
		else
				return (CHAR_TYPE);
	}
	return (ERROR_TYPE);
}

void	convert_table_from_char(const std::string& arg, t_conv_tab& tab)
{
	printf("CHAR CONVERTION\n");
	tab.c = arg[0];
	tab.i = (int)arg[0];
	tab.f = (float)tab.i;
	tab.d = (float)tab.f;	
}

void	convert_table_from_int(const std::string& arg, t_conv_tab& tab)
{
	printf("INT CONVERTION\n");
	tab.i = std::stoi(arg);
	tab.f = (float)tab.i;
	tab.d = (double)tab.f;
	if (is_char_displayable((char)tab.i))
	{
//		printf("Char displayable\n");
		tab.c = (char)tab.i;
	}
	else
	{
//		printf("char non displayable\n");
		tab.err_flags |= CHAR_NONDISP;
	}
//		tab.c = "Non displayable";
}

void	convert_table_from_float(const std::string& arg, t_conv_tab& tab)
{
	printf("FLOAT CONVERTION\n");
	tab.f = std::stof(arg);
	tab.d = (double)tab.f;
	if (std::isnan(tab.f) || std::isinf(tab.f))
	{
		tab.err_flags |= INT_IMPOS;
		tab.err_flags |= CHAR_IMPOS;
	}
	else
	{
		tab.i = (int)tab.f;
		tab.c = (char)tab.i;
	}
}

void	convert_table_from_double(const std::string& arg, t_conv_tab& tab)
{
	printf("DOUBLE CONVERTION\n");
	tab.d = std::stod(arg);
	tab.f = (float)tab.d;
	if (std::isnan(tab.f) || std::isinf(tab.f))
	{
		tab.err_flags |= INT_IMPOS;
		tab.err_flags |= CHAR_IMPOS;
	}
	else
	{
		tab.i = (int)tab.f;
		tab.c = (char)tab.i;
	}
}

void	print_convertion_table(const t_conv_tab& tab)
{
	if (CHAR_NONDISP & tab.err_flags)
		std::cout << "char: Non displayable" << std::endl;
	else if (CHAR_IMPOS & tab.err_flags)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << tab.c << "'" << std::endl;

	if (INT_IMPOS & tab.err_flags)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << tab.i << std::endl;

	std::cout << "float: " << tab.f << 'f' << std::endl;
	std::cout << "double: " << tab.d << std::endl;	
}

int main(int argc, char **argv)
{
	std::string			arg;
	enum e_cast_type	base_type;
	t_conv_tab			tab;

	tab.err_flags = 0;

	std::cout << "Enter" << std::endl;
	if (argc != 2)
	{
		std::cerr << "Wrong nb of arguments. Give string litteral to converte to [char, int, float, double]" << std::endl;
		return (1);
	}
	arg = argv[1];
	if (is_all_space(arg))
		arg = ' ';
	else
	{
		arg = arg.substr(arg.find_first_not_of(" "));
		arg = arg.substr(0, arg.find(' '));
	}
	base_type = find_base_type(arg);
	std::cout << "base type : " << base_type << std::endl;

	if (base_type == CHAR_TYPE)
		convert_table_from_char(arg, tab);
	else if (base_type == INT_TYPE)
		convert_table_from_int(arg, tab);
	else if (base_type == FLOAT_TYPE)
		convert_table_from_float(arg, tab);
	else if (base_type == DOUBLE_TYPE)
		convert_table_from_double(arg, tab);
	else if (base_type == ERROR_TYPE)
		std::cerr << "Convertion impossible" << std::endl;

	print_convertion_table(tab);
	return (0);
}