#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	print_array(char **words, int num)
{
	for (int j = 0; j < num; j++)
	{
		printf("%s\n", words[j]);
	}
}

void	copy_to_array(char **dest, char **src, int num)
{
	for (int j = 0; j < num; j++)
	{
		strcpy(dest[j], src[j]);
	}
}

/**
 * \brief Allocates memory for an array of strings.
 *
 * \param xdim An array of integers indicating the number of elements in the
 * 				arrays (strings)
 * \param ydim The number of pointers in the array of pointers
 * \return char** A dynamically allocated array of pointers
 *
 * \note The strings must have a termination character.
 */
char	**allocate_memory(int *xdim, int ydim)
{
	char	**arr;
	arr = (char **)malloc((ydim + 1) * sizeof(char));
	if (!arr)
		return (NULL);

	for(int j = 0; j < ydim; j++)
	 {
		arr = (char **)malloc(((char)xdim + 1) * sizeof(char));
		if(!arr[j])
		{
			for(int i = 0; i < j; i++)
				free(arr[i]);
			free(arr);
		}
	 }
	return (arr);
}

/**
 * \brief Frees the dynamically allocated memory for an array of pointers.
 *
 * \param w The array of pointers/
 * \param ydim The number of pointers in the array.
 */
void	free_array(char **w, int ydim)
{
	for(int i = 0; i < ydim; i++)
	{
		free(w[i]);
	}
	free(w);
}

int	main(void)
{
	char	*static_words_1[];
	char	*static_words_2[];
	int		ydim_1;
	int		ydim_2;
	char	**words;

	static_words_1[] = {"dynamically", "allocated", "multidimensional", "arrays"};
	static_words_2[] = {"are", "FUN", "!"};
	ydim_1 = 4;
	int xdim_1[] = {strlen(static_words_1[0]),
					strlen(static_words_1[1]),
					strlen(static_words_1[2]),
					strlen(static_words_1[3])};
	ydim_2 = 3;
	int xdim_2[] = {strlen(static_words_2[0]),
					strlen(static_words_2[1]),
					strlen(static_words_2[2])};
	words = allocate_memory(xdim_1, ydim_1);
	copy_to_array(words, static_words_1, ydim_1);
	print_array(words, ydim_1);
	free_array(words, ydim_1);
	words = allocate_memory(xdim_2, ydim_2);
	copy_to_array(words, static_words_2, ydim_2);
	print_array(words, ydim_2);
	free_array(words, ydim_2);
	return (0);
}
