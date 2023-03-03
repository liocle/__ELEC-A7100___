#include "header.h"
#include <stdio.h>

int main()
{
    /* Feel free to modify this function to test different things */

    uint32_t ackHeader = createAckHeader(120, 207, 21, 0);
    uint32_t nackHeader = createAckHeader(62, 209, 5, 1);
    uint32_t frameHeader = createHeader(15, 22, 8, 2);
    uint32_t blaHeader = createHeader(33, 89, 21, 0);
    uint32_t blablaHeader = createHeader(64, 113, 6, 0);
	

    printf("Ack Header: valid %d, source %d frame id %d type %d \n", validateHeader(ackHeader), getSourceAddress(ackHeader), getFrameId(ackHeader), getFrameType(ackHeader));
    printf("Nack Header: valid %d, source %d frame id %d type %d \n", validateHeader(nackHeader), getSourceAddress(nackHeader), getFrameId(nackHeader), getFrameType(nackHeader));
    printf("Frame Header: valid %d, source %d frame id %d type %d \n", validateHeader(frameHeader), getSourceAddress(frameHeader), getFrameId(frameHeader), getFrameType(frameHeader));
    printf("Bla Header: valid %d, source %d frame id %d type %d \n", validateHeader(blaHeader), getSourceAddress(blaHeader), getFrameId(blaHeader), getFrameType(blaHeader));
    printf("Blabla Header: valid %d, source %d frame id %d type %d \n", validateHeader(blablaHeader), getSourceAddress(blablaHeader), getFrameId(blablaHeader), getFrameType(blablaHeader));

    return 0;
}
