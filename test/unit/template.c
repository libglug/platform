#include <CUnit/Basic.h>
#include <CUnit/Assert.h>

#include "../create_suite.h"

int main(void)
{
    CU_pSuite suite = create_suite("", NULL, NULL);
    if (!suite) return CU_get_error();

    // CU_add_test()

    return run_tests(CU_BRM_VERBOSE);
}
