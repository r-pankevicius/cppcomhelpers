#include "pch.h"
#include "comhelpers.h"

HRESULT macroUsage(void *p)
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
	EXPECT_EQ(macroUsage((void*)&n), S_OK);

	EXPECT_EQ(macroUsage(NULL), E_POINTER);
}
