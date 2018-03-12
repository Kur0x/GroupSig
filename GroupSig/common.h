#pragma once
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;

namespace group_sig
{
	/**
	 * \brief �������� (n, b, G, g, a, ��, ��)
	 */
	struct public_para
	{
		ZZ n;
		ZZ b;
		ZZ G;
		ZZ g;
		ZZ a; // ϵͳ��ȫ�Բ���a
		long lambda;
		ZZ epsilon;
	};
}
