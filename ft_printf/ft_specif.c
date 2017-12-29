
#include "ft_printf.h"

int ft_format_flag(int i, char *std_flag, char *str, t_printf **format)
{
	(*format)->flag = (char*)ft_memalloc(sizeof(char) * 2);

	if(ft_strchr(std_flag, str[i] ) != NULL)
	{
		(*format)->flag[0] = str[i];
		i++;
	}
	else
		(*format)->flag[0] = '\0';
	return(i);
}

int ft_format_width(int i,char *str, t_printf **format)
{
	if(ft_isdigit(str[i]))
		i = i + ft_dig_count((*format)->width = ft_atoi(str + i));
	else
		(*format)->width = -1;
	return(i);
}

int ft_format_precision(int i, t_printf **format, char *str)
{
	if(str[i] == '.' && ft_isdigit(str[i + 1]))
		i = i + 1 + ft_dig_count((*format)->precision = ft_atoi(str + i + 1));
	else if (str[i] == '.' && !ft_isdigit(str[i + 1]))
	{
		(*format)->precision = -1;
		i++;
	}
	else
		(*format)->precision = -1;
	return(i);
}

int ft_format_length(int i, char *std_length, char *str, t_printf **format)
{
	(*format)->length = (char*)ft_memalloc(sizeof(char) * 2);
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
	else
		(*format)->length[0] = '\0';
	return(i);
}

int ft_format_type(int i, char *std_type, char *str, t_printf **format)
{
		(*format)->type = (char*)ft_memalloc(sizeof(char) * 2);

		if(ft_strchr(std_type, str[i]) != NULL)
		{
			(*format)->type[0] = str[i];
			i++;
		}
		else
			(*format)->type[0] = '\0';
	return(i);
}

int 	ft_specif(t_printf **format, char *str, int i)
{
	char	*std_flag;
	char	*std_type;
	char	*std_length;
	int		start;

	start = i;
	std_flag = ft_strdup("-+#0 ");
	std_type = ft_strdup("sSpdDioOuUxXcC");
	std_length = ft_strdup("ljhztL");
	*format = malloc(sizeof(t_printf));
	while(1)
	{
		i = ft_format_flag(i, std_flag, str, format);
		i = ft_format_width(i, str, format);
		i = ft_format_precision(i, format, str);
		i = ft_format_length(i, std_length, str, format);
		i = ft_format_type(i, std_type, str, format);
		if ((*format)->flag[0] == '%')
			i = start + 1;
		if(ft_strchr(std_type, str[i]) != NULL || str[i] == '%')
		{
			i++;

		}
	}
	free(std_flag);
	free(std_type);
	free(std_length);
	// printf("flag = %s\n", (*format)->flag);
	// printf("width = %d\n", (*format)->width);
	// printf("precision = %d\n", (*format)->precision);
	// printf("length = %s\n", (*format)->length);
	// printf("type = %s\n", (*format)->type);

	return (i);
}
