#include <stdio.h>
// #include <tests.h>
#define CBASE64_IMPLEMENTATION
#include <cbase64/cbase64.h>


// extern inline char* encode_data(const unsigned char* data_in, unsigned int* size_out);
// extern inline unsigned char* decode_data(const char* data_in, unsigned int* size_out);

int main()
{
	const char * STRING1  = "Hi my name is jason";
	const char * STRING2  = "SSB3b3JrIGZvciBEZWxsIFRlY2hub2xvZ2llcyE=";
	printf("Hello World!\n");
	unsigned int el = 0;
	const char * er = encode_data((unsigned char *)STRING1, &el);
	el = 0;
    const unsigned char * dr = decode_data(STRING2, &el);
	printf("%s", dr);
	printf("%s", er);
	FREE_BASE64(er);
	FREE_BASE64(dr);

	// int result = test();
	return (0);
}
