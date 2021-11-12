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
	/// <returns>S_OK or E_POINTER (if pRetVal is null)</returns>
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

	/// <summary>
	/// Helper function to implement get_PropertyName(VARIANT_BOOL* pRetVal) that converts backing bool to VARIANT_BOOL.
	/// </summary>
	/// <param name="boolValue">bool value to put to *pRetVal</param>
	/// <param name="pRetVal">Return value for the getter</param>
	/// <returns>S_OK or E_POINTER (if pRetVal is null)</returns>
	static HRESULT GetBoolToVariantBool(bool boolValue, VARIANT_BOOL* pRetVal) noexcept
	{
		if (NULL == pRetVal)
			return E_POINTER;

		*pRetVal = BoolToVariantBool(boolValue);
		return S_OK;
	}

	/// <summary>
	/// Helper function to implement put_PropertyName(VARIANT_BOOL newValue) that converts VARIANT_BOOL to the backing bool.
	/// </summary>
	/// <param name="newValue">Property value to set</param>
	/// <param name="bRefValueToSet">Reference to bool to set</param>
	/// <returns>S_OK</returns>
	static HRESULT PutVariantBoolToBool(const VARIANT_BOOL newValue, bool& bRefValueToSet) noexcept
	{
		bRefValueToSet = VariantBoolToBool(newValue);
		return S_OK;
	}

	/// <summary>
	/// Helper function to implement get_PropertyName(BSTR* pRetVal) with backing CComBSTR.
	/// </summary>
	static HRESULT GetBSTR(const CComBSTR& value, BSTR* pRetVal) noexcept
	{
		if (NULL == pRetVal)
			return E_POINTER;

		*pRetVal = value.Copy();
		return S_OK;
	}

	/// <summary>
	/// Helper function to implement put_PropertyName(BSTR newValue) with backing CComBSTR.
	/// </summary>
	static HRESULT PutBSTR(const BSTR newValue, CComBSTR& refValueToSet)
	{
		refValueToSet = newValue;
		return S_OK;
	}

	/// <summary>
	/// Converts VARIANT_TRUE to true. Other values are converted to false.
	/// </summary>
	static bool VariantBoolToBool(const VARIANT_BOOL vbValue)
	{
		return (VARIANT_TRUE == vbValue);
	}

	/// <summary>
	/// Converts bool to VARIANT_FALSE / VARIANT_TRUE.
	/// </summary>
	static VARIANT_BOOL BoolToVariantBool(const bool booValue)
	{
		return booValue ? VARIANT_TRUE : VARIANT_FALSE;
	}
};
