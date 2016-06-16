/*
 * tests.c
 *
 *  Created on: 3 cze 2016
 *      Author: Łukasz
 */

#ifdef TEST
#include "unity.h"
#include "board.h"
#include "diagnostic.h"
#include "i2c_temperature.c"
//test functions

void test1()
{
	TEST_ASSERT_EQUAL(1,showTempChange(25,25));

	TEST_ASSERT_TRUE(Board_LED_Test(1));
	TEST_ASSERT_FALSE(Board_LED_Test(0));
	TEST_ASSERT_FALSE(Board_LED_Test(2));
}

void test2()
{
	TEST_ASSERT_EQUAL(2,showTempChange(25,24));

	TEST_ASSERT_TRUE(Board_LED_Test(2));
	TEST_ASSERT_FALSE(Board_LED_Test(0));
	TEST_ASSERT_FALSE(Board_LED_Test(1));
}

void test3()
{
	TEST_ASSERT_EQUAL(0,showTempChange(24,25));

	TEST_ASSERT_TRUE(Board_LED_Test(0));
	TEST_ASSERT_FALSE(Board_LED_Test(1));
	TEST_ASSERT_FALSE(Board_LED_Test(2));
}

void main(void )
{
	Board_Init();
	//......unity code

	UNITY_BEGIN();

    RUN_TEST(test1);
    RUN_TEST(test2);
    RUN_TEST(test3);

	return UNITY_END();
}
#endif
