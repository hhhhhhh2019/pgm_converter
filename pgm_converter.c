#include <pgm.h>
#include <stdio.h>

int main(int argc, char** argv) {
	if (argc != 3) {
		printf("Convert ascii pgm to binary pgm.\nUsage: %s <input file> <output file>\n", argv[0]);
		return 0;
	}

	PGM pgm;
	read_pgm(argv[1], &pgm);

	FILE* f = fopen(argv[2], "wb");
	
	fprintf(f, "P5\n%d %d\n%d\n", pgm.width, pgm.height, 255);

	for (int i = 0; i < pgm.height; i++)
		fwrite(pgm.data[i], sizeof(char), pgm.width, f);

	fclose(f);
}
