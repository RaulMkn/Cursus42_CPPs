#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
}

static bool	isPseudoLiteral(const std::string &s)
{
	return (s == "nan" || s == "nanf"
		|| s == "+inf" || s == "-inf" || s == "inf"
		|| s == "+inff" || s == "-inff" || s == "inff");
}

static void	printPseudo(const std::string &s)
{
	std::string	base;

	// Normalize to the double form (no trailing 'f'): nan, inf, +inf, -inf
	if (s == "nan" || s == "nanf")
		base = "nan";
	else if (s == "inf" || s == "inff")
		base = "inf";
	else if (s == "+inf" || s == "+inff")
		base = "+inf";
	else
		base = "-inf";
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << base << "f" << std::endl;
	std::cout << "double: " << base << std::endl;
}

static bool	isCharLiteral(const std::string &s)
{
	return (s.length() == 1 && !std::isdigit(s[0]));
}

static void	printChar(double d)
{
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
}

static void	printInt(double d)
{
	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d)
		|| d < static_cast<double>(INT_MIN)
		|| d > static_cast<double>(INT_MAX))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
}

static void	printFloat(double d)
{
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << static_cast<float>(d) << "f" << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

static void	printDouble(double d)
{
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << d << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

void	ScalarConverter::convert(const std::string &literal)
{
	if (isPseudoLiteral(literal))
	{
		printPseudo(literal);
		return ;
	}
	if (isCharLiteral(literal))
	{
		double	d = static_cast<double>(literal[0]);
		printChar(d);
		printInt(d);
		printFloat(d);
		printDouble(d);
		return ;
	}

	char		*end = NULL;
	double		d = std::strtod(literal.c_str(), &end);
	std::string	rest(end);

	if (rest == "f" || rest == "F")
		rest = "";
	if (end == literal.c_str() || !rest.empty())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}
