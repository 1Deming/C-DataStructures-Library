/**
 * @file UnitTest.c
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 *
 * @date 15/10/2018
 */

#include "UnitTest.h"

unsigned_t GlobalTotalTests = 0;
unsigned_t GlobalTotalPassed = 0;
unsigned_t GlobalTotalErrors = 0;

Status ut_init(UnitTest *ut)
{
    *ut = malloc(sizeof(UnitTest_t));

    if (!(*ut))
        return DS_ERR_ALLOC;

    (*ut)->total = 0;
    (*ut)->passed = 0;

    return DS_OK;
}

Status ut_delete(UnitTest *ut)
{
    if (*ut == NULL)
        return DS_ERR_NULL_POINTER;

    free(*ut);

    *ut = NULL;

    return DS_OK;
}

void ut_report(UnitTest ut, const char *struct_name)
{
    printf("+--------------------------------------------------+\n");
    printf("|                  UnitTest Report                 |\n");
    printf("+--------------------------------------------------+\n");
    printf("  Name   : %s\n", struct_name);
    printf("  Total  : %lld\n", ut->total);
    printf("  Passed : %lld\n\n", ut->passed);
}

void ut_equals_bool(UnitTest ut, bool param1, bool param2,
        const char *test_name)
{
    if (param1 == param2)
    {
        ut->passed++;
        GlobalTotalPassed++;
        printf("%-40s %s", test_name, "PASSED\n");
    }
    else
    {
        printf("%-40s %s", test_name, "FAILED !\n");
    }

    ut->total++;
    GlobalTotalTests++;
}

void ut_equals_int(UnitTest ut, int param1, int param2, const char *test_name)
{
    if (param1 == param2)
    {
        ut->passed++;
        GlobalTotalPassed++;
        printf("%-40s %s", test_name, "PASSED\n");
    }
    else
    {
        printf("%-40s %s", test_name, "FAILED !\n");
    }

    ut->total++;
    GlobalTotalTests++;
}

void ut_equals_integer_t(UnitTest ut, integer_t param1, integer_t param2,
        const char *test_name)
{
    if (param1 == param2)
    {
        ut->passed++;
        GlobalTotalPassed++;
        printf("%-40s %s", test_name, "PASSED\n");
    }
    else
    {
        printf("%-40s %s", test_name, "FAILED !\n");
    }

    ut->total++;
    GlobalTotalTests++;
}

void ut_equals_unsigned_t(UnitTest ut, unsigned_t param1, unsigned_t param2,
        const char *test_name)
{
    if (param1 == param2)
    {
        ut->passed++;
        GlobalTotalPassed++;
        printf("%-40s %s", test_name, "PASSED\n");
    }
    else
    {
        printf("%-40s %s", test_name, "FAILED !\n");
    }

    ut->total++;
    GlobalTotalTests++;
}

void ut_equals_double(UnitTest ut, double param1, double param2,
                          const char *test_name)
{
    if (param1 == param2)
    {
        ut->passed++;
        GlobalTotalPassed++;
        printf("%-40s %s", test_name, "PASSED\n");
    }
    else
    {
        printf("%-40s %s", test_name, "FAILED !\n");
    }

    ut->total++;
    GlobalTotalTests++;
}

void ut_error()
{
    GlobalTotalErrors++;
}

void FinalReport()
{
    printf("+--------------------------------------------------------------------------------+\n");
    printf("|                                  Final Report                                  |\n");
    printf("+--------------------------------------------------------------------------------+\n");
    printf("    Total Tests  : %llu\n", GlobalTotalTests);
    printf("    Total Passed : %llu\n", GlobalTotalPassed);
    printf("    Total Failed : %llu\n", GlobalTotalTests - GlobalTotalPassed);
    printf("    Total Errors : %llu\n\n", GlobalTotalErrors);
}
