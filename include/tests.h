#pragma once
#ifndef TEST_H
#define TEST_H


int test();

// char* EncodeData(const unsigned char* data_in, unsigned int length_in, unsigned int* length_out);
// unsigned char* DecodeData(const char* code_in, unsigned int length_in, unsigned int* length_out);
int EncodeDecodeTest(const char* string);
int LengthEstimateTest();

int OverwriteTest();
int DecodeEncodeTest();
int RFC4648Test();
int BitEncDecTest();
int PartialTest();

#endif