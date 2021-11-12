// cppcomhelpers.h

#pragma once

#include <atlbase.h>
#include <atlcom.h>
#include <wtypes.h>
#include <vcruntime.h>
#include <winerror.h>

/// <summary>
/// Utility functions to make standard COM methods implementation (STDMETHODIMP) easier.
/// </summary>
class cppcomhelpers
{
public:
	/// <summary>
	/// Helper function to implement get_PropertyName(T* pRetVal): *pRetVal = value.
	/// Use when no type conversions are needed between the backing value and return value.
	/// </summary>
	template<class T> static HRESULT Get(const T value, T* pRetVal) noexcept
	{
		if (NULL == pRetVal)
			return E_POINTER;

		*pRetVal = value;
		return S_OK;
	}

	/// <summary>
	/// Helper function to implement put_PropertyName(T newValue): refValueToSet = newValue.
	/// Use when no type conversions are needed between value to be assigned (newValue) and the backing value.
	/// </summary>
	template<class T> static HRESULT Put(const T newValue, T& refValueToSet) noexcept
	{
		refValueToSet = newValue;
		return S_OK;
	}
};
