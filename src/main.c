#include <stdio.h>
// #include <tests.h>
#include <cbase64/cbase64.h>
#define CBASE64_IMPLEMENTATION
char* EncodeData(const unsigned char* data_in, unsigned int length_in, unsigned int* length_out)
{
    const unsigned int encodedLength = cbase64_calc_encoded_length(length_in);
    char* codeOut = (char*)malloc(encodedLength);
    char* codeOutEnd = codeOut;

    cbase64_encodestate encodeState;
    cbase64_init_encodestate(&encodeState);
    codeOutEnd += cbase64_encode_block(data_in, length_in, codeOutEnd, &encodeState);
    codeOutEnd += cbase64_encode_blockend(codeOutEnd, &encodeState);

    *length_out = (codeOutEnd - codeOut);
    return codeOut;
}

unsigned char* DecodeData(const char* code_in, unsigned int length_in, unsigned int* length_out)
{
    const unsigned int decodedLength = cbase64_calc_decoded_length(code_in, length_in);
    unsigned char* dataOut = (unsigned char*)malloc(decodedLength);

    cbase64_decodestate decodeState;
    cbase64_init_decodestate(&decodeState);
    *length_out = cbase64_decode_block(code_in, length_in, dataOut, &decodeState);
    return dataOut;
}

char* encode_data(const unsigned char* data_in, unsigned int* size_out)
{
    const unsigned int length = 1 + strlen(data_in);
    return EncodeData(data_in, length, &size_out);
}

unsigned char* decode_data(const char* data_in, unsigned int* size_out)
{
    const char* in = data_in;
    const unsigned int length = 1 + strlen(data_in);
    return DecodeData(in, length, &size_out);
}

int main()
{
	const char * STRING1  = "Hi my name is jason";
	const char * STRING2  = "SSB3b3JrIGZvciBEZWxsIFRlY2hub2xvZ2llcyE=";
	printf("Hello World!\n");
	unsigned int el = 0;
	const char * er = encode_data((unsigned char *)STRING1, &el);
	el = 0;
    const char * dr = decode_data((unsigned char *)STRING2, &el);
	printf(dr);
	printf(er);
	FREE_BASE64(er);

	// int result = test();
	return (0);
}