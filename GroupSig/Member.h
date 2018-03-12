#pragma once
#include "common.h"

namespace group_sig
{
	class member
	{
	public:
		member(public_para para);
		ZZ verify();
		string sig(const ZZ& x) const;
		string sig(const string& x) const;
		static bool ver(const ZZ& x, const ZZ& y);

	private:
		ZZ x;
		ZZ y;
		ZZ z;
		ZZ v;
		public_para para;
	};
}
