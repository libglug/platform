#include <CUnit/Basic.h>
#include <CUnit/Assert.h>

#include <create_suite.h>

#include "mocks/Windows.h"
#include <src/win32/system.h>

void test_cpus(void)
{
    // 8 cpus, all active
    set_system_cpus(8, (1 << 8) - 1);
    CU_ASSERT_EQUAL(cpu_count_win(), 8)

    // 2 cpus, none active
    set_system_cpus(2, 0);
    CU_ASSERT_EQUAL(cpu_count_win(), 2)
}

void test_active(void)
{
    // 32 cpus, 16 active
    set_system_cpus(32, (1 << 16) - 1);
    CU_ASSERT_EQUAL(active_cpus_win(), 16)

    // 8 cpus, 4 active
    set_system_cpus(8, 1 | 2 | 8 | 32);
    CU_ASSERT_EQUAL(active_cpus_win(), 4)
}

void test_memory(void)
{
    // 16 Gib as KB
    set_memory(17179869184 / 1024);
    CU_ASSERT_EQUAL(physical_mem_win(), 17179869184)

    // fail to fetch memory once
    set_memory_failure_count(1);
    CU_ASSERT_EQUAL(physical_mem_win(), 0)
    CU_ASSERT_EQUAL(physical_mem_win(), 17179869184)
}

int main(void)
{
    CU_pSuite suite = create_suite("windows system", NULL, NULL);
    if (!suite) return CU_get_error();

    CU_add_test(suite, "cpus", test_cpus);
    CU_add_test(suite, "active cpus", test_active);
    CU_add_test(suite, "physical memory", test_memory);

    return run_tests(CU_BRM_VERBOSE);
}
