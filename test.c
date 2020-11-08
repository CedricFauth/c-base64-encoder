#include "base64.h"
#include "string.h"

int main(int argc, char **argv) {

	if (argc != 2) return 0;

	char *data = argv[1];
	unsigned int l = strlen(data);
	char *base64_string = base64_encode(data, l);

	printf("%s\n", base64_string);
	free(base64_string);
}
