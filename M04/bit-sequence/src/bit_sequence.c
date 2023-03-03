#include "bit_sequence.h"
#include <stdio.h>
#include <stdlib.h>

/* DESCRIPTION:
 * ------------
 * The function extracts a sequence of bits from the argument data. The indexes
 * of the bits that will be extracted are the set bits in mask.
 *
 * The set bits in mask are copied to an unsigned char variable.
 *
 * For example,
 *
 * data = 0101 0101 1010 1010 0101 0101 1010 1010 = 0x55aa55aa
 * mask = 0000 0000 0001 0011 0011 0000 0010 0110 = 0x00133026
 *                     ^   ^^   ^^        ^   ^^
 * retVal =            0   10   01        1   01  = 0x4d
 *
 *
 * PARAMETERS:
 * ------------
 * uint32_t data: a 32 bit integer that will be operated on
 *
 * uint32_t mask: the bit packed data that indicates the bits to be copied to result
 *
 * RETURNS:
 * ------------
 * The extracted sequence stored in a single unsigned char.
 *
 */
/*Start a while loop that will continue as long as mask is not 0 and j is less than 8.
Within the loop, perform a bitwise AND operation between mask and 1. If the
result is not 0, this means that the least significant bit of mask is set, and
the corresponding bit in data should be extracted.  If the least significant bit
of mask is set, perform a bitwise AND operation between data and 1 << i. If the
result is not 0, this means that the corresponding bit in data is set. In this
case, set the corresponding bit in retVal using the bitwise OR operation retVal
|= (1 << j).  Increment the value of j by 1.  Right-shift data by 1. This means
that the least significant bit of data will be discarded and the next bit will
become the least significant bit.  Right-shift mask by 1. This means that the
least significant bit of mask will be discarded and the next bit will become the
least significant bit.*/

uint8_t op_bit_get_sequence(uint32_t data, uint32_t mask)
{
	uint8_t retVal = 0;
	int 	j = 0;

	while (mask && j < 8)
	{
		if (mask & 1)
		{
			if(data & (1 << 0))
				retVal |= (1 << j);
			j++;
		}
		data >>= 1;
		mask >>= 1;
	}
	return (retVal) ;
}
/*(lldb) frame variable
(uint32_t) data = 0b01010101101010100101010110101010
(uint32_t) mask = 0b00000000000100110011000000100110
							   0  10  01      1  01
(uint8_t) retVal = 0b00000000
(int) i = 0
(int) j = 8
(lldb)
00100110) at bit_sequence.c:34:10
   31
   32  	uint8_t op_bit_get_sequence(uint32_t data, uint32_t mask)
   33  	{
-> 34  		uint8_t retVal = 0;
   35  		int		i = 0;
   36  		int 	j = 0;
   37
Target 0: (a.out) stopped.
(lldb) gui
(lldb) frame variable
(uint32_t) data = 0b00000000000000000010101011010101
(uint32_t) mask = 0b00000000000000000000000000001001
(uint8_t) retVal = 0b01001101
(int) i = 0
(int) j = 6
(lldb)
*/
