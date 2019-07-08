// プリコンパイルヘッダ ---------------
#include "../../pch.h"
// ------------------------------------
#include "InputIP.h"


InputIp::InputIp()
{
}

std::string InputIp::Input(std::string _ip)
{

	DirectX::Keyboard::Keys key;

	key = System::InputManager::GetInstance().GetPressedKeys();

	switch (key)
	{
	case DirectX::Keyboard::Keys::D1:			_ip += "1";  break;
	case DirectX::Keyboard::Keys::D2:			_ip += "2";  break;
	case DirectX::Keyboard::Keys::D3:			_ip += "3";  break;
	case DirectX::Keyboard::Keys::D4:			_ip += "4";  break;
	case DirectX::Keyboard::Keys::D5:			_ip += "5";  break;
	case DirectX::Keyboard::Keys::D6:			_ip += "6";  break;
	case DirectX::Keyboard::Keys::D7:			_ip += "7";  break;
	case DirectX::Keyboard::Keys::D8:			_ip += "8";  break;
	case DirectX::Keyboard::Keys::D9:			_ip += "9";  break;
	case DirectX::Keyboard::Keys::D0:			_ip += "0";  break;
	case DirectX::Keyboard::Keys::OemPeriod:	_ip += ".";  break;
	case DirectX::Keyboard::Keys::OemComma:		_ip += ",";  break;
	case DirectX::Keyboard::Keys::A:			_ip += "A";  break;
	case DirectX::Keyboard::Keys::B:			_ip += "B";  break;
	case DirectX::Keyboard::Keys::C:			_ip += "C";  break;
	case DirectX::Keyboard::Keys::D:			_ip += "D";  break;
	case DirectX::Keyboard::Keys::E:			_ip += "E";  break;
	case DirectX::Keyboard::Keys::F:			_ip += "F";  break;
	case DirectX::Keyboard::Keys::G:			_ip += "G";  break;
	case DirectX::Keyboard::Keys::H:			_ip += "H";  break;
	case DirectX::Keyboard::Keys::I:			_ip += "I";  break;
	case DirectX::Keyboard::Keys::J:			_ip += "J";  break;
	case DirectX::Keyboard::Keys::K:			_ip += "K";  break;
	case DirectX::Keyboard::Keys::L:			_ip += "L";  break;
	case DirectX::Keyboard::Keys::M:			_ip += "M";  break;
	case DirectX::Keyboard::Keys::N:			_ip += "N";  break;
	case DirectX::Keyboard::Keys::O:			_ip += "O";  break;
	case DirectX::Keyboard::Keys::P:			_ip += "P";  break;
	case DirectX::Keyboard::Keys::Q:			_ip += "Q";  break;
	case DirectX::Keyboard::Keys::R:			_ip += "R";  break;
	case DirectX::Keyboard::Keys::S:			_ip += "S";  break;
	case DirectX::Keyboard::Keys::T:			_ip += "T";  break;
	case DirectX::Keyboard::Keys::U:			_ip += "U";  break;
	case DirectX::Keyboard::Keys::V:			_ip += "V";  break;
	case DirectX::Keyboard::Keys::W:			_ip += "W";  break;
	case DirectX::Keyboard::Keys::X:			_ip += "X";  break;
	case DirectX::Keyboard::Keys::Y:			_ip += "Y";  break;
	case DirectX::Keyboard::Keys::Z:			_ip += "Z";  break;
	case DirectX::Keyboard::Keys::Delete:		_ip  = "" ;  break;
	case DirectX::Keyboard::Keys::Back:			_ip  = "" ;  break;


	default:
		break;
	}

	return _ip;
}

char InputIp::Input()
{

	DirectX::Keyboard::Keys keys = System::InputManager::GetInstance().GetPressedKeys();
	switch (keys)
	{
	case DirectX::Keyboard::Keys::OemComma:		return ',';  break;	// 44
	case DirectX::Keyboard::Keys::OemPeriod:	return '.';  break;	// 46
	case DirectX::Keyboard::Keys::D0:			return '0';  break;	// 48
	case DirectX::Keyboard::Keys::D1:			return '1';  break;	// 49
	case DirectX::Keyboard::Keys::D2:			return '2';  break;	// 50
	case DirectX::Keyboard::Keys::D3:			return '3';  break;	// 51
	case DirectX::Keyboard::Keys::D4:			return '4';  break;	// 52
	case DirectX::Keyboard::Keys::D5:			return '5';  break;	// 53
	case DirectX::Keyboard::Keys::D6:			return '6';  break;	// 54
	case DirectX::Keyboard::Keys::D7:			return '7';  break;	// 55
	case DirectX::Keyboard::Keys::D8:			return '8';  break;	// 56
	case DirectX::Keyboard::Keys::D9:			return '9';  break;	// 57

	case DirectX::Keyboard::Keys::A:			return 'A';  break;	// 65
	case DirectX::Keyboard::Keys::B:			return 'B';  break;	// 66
	case DirectX::Keyboard::Keys::C:			return 'C';  break;	// 67
	case DirectX::Keyboard::Keys::D:			return 'D';  break;	// 68
	case DirectX::Keyboard::Keys::E:			return 'E';  break;	// 69
	case DirectX::Keyboard::Keys::F:			return 'F';  break;	// 70
	case DirectX::Keyboard::Keys::G:			return 'G';  break;	// 71
	case DirectX::Keyboard::Keys::H:			return 'H';  break;	// 72
	case DirectX::Keyboard::Keys::I:			return 'I';  break;	// 73
	case DirectX::Keyboard::Keys::J:			return 'J';  break;	// 74
	case DirectX::Keyboard::Keys::K:			return 'K';  break;	// 75
	case DirectX::Keyboard::Keys::L:			return 'L';  break;	// 76
	case DirectX::Keyboard::Keys::M:			return 'M';  break;	// 77
	case DirectX::Keyboard::Keys::N:			return 'N';  break;	// 78
	case DirectX::Keyboard::Keys::O:			return 'O';  break;	// 79
	case DirectX::Keyboard::Keys::P:			return 'P';  break;	// 80
	case DirectX::Keyboard::Keys::Q:			return 'Q';  break;	// 81
	case DirectX::Keyboard::Keys::R:			return 'R';  break;	// 82
	case DirectX::Keyboard::Keys::S:			return 'S';  break;	// 83
	case DirectX::Keyboard::Keys::T:			return 'T';  break;	// 84
	case DirectX::Keyboard::Keys::U:			return 'U';  break;	// 85
	case DirectX::Keyboard::Keys::V:			return 'V';  break;	// 86
	case DirectX::Keyboard::Keys::W:			return 'W';  break;	// 87
	case DirectX::Keyboard::Keys::X:			return 'X';  break;	// 88
	case DirectX::Keyboard::Keys::Y:			return 'Y';  break;	// 89
	case DirectX::Keyboard::Keys::Z:			return 'Z';  break;	// 90
	case DirectX::Keyboard::Keys::Delete:		return 'd';  break;	// 
	case DirectX::Keyboard::Keys::Back:			return 'b';  break;	// 
	case DirectX::Keyboard::Keys::Enter:		return NULL; break; // NULL
	default:									return NULL; break;	// NULL 
	}
}
