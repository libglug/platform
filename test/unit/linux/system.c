#include <CUnit/Basic.h>
#include <CUnit/Assert.h>

#include <create_suite.h>

#include "mocks/unistd.h"
#include <src/linux/system.h>

void test_cpus(void)
{
    set_popen_output("CPU(s):     8");
    CU_ASSERT_EQUAL(cpu_count_linux(), 8)

    set_popen_output("CPU(s): 2");
    CU_ASSERT_EQUAL(cpu_count_linux(), 2)

    set_popen_failure_count(1);
    CU_ASSERT_EQUAL(cpu_count_linux(), 0)
    CU_ASSERT_EQUAL(cpu_count_linux(), 2)

    set_popen_output("0");
    CU_ASSERT_EQUAL(cpu_count_linux(), 0)
}

void test_active(void)
{
    set_popen_output("3");
    CU_ASSERT_EQUAL(active_cpus_linux(), 4)

    set_popen_failure_count(1);
    CU_ASSERT_EQUAL(active_cpus_linux(), 0)
    CU_ASSERT_EQUAL(active_cpus_linux(), 4)

    set_popen_output("0");
    CU_ASSERT_EQUAL(active_cpus_linux(), 0)
}

void test_memory(void)
{
    set_popen_output("Mem: 17179869184");
    CU_ASSERT_EQUAL(physical_mem_linux(), 17179869184)

    set_popen_failure_count(1);
    CU_ASSERT_EQUAL(physical_mem_linux(), 0)
    CU_ASSERT_EQUAL(physical_mem_linux(), 17179869184)

    set_popen_output("0");
    CU_ASSERT_EQUAL(physical_mem_linux(), 0)
}

int main(void)
{
    CU_pSuite suite = create_suite("linux system", NULL, NULL);
    if (!suite) return CU_get_error();

    CU_add_test(suite, "cpus", test_cpus);
    CU_add_test(suite, "active cpus", test_active);
    CU_add_test(suite, "physical memory", test_memory);

    return run_tests(CU_BRM_VERBOSE);
}
