/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:49:42 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/24 19:02:00 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caster.hpp"

bool	is_char_out_of_bounds(int c)
{
	return (c < 32 || 127 < c);
}

bool	is_char_non_displayable(int c)
{
	return ((0 <= c && c < 32) || c == 127);
//	return (('0' <= c) && (c <= '9'));
//	return ((32 <= c && c < 48) || (58 <= c && c < 127));
}

bool	is_all_space(const std::string& str)
{
	return (str.find_first_not_of(' ') == str.npos);
}

void	empty_steam(std::ostringstream& os)
{
	os.str("");
	os.clear();
}

bool	non_numeric_float_check(const std::string& arg, t_conv_tab& tab)
{
	if (arg.compare(0, 3, "nan") == 0)
	{
		tab.c_str = "impossible";
		tab.i_str = "impossible";
		tab.f_str = "nanf";
		tab.d_str = "nan";
		return (true);
	}
	else if (arg.compare(1, 3, "inf") == 0 && (arg[0] == '-' || arg[0] == '+'))
	{
		tab.c_str = "impossible";
		tab.i_str = "impossible";
		tab.f_str = arg[0];
		tab.d_str = arg[0];
		tab.f_str += "inf";
		tab.d_str += "inf";
		return (true);
	}
	return (false);
}
/*
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
		else if (arg.length() < 1)
			//!((32 <= arg[0] && arg[0] < 48) || (58 <= arg[0] || arg[0] < 127)))
			return (ERROR_TYPE);
		else
			return (CHAR_TYPE);
	}
	return (ERROR_TYPE);
}
*/

void	convert_table_from_char(const std::string& arg, t_conv_tab& tab)
{
	char				c = arg[0];
	std::ostringstream	os;

	printf("CHAR CONVERSION\n");
	tab.c_str = '\'';
	tab.c_str += c;
	tab.c_str += '\'';
	
	tab.i = (int)c;
	os << tab.i;
	tab.i_str = os.str();
	empty_steam(os);

	tab.f = (float)tab.i;
	os << tab.f;
	tab.f_str = os.str();
	empty_steam(os);

	tab.d = (double)tab.f;
	os << tab.d;
	tab.d_str = os.str();
	empty_steam(os);
}
/*
void	convert_table_from_int(const std::string& arg, t_conv_tab& tab)
{
	size_t				temp_i = std::stol;
	std::ostringstream	os;

	printf("INT CONVERSION\n");
	
	tab.d = (double)temp_i;
	if (tab.d > FLT_MAX || tab.d < FLT_MIN)
		tab.f_str = "impossible";
	else
	{
		tab.f = (float)tab.d;
		os << tab.f;
		tab.f_str = os.str();
		os.flush();
	}
	if (tab.f > (float)INT_MAX || tab.f < (float)INT_MIN)
		tab.i_str = "impossible";
	else
	{
		tab.i = (int)tab.f;
		os << tab.i;
		tab.i_str = os.str();
		os.flush();
	}

	if (tab.i > (int)CHAR_MAX || tab.i < (int)CHAR_MIN)
		tab.i_str = "impossible";
	else
	{
		tab.i = (int)tab.f;
		os << tab.i;
		tab.i_str = os.str();
		os.flush();
	}

	if (is_char_out_of_bounds(tab.i))
		tab.c_str = "impossible";
	else if (is_char_non_displayable((char)tab.i))
		tab.c_str = "Non displayable";
	else
		tab.c_str = (char)tab.i;
}
*/
//void	convert_table_from_float(const std::string& arg, t_conv_tab& tab)
void	convert_generic(const std::string& arg, t_conv_tab& tab)
{
	double				temp_d;
	std::ostringstream	os;
	
	printf("GENERIC CONVERSION\n");
	try
	{
		temp_d = std::stod(arg);
		tab.d = temp_d;
		os << tab.d;
		tab.d_str = os.str();
		empty_steam(os);
	}
	catch (std::out_of_range &e)
	{
		tab.d_str = "impossible";
		tab.f_str = "impossible";
		tab.i_str = "impossible";
		tab.c_str = "impossible";
		return ;
	}
	catch (std::invalid_argument &e)
	{
		tab.d_str = "impossible";
		tab.f_str = "impossible";
		tab.i_str = "impossible";
		tab.c_str = "impossible";
		return ;
	}
	if (tab.d < std::numeric_limits<float>::lowest()
		|| std::numeric_limits<float>::max() < tab.d)
	{
		std::cout << "Busted float limit" << std::endl;
		std::cout << "double rep : " << tab.d << std::endl;
		std::cout << "test1 : " << (tab.d < std::numeric_limits<float>::lowest()) << std::endl;
		std::cout << "test2 : " << (std::numeric_limits<float>::max() < tab.d) << std::endl;
		std::cout << "float min : " << std::numeric_limits<float>::lowest() << std::endl;
		std::cout << "float max : " << std::numeric_limits<float>::max() << std::endl;
		tab.f_str = "impossible";
		tab.i_str = "impossible";
		tab.c_str = "impossible";
		return ;
	}
	else
	{
		tab.f = (float)tab.d;
		os << tab.f;
		tab.f_str = os.str();
		empty_steam(os);
	}
	if (tab.f > (float)INT_MAX || tab.f < (float)INT_MIN)
	{
		tab.i_str = "impossible";
		tab.c_str = "impossible";
		return ;
	}
	else
	{
		tab.i = (int)tab.f;
		os << tab.i;
		tab.i_str = os.str();
		empty_steam(os);
	}
	if (is_char_non_displayable(tab.i))
		tab.c_str = "Non displayable";
	else if (is_char_out_of_bounds(tab.i))
		tab.c_str = "impossible";
	else
	{
		tab.c_str = "'";
		tab.c_str += (char)tab.i;
		tab.c_str += "'";
	}
}

void	print_conversion_table(const t_conv_tab& tab)
{
	std::cout << "char: " << tab.c_str << std::endl;
	std::cout << "int: " << tab.i_str << std::endl;

	std::cout << "float: " << tab.f_str;
	if (tab.f_str != "impossible")
	{
		if (tab.f_str == tab.i_str)
			std::cout << ".0";
		std::cout << 'f';
	}
	std::cout << std::endl;
	
	std::cout << "double: " << tab.d_str;
	if (tab.d_str != "impossible")
	{
		if (tab.d_str == tab.i_str)
			std::cout << ".0";
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	std::string			arg;
	t_conv_tab			tab;

	std::cout << "Enter" << std::endl;
	if (argc != 2)
	{
		std::cerr << "Missing argument. Give string litteral to converte to [char, int, float, double]" << std::endl;
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

	if (arg.length() == 1 && !std::isdigit(arg[0]))
		convert_table_from_char(arg, tab);
	else if (!non_numeric_float_check(arg, tab))
		convert_generic(arg, tab);

	print_conversion_table(tab);
	return (0);
}