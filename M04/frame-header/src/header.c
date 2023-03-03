#include "header.h"

/*
 * You are required to implement the parser functions below.
 *
 * int validateHeader(uint32_t header); function validates the header. A header
 * is valid if all the conditions below evaluate true.
 *  - SYNC field is equal to 0x2a
 *  - if ACK bit is set V bit is also
 *  - if ACK bit is reset TYPE is non-zero.
 * 
	- SOURCE ADDRESS and DESTINATION ADDRESS are non-zero and different than each other.
 *
 *  If the header is valid, the function returns 1 otherwise it returns 0.
 *
 * int getFrameId(uint32_t header); function returns FRAME ID field if the
 * header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise,
	it returns non-negative integer corresponding to FRAME ID field.
 *
 * int getFrameType(uint32_t header); function returns TYPE field if the header
 * is valid, possibly checked using validateHeader function above, and ACK bit
 * is reset.
 *  - If the header is not valid, it returns -1.
 *  - If ACK bit is set, it returns 0.
 *  - Otherwise, it returns non-negative integer corresponding to TYPE field.
 *
 * int getSourceAddress(uint32_t header); function returns SOURCE ADDRESS field
 * if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise,
	it returns non-negative integer corresponding to SOURCE ADDRESS field.
 */

const uint32_t	SYNC_MASK = 0x3F; // 111111
const uint32_t	SYNC_SHIFT = 0;
const uint32_t	ACK_MASK = 0x40;  // 100000
const uint32_t	ACK_SHIFT = 6;
const uint32_t	V_MASK = 0x80; // 0100000
const uint32_t	V_SHIFT = 7;
const uint32_t	TYPE_MASK = 0x700; // 111000000
const uint32_t	TYPE_SHIFT = 8;
const uint32_t	FRAMEID_MASK = 0xF800; // 1111100000000
const uint32_t	FRAMEID_SHIFT = 11;
const uint32_t	SRC_ADDR_MASK = 0xFF0000; // 1111110000000000
const uint32_t	SRC_ADDR_SHIFT = 16;
const uint32_t	DST_ADDR_MASK = 0xFF000000; // 111111000000000000
const uint32_t	DST_ADDR_SHIFT = 24;

int	validateHeader(uint32_t header)
{
	uint32_t	src;
	uint32_t	dst;

	src = (header & SRC_ADDR_MASK) >> SRC_ADDR_SHIFT;
	dst = (header & DST_ADDR_MASK) >> DST_ADDR_SHIFT;
	if ((header & SYNC_MASK) == 0x2a)
	{
		if (((header & ACK_MASK) >> ACK_SHIFT == 1) && ((header & V_MASK) >> V_SHIFT == 1))
		{
			if (src && dst && src != dst)
				return (1);
		}
		else if (((header & ACK_MASK) >> ACK_SHIFT == 0) && ((header & TYPE_MASK) >> TYPE_SHIFT != 0))
			{
				if (src && dst && (src != dst))
					return (1);
			}
	}
	return (0);
}

int	getFrameId(uint32_t header)
{
	if (validateHeader(header))
		return ((header & FRAMEID_MASK) >> FRAMEID_SHIFT);
	return (-1);
}

int	getFrameType(uint32_t header)
{
	if (validateHeader(header))
	 {
		if ((header & ACK_MASK) >> ACK_SHIFT)
			return (0);
		else 
			return ((header & TYPE_MASK) >> TYPE_SHIFT);
	}
	return (-1);
}
int	getSourceAddress(uint32_t header)
{
	if (validateHeader(header))
		return ((header & SRC_ADDR_MASK) >> SRC_ADDR_SHIFT);
	return (-1);
}
uint32_t	createAckHeader(int destAddress, int sourceAddress, uint8_t frameId, char valid)
{
	uint32_t	ack_header;

	ack_header = 0;
	ack_header = ack_header | ((0x2a << SYNC_SHIFT) & SYNC_MASK);
	ack_header = ack_header | ((1 << ACK_SHIFT) & ACK_MASK);
	ack_header = ack_header | ((valid << V_SHIFT) & V_MASK);
//	if (!valid)
//		ack_header = ack_header | ((1 << TYPE_SHIFT) & TYPE_MASK);
//	else
//		ack_header = ack_header | ((0 << TYPE_SHIFT) & TYPE_MASK);
	ack_header = ack_header | ((frameId << FRAMEID_SHIFT) & FRAMEID_MASK);
	ack_header = ack_header | ((sourceAddress << SRC_ADDR_SHIFT) & SRC_ADDR_MASK);
	ack_header = ack_header | ((destAddress << DST_ADDR_SHIFT) & DST_ADDR_MASK);
	return (ack_header);


}

uint32_t	createHeader(int destAddress, int sourceAddress, uint8_t frameId, uint8_t type)
{
	uint32_t header;

	header = 0;
	header = header | ((0x2a) & SYNC_MASK);
	header = header | ((type << TYPE_SHIFT) & TYPE_MASK);
	header = header | ((frameId << FRAMEID_SHIFT) & FRAMEID_MASK);
	header = header | ((sourceAddress << SRC_ADDR_SHIFT) & SRC_ADDR_MASK);
	header = header | ((destAddress << DST_ADDR_SHIFT) & DST_ADDR_MASK);
	return (header);
}
