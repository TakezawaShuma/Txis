#include <iostream>
#include "../../pch.h"

namespace Data
{
	std::string ErrorState(int errorNumber)
	{
		std::string ret;

		switch (errorNumber)
		{
		case 10004:
			ret = "関数の呼び出しに割込みがありました。"; break;
		case 10013:
			ret = "アクセスは拒否されました。"; break;
		case 10014:
			ret = "アドレスが正しくありません。"; break;
		case 10022:
			ret = "無効な引数です。"; break;
		case 10024:
			ret = "開いているファイルが多すぎます。"; break;
		case 10035:
			ret = "リソースが一時的に利用できなくなっています。"; break;
		case 10036:
			ret = "操作は現在実行中です。"; break;
		case 10037:
			ret = "操作は既に実行中です。"; break;
		case 10038:
			ret = "非ソケットに対してソケット操作を試みました。"; break;
		case 10039:
			ret = "送信先のアドレスが必要です。"; break;
		case 10040:
			ret = "メッセージが長すぎます。"; break;
		case 10041:
			ret = "プロトコルの種類がソケットに対して正しくありません。"; break;
		case 10042:
			ret = "プロトコルのオプションが正しくありません。"; break;
		case 10043:
			ret = "プロトコルがサポートされていません。"; break;
		case 10044:
			ret = "サポートされていないソケットの種類です。"; break;
		case 10045:
			ret = "操作がソケット上でサポートされていません。"; break;
		case 10046:
			ret = "プロトコル ファミリがサポートされていません。"; break;
		case 10047:
			ret = "プロトコル ファミリはアドレス ファミリをサポートしていません。"; break;
		case 10048:
			ret = "アドレスは既に使用中です。"; break;
		case 10049:
			ret = "要求されたアドレスを割り当てられません。"; break;
		case 10050:
			ret = "ネットワークがダウンしています。"; break;
		case 10051:
			ret = "ICMP ネットワークに到達できません。"; break;
		case 10052:
			ret = "ネットワークがリセットされたため切断されました。"; break;
		case 10053:
			ret = "ソフトウェアによって接続が中止されました。"; break;
		case 10054:
			ret = "ピアによって接続がリセットされました。"; break;
		case 10055:
			ret = "バッファ領域がサポートされていません。"; break;
		case 10056:
			ret = "ソケットは既に接続されています。"; break;
		case 10057:
			ret = "ソケットが接続されていません。"; break;
		case 10058:
			ret = "ソケットのシャットダウン後に送信できません。"; break;
		case 10060:
			ret = "接続がタイムアウトになりました。"; break;
		case 10061:
			ret = "接続が拒否されました。"; break;
		case 10064:
			ret = "ホストがダウンしています。"; break;
		case 10065:
			ret = "ホストに到達するためのルートがありません。"; break;
		case 10067:
			ret = "プロセスが多すぎます。"; break;

		default:
			break;
		}
		return ret;
	}
}