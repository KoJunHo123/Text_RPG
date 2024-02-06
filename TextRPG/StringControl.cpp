#include "string.h"

int CountString(const wchar_t _str[])
{
	int count = 0;
	while ('\0' != _str[count])
	{
		++count;
	}

	return count;
}

void CopyString(wchar_t _body[], const wchar_t _copy[])
{
	int count = CountString(_copy);
	for (int i = 0; i < CountString(_copy); ++i)
	{
		_body[i] = _copy[i];
	}

}
