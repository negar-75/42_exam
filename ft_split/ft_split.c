#include<stdlib.h>
#include<stdio.h>

int word_count(char *str)
{
    int i = 0;
    int count = 0;

    while(str[i])
    {
        while(str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
        {
          i++;
        }
        if(str[i] && (str[i] != ' ' || !(str[i] >= 9 && str[i] <= 13)))
        {
          count++;
        }
        while(str[i] && !(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
        {
           i++;
        }
    }

    return count;
}
char* word_allocation(char* str)
{
	int i = 0;
	while(str[i] && !(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
	{
		i++;
	}
	char* word = malloc((i + 1) * sizeof(char));
	i = 0;
	while(str[i] && !(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return word;
	
}

char    **ft_split(char *str)
{
	int words = word_count(str);
	char **arr = malloc((words + 1) * sizeof(char*));
	int j = 0;
	while(*str)
	{
		 while(*str && (*str == ' ' || (*str >= 9 && *str<= 13)))
        {
          str++;
        }
		if(*str)
		{
			arr[j] = word_allocation(str);
			j++;

			while(*str && !(*str == ' ' || (*str >= 9 && *str <= 13)))
			{
				str++;
			}

		}
	}
	arr[j] = NULL;
	return arr;
}


// int main ()
// {
//     char* text = "this is meeeee ";
// 	char **t = ft_split(text);
// 	while(*t)
// 	{
// 		printf("%s ",*t);
// 		t++;
// 	}
   
//     return 0;
// }