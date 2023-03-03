/* In this task, you are required to print a box composed of two triangles using
 * nested loops. An example output of the program is shown below.
 *   ....#
 *   ...##
 *   ..###
 *   .####
 *   #####
 *
 *  1. Implement function void draw_triangle(unsigned int size) that draws a box
 *     that contains a triangle of . and another triangle of #. The function should
 *     print the example output above when it is called draw_triangle(5);.
 *  2. The box should be size characters wide, and size characters tall.
 *  3. The box is split diagonally into two such that the right-bottom characters
 *     are '#', and the left-top characters are '.'.
 *  4. The first line contains one '#' character at the right edge, the second line
 *     contains two '##' characters, and so on. On the last line all characters are '#'.
 *  5. All lines (also the last line) should end with a newline character ('\n').
 *  6. (optional) To test draw_triangle(unsigned int size) function, you can write a main
 *     function that asks user for an input number of unsigned int type, and calls
 *     draw_triangle function using the given input. The main function in the provided
 *     template just has draw_triangle(5); statement.
 */

#include "source.h"
#include <math.h>
#include <stdio.h>

void draw_triangle(unsigned int size)
{
	unsigned int	dots_nbr;
	unsigned int	hash_nbr;
	unsigned int	print_dots;
	unsigned int	print_hash;
	char			dots;
	char			hash;

	dots = '.';
	hash = '#';
	for(hash_nbr = 1, dots_nbr = size - hash_nbr; dots >= 0 && hash_nbr <= size; hash_nbr++, dots_nbr--)
	{
		print_dots = size - hash_nbr;
		print_hash = hash_nbr;
		while(print_dots--)
			printf("%c", dots);
		while(print_hash--)
			printf("%c", hash);
		printf("\n");
	}
}
