#ifndef BASE64_CF
#define BASE64_CF

#include <stdio.h>
#include <stdlib.h>
#include <_types.h>

static const char *symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static char *base64_encode(void *data, unsigned int length){

	char *s = (char*) data;
	unsigned int new_length = (length + 2) / 3 * 4;
	printf("%u ", new_length);
	unsigned int padding = length % 3;
	char *target = malloc(sizeof(char)*new_length);
	if (!target) return NULL;

	int j = 0;
	for (int i = 0; i < length-2; i = i+3) {
		u_int32_t pos = 0 | s[i] << 16 | s[i+1] << 8 | s[i+2];
		target[j++] = symbols[pos >> 18];
		target[j++] = symbols[(pos >> 12) & 0x3F];
		target[j++] = symbols[(pos >> 6) & 0x3F];
		target[j++] = symbols[pos & 0x3F];
	}

	if (padding == 1) {
		u_int8_t pos = s[length-1];
		target[j++] = symbols[pos >> 2];
		target[j++] = symbols[(pos << 4) & 0x3F];
		target[j++] = '=';
		target[j] = '=';
	} else if (padding == 2) {
		u_int16_t pos = s[length-2] << 8 | s[length-1];
		target[j++] = symbols[pos >> 10];
		target[j++] = symbols[(pos >> 4) & 0x3F];
		target[j++] = symbols[(pos << 2) & 0x3F];
		target[j] = '=';
	}

	return target;
}

#endif // BASE64_CF
