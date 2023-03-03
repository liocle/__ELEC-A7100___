/*
Implement below function **sixBits** which returns only least significant six bits
of the input value **v**. Rest of the two highest significant bits must be reset.
(i.e) If the input value **v** is **11110000**, then **sixBits** function must return
**110000**. One way to accomplish this is to use a bit mask.
*/

#include <stdio.h>

// define sixBits function here
// (1 << i) generates value where only i'th bit is set
// value & (1 << i)) is non-zero only if i'th bit is set in value

#define BIT_MASK (0x3F) //defines 6 least significant bits.

unsigned char sixBits(unsigned char v)
{
	unsigned char b = (v & BIT_MASK);
	return b;
}