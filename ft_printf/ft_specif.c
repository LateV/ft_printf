
#include "ft_printf.h"

int ft_format_flag(int i, char *std_flag, char *str, t_printf **format)
{
	while(ft_strchr(std_flag, str[i] ) != NULL)
	{
		if(str[i] == '-')
			(*format)->flag[0] = str[i];
		if(str[i] == '+')
			(*format)->flag[1] = str[i];
		if(str[i] == '#')
			(*format)->flag[2] = str[i];
		if(str[i] == '0')
			(*format)->flag[3] = str[i];
		if(str[i] == ' ')
			(*format)->flag[4] = str[i];
		i++;
	}
	return(i);
}

int ft_format_width(int i,char *str, t_printf **format)
{
	i = i + ft_dig_count((*format)->width = ft_atoi(str + i));
	return(i);
}

int ft_format_precision(int i, t_printf **format, char *str)
{
	if(str[i] == '.' && ft_isdigit(str[i + 1]))
	{
		i = i + 1 + ft_dig_count((*format)->precision = ft_atoi(str + i + 1));
		return(i);
	}
	if (str[i] == '.' && !ft_isdigit(str[i + 1]))
	{
		(*format)->precision = -1;
		i++;
		return(i);
	}
	return(i);
}

int ft_format_length(int i, char *std_length, char *str, t_printf **format)
{
	ft_memset((*format)->length, '\0', 2);
	if(ft_strchr(std_length, str[i]) != NULL)
	{
		if(str[i] == 'h' && str[i + 1] == 'h')
		{
			(*format)->length[0] = str[i];
			(*format)->length[1] = str[i + 1];
			i = i + 2;
		}
		else if(str[i] == 'l' && str[i + 1] == 'l')
		{
			(*format)->length[0] = str[i];
			(*format)->length[1] = str[i + 1];
			i = i + 2;
		}
		else
		{
			(*format)->length[0] = str[i];
			i++;
		}
	}
	return(i);
}

int ft_format_type(int i, char *str, t_printf **format)
{
	(*format)->type[0] = str[i];
	i++;
	return(i);
}

int 	ft_specif(t_printf **format, char *str, int i)
{
	char	*std_flag;
	char	*std_type;
	char	*std_length;
	int		flag;

	flag = 0;
	std_flag = ft_strdup("-+#0 ");
	std_type = ft_strdup("sSpdDioOuUxXcC");
	std_length = ft_strdup("ljhztL");
	*format = malloc(sizeof(t_printf));
	(*format)->flag = (char*)malloc(sizeof(char) * 5);
	ft_memset((*format)->flag, '\0', 5);
	(*format)->width = -1;
	(*format)->precision = -1;
	(*format)->length = (char*)ft_memalloc(sizeof(char) * 2);
	ft_memset((*format)->length, '\0', 2);
	(*format)->type = (char*)ft_memalloc(sizeof(char) * 2);
	ft_memset((*format)->type, '\0', 2);
	while (str[i] != '%' && ft_strchr(std_type, str[i]) != NULL && str[i] != '\0')
	{
		if (ft_strchr(std_flag, str[i]) != NULL)
		{
			i = ft_format_flag(i, std_flag, str, format);
			continue;
		}
		if (ft_isdigit(str[i]))
		{
			i = ft_format_width(i, str, format);
			continue;
		}
		if (str[i] == '.')
		{
			i = ft_format_precision(i, format, str);
			continue;
		}
		if (ft_strchr(std_length, str[i]) != NULL)
		{
			i = ft_format_length(i, std_length, str, format);
			continue;
		}
		i++;
	}
	if (ft_strchr(std_type, str[i]) != NULL)
		i = ft_format_type(i, str, format);
	free(std_flag);
	free(std_type);
	free(std_length);
	printf("flag = %s\n", (*format)->flag);
	printf("width = %d\n", (*format)->width);
	printf("precision = %d\n", (*format)->precision);
	printf("length = %s\n", (*format)->length);
	printf("type = %s\n", (*format)->type);

	return (i);
}
