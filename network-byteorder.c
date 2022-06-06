#include <inttypes.h>
#include <stdio.h>
#include <arpa/inet.h>

typedef union
{
	uint32_t value;
	unsigned char bytes[sizeof(uint32_t)];
} ValueBytes;

static void hexdump(const void *data, size_t n)
{
	if(!n)
		return;

	const unsigned char *bytes = (const unsigned char *)data;

	printf("%02x", (unsigned)bytes[0]);
	for(size_t i=1U; i<n; ++i)
		printf(" %02x", (unsigned)bytes[i]);
}

int main(void)
{
	ValueBytes vb = {
		.bytes = { '\xfe', '\xe1', '\xde', '\xad' }
	};

	printf("Assume following bytes have been received:\n");
	hexdump(vb.bytes, sizeof(vb.bytes));
	putchar('\n');

	printf("If interpreted as an unsigned 32 bit integer, the value of that\n");
	printf("byte sequence is %#" PRIx32 " on your machine.\n", vb.value);

	vb.value = ntohl(vb.value);

	printf("After calling ntohl() on this byte sequence, the order of the bytes changed:\n");
	hexdump(vb.bytes, sizeof(vb.bytes));
	putchar('\n');
	printf("The value of it, when interpreted as an unsigned 32 bit integer is now: %#" PRIx32 "\n", vb.value);

	return 0;
}
