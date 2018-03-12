#pragma once
#include "common.h"
#include <MMX/RsaSignature.h>
#include <vector>

namespace group_sig
{
	struct member_info
	{
		string id;
		ZZ y;
		ZZ z;
	};

	class GM
	{
	public:
		explicit GM(long lambda)
			: lambda(lambda)
		{
		}

		void init();
		public_para getPublicPara() const;
		bool verify(string id, ZZ y, ZZ z, ZZ c, ZZ s);
		string open(ZZ gg, ZZ zz);
	private:
		RSA::RsaSignature rsa_; // (n b)
		ZZ G;
		ZZ g; // 循环群G，g为生成元，n为G的阶
		ZZ a;
		long lambda; //群成员私钥长度
		ZZ epsilon;
		vector<member_info> info;
	};
}
