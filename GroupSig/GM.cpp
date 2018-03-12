#include "GM.h"
#include <MMX/RsaSignature.h>
using namespace group_sig;

/**
 * \brief 群管理员GM获取下列值
 * 
 * 			RSA公钥对 (n, b)
 * 			
 *			循环群G，g为生成元，n为G的阶
 *			
 *			系统安全性参数a,λ(群成员私钥长度),ε
 *			
 *			公开参数 (n, e, G, g, a, λ, ε)
 *			
 *			群管理员保存RSA私钥对(n, d)???
 */
void GM::init()
{
	rsa_.generateKeyPair();

	// TODO network startserver
}

public_para GM::getPublicPara() const
{
	return {
		rsa_.getPK()->n,
		rsa_.getPK()->b,
		G, g, a, lambda, epsilon
	};
}

bool GM::verify(string id, ZZ y, ZZ z, ZZ c, ZZ s)
{
	// TODO verify y和z的合法性

	// GM保存(y, z)用于日后打开群签名
	info.push_back({id, y, z});
	//  GM生成Alice的成员证书 v = (y + 1) ^ d (mod n)
	ZZ v = PowerMod(y + 1, rsa_.getSK()->a, rsa_.getPK()->n);

	// TODO network 发送 成员证书 v 给 Alice
}

string GM::open(ZZ gg, ZZ zz)
{
	for (auto i : info)
	{
		if (PowerMod(gg, i.y, rsa_.getPK()->n) == zz)
			return i.id;
	}
	string s;
	return "";
}
