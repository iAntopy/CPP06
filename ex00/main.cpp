/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:49:42 by iamongeo          #+#    #+#             */
/*   Updated: 2023/08/01 15:12:45 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caster.hpp"

bool	is_char_non_displayable(int c)
{
	return ((0 <= c && c < 32) || c == 127);
}

bool	is_all_space(const std::string& str)
{
	return (str.find_first_not_of(' ') == str.npos);
}

void	convert_float_to_str(float f, t_conv_tab &tab)
{
	std::ostringstream	os;

	tab.f = f;
	os << f;
	tab.f_str = os.str();
}


void	convert_double_to_str(double d, t_conv_tab &tab)
{
	std::ostringstream	os;

	tab.d = d;
	os << d;
	tab.d_str = os.str();
}

void	convert_int_to_str(int i, t_conv_tab &tab)
{
	std::ostringstream	os;

	tab.i = i;
	os << i;
	tab.i_str = os.str();
}

bool	non_numeric_float_check(const std::string& arg, enum e_num_type& dtype, t_conv_tab& tab)
{
	if (arg.compare(0, 3, "nan") == 0)
	{
		tab.c_str = "impossible";
		tab.i_str = "impossible";
		tab.f_str = "nan";
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


void	convert_from_char(const std::string& arg, t_conv_tab& tab)
{
	char				c = arg[0];

	std::cout << "Convert from char" << std::endl;
	tab.c_str = '\'';
	tab.c_str += c;
	tab.c_str += '\'';
	
	convert_int_to_str(static_cast<int>(c), tab);
	convert_float_to_str(static_cast<float>(c), tab);
	convert_double_to_str(static_cast<double>(c), tab);
}


void	convert_from_int(const std::string& arg, t_conv_tab& tab)
{
	ssize_t	nb;

	std::cout << "Convert from int" << std::endl;
	tab.d_str = "impossible";
	tab.f_str = "impossible";
	tab.i_str = "impossible";
	tab.c_str = "impossible";

	try {nb = std::stol(arg);}
	catch (std::exception &e)
	{
		std::cerr << "Nb way waaaaaaaayyyy too big. Converter shutdown. Situation critical." << std::endl;
		return ;
	}

	if (std::numeric_limits<int>::lowest() <= nb && nb <= std::numeric_limits<int>::max())
		convert_int_to_str(static_cast<int>(nb), tab);
	convert_float_to_str(static_cast<float>(tab.i), tab);
	convert_double_to_str(static_cast<double>(tab.i), tab);

	if (0 <= nb && nb <= 128)
	{
		if (is_char_non_displayable(static_cast<char>(tab.i)))
			tab.c_str = "Non diplayable";
		else
			tab.c_str = std::string("\'") + static_cast<char>(tab.i) + '\'';
	}
}


void	convert_from_float(const std::string& arg, t_conv_tab& tab)
{
	double	nb;

	std::cout << "Convert from float" << std::endl;
	tab.d_str = "impossible";
	tab.f_str = "impossible";
	tab.i_str = "impossible";
	tab.c_str = "impossible";

	try {nb = std::stod(arg);}
	catch (std::exception &e)
	{
		std::cerr << "Nb way waaaaaaaayyyy too big. Converter shutdown. Situation critical." << std::endl;
		return ;
	}

	if (std::numeric_limits<float>::lowest() <= nb && nb <= std::numeric_limits<float>::max())
		convert_float_to_str(static_cast<float>(nb), tab);
	if (std::numeric_limits<int>::lowest() <= nb && nb <= std::numeric_limits<int>::max())
		convert_int_to_str(static_cast<int>(tab.f), tab);
	tab.d = static_cast<double>(tab.f);
	convert_double_to_str(static_cast<double>(tab.f), tab);

	if (0 <= nb && nb <= 128)
	{
		if (is_char_non_displayable(tab.i))
			tab.c_str = "Non diplayable";
		else
			tab.c_str = std::string("\'") + static_cast<char>(tab.i) + '\'';
	}
}

void	convert_from_double(const std::string& arg, t_conv_tab& tab)
{
	double				nb;
	std::ostringstream	os;

	std::cout << "Convert from double" << std::endl;
	tab.d_str = "impossible";
	tab.f_str = "impossible";
	tab.i_str = "impossible";
	tab.c_str = "impossible";

	try {nb = std::stod(arg);}
	catch (std::exception &e)
	{
		std::cerr << "Nb way waaaaaaaayyyy too big. Converter shutdown. Situation critical." << std::endl;
		return ;
	}

	convert_double_to_str(static_cast<double>(nb), tab);
	if (std::numeric_limits<float>::lowest() <= nb && nb <= std::numeric_limits<float>::max())
		convert_float_to_str(static_cast<float>(tab.d), tab);
	if (std::numeric_limits<int>::lowest() <= nb && nb <= std::numeric_limits<int>::max())
		convert_int_to_str(static_cast<int>(tab.d), tab);

	if (0 <= tab.i && tab.i <= 128)
	{
		if (is_char_non_displayable(tab.i))
			tab.c_str = "Non diplayable";
		else
			tab.c_str = std::string("\'") + static_cast<char>(tab.i) + '\'';
	}
}

bool	find_actual_type(const std::string& arg, enum e_num_type& dtype, t_conv_tab& tab)
{
	size_t	p1, p2;

	if (non_numeric_float_check(arg, dtype, tab))
		return (true);
	if (!(arg[0] == '-' && arg.length() > 1 && isdigit(arg[1]))
		&& !isdigit(arg[0]))
	{
		if (arg.length() > 1 && arg[1] != ' ')
			return (false);
		dtype = CHAR_TYPE;
		convert_from_char(arg, tab);
	}
	else if ((p1 = arg.find('.')) != arg.npos)
	{
		if (arg.find_first_not_of(DIGITS, arg[0] == '-') != p1)
			return (false);
		if ((p2 = arg.find_first_not_of(DIGITS, p1 + 1)) != arg.npos && (arg[p2] == 'f')
			&& (arg[p2 + 1] == ' ' || arg[p2 + 1] == '\0'))
		{
			dtype = FLT_TYPE;
			convert_from_float(arg, tab);
		}
		else if (p2 != arg.npos && arg[p2] != ' ')
			return (false);
		else
		{
			dtype = DBL_TYPE;
			convert_from_double(arg, tab);
		}
	}
	else
	{
		if ((p1 = arg.find_first_not_of(DIGITS, arg[0] == '-')) != arg.npos && arg[p1] != ' ')
			return (false);
		dtype = INT_TYPE;
		convert_from_int(arg, tab);
	}
	return (true);
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
	enum e_num_type		dtype;

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

	if (!find_actual_type(arg, dtype, tab))
	{
		std::cerr << "Error: Conversion not possible." << std::endl;
		return (EXIT_FAILURE);
	}

	print_conversion_table(tab);
	return (0);
}