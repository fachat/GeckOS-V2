
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(int argc, char *argv[]) {

	int textoffset = 0;
	int dataoffset = 0;
	int bssoffset = 0;
	int zerooffset = 0;

	char *line = NULL;
	ssize_t len = 0;
	ssize_t nread = 0;

	char *tok = NULL;

	if (argc > 1) {
		textoffset = atoi(argv[1]);
	}
	if (argc > 2) {
		dataoffset = atoi(argv[2]);
	}
	if (argc > 3) {
		bssoffset = atoi(argv[3]);
	}
	if (argc > 4) {
		zerooffset = atoi(argv[4]);
	}

	fprintf(stderr, "offsets: %d, %d, %d, %d\n", 
		textoffset, dataoffset, bssoffset, zerooffset);

	while ((nread = getline(&line, &len, stdin)) != -1) {
		char name[64];
		int addr = 0;
		int blk = 0;
		int afl = 0;
		int seg = 0;
		int diff = 0;

		fprintf(stderr, "line -> %s", line);

		// note that this scanf includes the ending comma in the name
		sscanf(line, "%64s %x, %d, %x", name, &addr, &blk, &afl);

		seg = afl & 0x0f;
		switch(seg) {
		case 2:
			diff = textoffset;
			break;
		case 3: 
			diff = dataoffset;
			break;
		case 4:
			diff = bssoffset;
			break;
		case 5:
			diff = zerooffset;
			break;
		}		
		addr += diff;

		fprintf(stderr, "%s 0x%04x, %d, 0x%04x (seg=%d, diff=%d)\n", name, addr, blk, afl, seg, diff);

		printf("%s 0x%04x, %d, 0x%04x\n", name, addr, blk, afl);
	}
	free(line);
}

