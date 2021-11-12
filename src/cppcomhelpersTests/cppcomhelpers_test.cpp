#include "pch.h"
#include "cppcomhelpers.h"

HRESULT abc(void *p)
{
	HR_GUARD_FAILED(S_OK);
	HR_GUARD_NULL_POINTER(p);
	return S_OK;
}

TEST(TestCaseName, TestName)
{
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);

	int n = 1;
	EXPECT_EQ(abc((void*)&n), S_OK);

	EXPECT_EQ(abc(NULL), E_POINTER);
}
