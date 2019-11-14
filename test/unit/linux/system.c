#include <CUnit/Basic.h>
#include <CUnit/Assert.h>

#include <create_suite.h>

#include "mocks/unistd.h"
#include <src/system/linux/system.h>

void test_cpus(void)
{
    // 8 cpus
    set_popen_output("CPU(s):     8");
    CU_ASSERT_EQUAL(cpu_count_linux(), 8)

    // 2 cpus
    set_popen_output("CPU(s): 2");
    CU_ASSERT_EQUAL(cpu_count_linux(), 2)

    // fail to fetch cpus once
    set_popen_failure_count(1);
    CU_ASSERT_EQUAL(cpu_count_linux(), 0)
    CU_ASSERT_EQUAL(cpu_count_linux(), 2)

    // bad output from popen
    set_popen_output("garbagetext");
    CU_ASSERT_EQUAL(cpu_count_linux(), 0)
}

void test_active(void)
{
    // 3 active cpus
    set_popen_output("3");
    CU_ASSERT_EQUAL(active_cpus_linux(), 4)

    // fail to fetch active cpus once
    set_popen_failure_count(1);
    CU_ASSERT_EQUAL(active_cpus_linux(), 0)
    CU_ASSERT_EQUAL(active_cpus_linux(), 4)

    // bad output from popen
    set_popen_output("validcpus124");
    CU_ASSERT_EQUAL(active_cpus_linux(), 0)
}

void test_memory(void)
{
    // 16 Gib
    set_popen_output("Mem: 17179869184");
    CU_ASSERT_EQUAL(physical_mem_linux(), 17179869184)

    // fail to fetch memory
    set_popen_failure_count(1);
    CU_ASSERT_EQUAL(physical_mem_linux(), 0)
    CU_ASSERT_EQUAL(physical_mem_linux(), 17179869184)

    // bad output from popen
    set_popen_output("ha");
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
