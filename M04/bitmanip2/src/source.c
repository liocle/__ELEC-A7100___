/*
Implement below function **mergeBits** which takes two 4 bit number as input values 
and returns a 8 bit value. This 8 bit value is formed from the two input values **a**
and **b**. The value **a** forms the 4 higher order bits of the return value whereas
**b** forms 4 lower order bits of the return value. For example, when a function 
is called as follows: `mergeBits (0x6, 0xD)`, then result will be eight-bit number, 
which is the hexadecimal representation `6D`.
*/

// define mergeBits function here
unsigned char mergeBits(unsigned char a, unsigned char b)
{
	unsigned char res;
	/* Shift the bits of a 4 positions to the left to make space for b */
	res = a << 4;
    /* Perform a bitwise OR operation to combine the 4 higher order bits of a and the 4 lower order bits of b */
	res = res | b;
	return (res);
}
