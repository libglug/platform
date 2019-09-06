#include <CUnit/Basic.h>
#include <CUnit/Assert.h>

#include <create_suite.h>

#include "mocks/unistd.h"
#include <src/linux/system.h>

void test_cpus(void)
{
    set_lscpu_output("CPU(s):     5");
    CU_ASSERT_EQUAL(cpu_count_linux(), 5);

    set_lscpu_output("CPU(s): 2");
    CU_ASSERT_EQUAL(cpu_count_linux(), 2);

    set_lscpu_failure(1);
    CU_ASSERT_EQUAL(cpu_count_linux(), 0);
    CU_ASSERT_EQUAL(cpu_count_linux(), 2);
}

int main(void)
{
    CU_pSuite suite = create_suite("linux system", NULL, NULL);
    if (!suite) return CU_get_error();

    CU_add_test(suite, "cpus", test_cpus);

    return run_tests(CU_BRM_VERBOSE);
}
