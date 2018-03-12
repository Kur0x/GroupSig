#include "Member.h"
#include <MMX/Cryptography.h>
using namespace group_sig;

member::member(public_para para)
{
	this->para = para;
	RandomBits(x, para.lambda);
	y = PowerMod(para.a, x, para.n);
	z = PowerMod(para.g, y, para.n);
}


ZZ member::verify()
{
	// TODO network
	// send(y, z, SKLOG(x));

	if (v == NULL)
		throw "v error";
}

string member::sig(const ZZ& x) const
{
	ZZ r = RandomBnd(para.n - 1) + 1; //[1,p-1]
	ZZ gg = PowerMod(para.g, r, para.n);
	ZZ zz = PowerMod(gg, y, para.n);
	ZZ v1 = SKLOGLOG(x); // TODO implement
	ZZ v2 = SKROOTLOG(x); // TODO implement
	return Cryptography::numberToString(gg, false) + ' ' +
		Cryptography::numberToString(zz, false) + ' ' +
		Cryptography::numberToString(v1, false) + ' ' +
		Cryptography::numberToString(v2, false);
}

string member::sig(const string& x) const
{
	return this->sig(Cryptography::stringToNumber(x));
}

bool member::ver(const ZZ& x, const ZZ& y)
{
	// TODO implement 验证群签名只需用到 双离散对数的知识签名(skloglog)，和离散对数的e次方根的知识签名 (skrootlog) 就可以了。
}
