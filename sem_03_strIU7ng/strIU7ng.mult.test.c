#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strIU7ng.h"

int test_strIU7ng_mult_empty_1();
int test_strIU7ng_mult_empty_2();
int test_strIU7ng_mult_neg();
int test_strIU7ng_mult_normal_1();
int test_strIU7ng_mult_normal_2();


int main(void)
{
	int ec;
	int rc  = EXIT_SUCCESS;
	
	setbuf(stdout, NULL);
	
	ec = test_strIU7ng_mult_empty_1();
	if (ec != EXIT_SUCCESS)
		rc = ec;
	ec = test_strIU7ng_mult_empty_2();
	if (ec != EXIT_SUCCESS)
		rc = ec;
	ec = test_strIU7ng_mult_neg();
	if (ec != EXIT_SUCCESS)
		rc = ec;
	ec = test_strIU7ng_mult_normal_1();
	if (ec != EXIT_SUCCESS)
		rc = ec;
	ec = test_strIU7ng_mult_normal_2();
	if (ec != EXIT_SUCCESS)
		rc = ec;
	
	return rc;
}

int test_strIU7ng_mult_empty_1()
{
	int multiplier = 0;
	strIU7ng str_src = strIU7ng_create("a");
	strIU7ng str_exp = strIU7ng_create("");
	strIU7ng str_res;
	
	str_src.head[1] = 0;
	str_src.len = 1;
	
	str_exp.head[0] = 0;
	str_exp.len = 0;
	
	printf("Test strIU7ng_mult. Empty 1 ");
	
	str_res = strIU7ng_mult(str_src, multiplier);
	if (strcmp(str_res.head, str_exp.head) == 0)
	{
		printf("Success.\n");
		
		strIU7ng_free(&str_src);
		strIU7ng_free(&str_exp);
		strIU7ng_free(&str_res);
		
		return EXIT_SUCCESS;
	}
	
	printf("Failure.\n");
	
	printf("Multiplier: %d\n", multiplier);
	printf("Source: %s\n", str_src.head);
	printf("Expected: %s\n", str_exp.head);
	printf("Received: %s\n", str_res.head);
	
	strIU7ng_free(&str_src);
	strIU7ng_free(&str_exp);
	strIU7ng_free(&str_res);
	
	return EXIT_FAILURE;
}

int test_strIU7ng_mult_empty_2()
{
	int multiplier = 14;
	strIU7ng str_src = strIU7ng_create("");
	strIU7ng str_exp = strIU7ng_create("");
	strIU7ng str_res;
	
	str_src.head[0] = 0;
	str_src.len = 0;
	
	str_exp.head[0] = 0;
	str_exp.len = 0;
	
	printf("Test strIU7ng_mult. Empty 2 ");
	
	str_res = strIU7ng_mult(str_src, multiplier);
	if (strcmp(str_res.head, str_exp.head) == 0)
	{
		printf("Success.\n");
		
		strIU7ng_free(&str_src);
		strIU7ng_free(&str_exp);
		strIU7ng_free(&str_res);
		
		return EXIT_SUCCESS;
	}
	
	printf("Failure.\n");
	
	printf("Multiplier: %d\n", multiplier);
	printf("Source: %s\n", str_src.head);
	printf("Expected: %s\n", str_exp.head);
	printf("Received: %s\n", str_res.head);
	
	strIU7ng_free(&str_src);
	strIU7ng_free(&str_exp);
	strIU7ng_free(&str_res);
	
	return EXIT_FAILURE;
}

int test_strIU7ng_mult_neg()
{
	int multiplier = -88;
	strIU7ng str_src = strIU7ng_create("Spasibo");
	strIU7ng str_exp = strIU7ng_create("Spasibo");
	strIU7ng str_res;
	
	str_src.head[7] = 0;
	str_src.len = 7;
	
	str_exp.head[7] = 0;
	str_exp.len = 7;
	
	printf("Test strIU7ng_mult. Negative multiplier ");
	
	str_res = strIU7ng_mult(str_src, multiplier);
	if (strcmp(str_res.head, str_exp.head) == 0)
	{
		printf("Success.\n");
		
		strIU7ng_free(&str_src);
		strIU7ng_free(&str_exp);
		strIU7ng_free(&str_res);
		
		return EXIT_SUCCESS;
	}
	
	printf("Failure.\n");
	
	printf("Multiplier: %d\n", multiplier);
	printf("Source: %s\n", str_src.head);
	printf("Expected: %s\n", str_exp.head);
	printf("Received: %s\n", str_res.head);
	
	strIU7ng_free(&str_src);
	strIU7ng_free(&str_exp);
	strIU7ng_free(&str_res);
	
	return EXIT_FAILURE;
}

int test_strIU7ng_mult_normal_1()
{
	int multiplier = 1;
	strIU7ng str_src = strIU7ng_create("Bolshoe");
	strIU7ng str_exp = strIU7ng_create("Bolshoe");
	strIU7ng str_res;
	
	str_src.head[7] = 0;
	str_src.len = 7;
	
	str_exp.head[7] = 0;
	str_exp.len = 7;
	
	printf("Test strIU7ng_mult. Normal 1 ");
	
	str_res = strIU7ng_mult(str_src, multiplier);
	if (strcmp(str_res.head, str_exp.head) == 0)
	{
		printf("Success.\n");
		
		strIU7ng_free(&str_src);
		strIU7ng_free(&str_exp);
		strIU7ng_free(&str_res);
		
		return EXIT_SUCCESS;
	}
	
	printf("Failure.\n");
	
	printf("Multiplier: %d\n", multiplier);
	printf("Source: %s\n", str_src.head);
	printf("Expected: %s\n", str_exp.head);
	printf("Received: %s\n", str_res.head);
	
	strIU7ng_free(&str_src);
	strIU7ng_free(&str_exp);
	strIU7ng_free(&str_res);
	
	return EXIT_FAILURE;
}

int test_strIU7ng_mult_normal_2()
{
	int multiplier = 3;
	strIU7ng str_src = strIU7ng_create("!");
	strIU7ng str_exp = strIU7ng_create("!!!");
	strIU7ng str_res;
	
	str_src.head[1] = 0;
	str_src.len = 1;
	
	str_exp.head[3] = 0;
	str_exp.len = 3;
	
	printf("Test strIU7ng_mult. Normal 2 ");
	
	str_res = strIU7ng_mult(str_src, multiplier);
	if (strcmp(str_res.head, str_exp.head) == 0)
	{
		printf("Success.\n");
		
		strIU7ng_free(&str_src);
		strIU7ng_free(&str_exp);
		strIU7ng_free(&str_res);
		
		return EXIT_SUCCESS;
	}
	
	printf("Failure.\n");
	
	printf("Multiplier: %d\n", multiplier);
	printf("Source: %s\n", str_src.head);
	printf("Expected: %s\n", str_exp.head);
	printf("Received: %s\n", str_res.head);
	
	strIU7ng_free(&str_src);
	strIU7ng_free(&str_exp);
	strIU7ng_free(&str_res);
	
	return EXIT_FAILURE;
}