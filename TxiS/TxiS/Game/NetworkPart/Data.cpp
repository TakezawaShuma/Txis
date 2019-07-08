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
			ret = "�֐��̌Ăяo���Ɋ����݂�����܂����B"; break;
		case 10013:
			ret = "�A�N�Z�X�͋��ۂ���܂����B"; break;
		case 10014:
			ret = "�A�h���X������������܂���B"; break;
		case 10022:
			ret = "�����Ȉ����ł��B"; break;
		case 10024:
			ret = "�J���Ă���t�@�C�����������܂��B"; break;
		case 10035:
			ret = "���\�[�X���ꎞ�I�ɗ��p�ł��Ȃ��Ȃ��Ă��܂��B"; break;
		case 10036:
			ret = "����͌��ݎ��s���ł��B"; break;
		case 10037:
			ret = "����͊��Ɏ��s���ł��B"; break;
		case 10038:
			ret = "��\�P�b�g�ɑ΂��ă\�P�b�g��������݂܂����B"; break;
		case 10039:
			ret = "���M��̃A�h���X���K�v�ł��B"; break;
		case 10040:
			ret = "���b�Z�[�W���������܂��B"; break;
		case 10041:
			ret = "�v���g�R���̎�ނ��\�P�b�g�ɑ΂��Đ���������܂���B"; break;
		case 10042:
			ret = "�v���g�R���̃I�v�V����������������܂���B"; break;
		case 10043:
			ret = "�v���g�R�����T�|�[�g����Ă��܂���B"; break;
		case 10044:
			ret = "�T�|�[�g����Ă��Ȃ��\�P�b�g�̎�ނł��B"; break;
		case 10045:
			ret = "���삪�\�P�b�g��ŃT�|�[�g����Ă��܂���B"; break;
		case 10046:
			ret = "�v���g�R�� �t�@�~�����T�|�[�g����Ă��܂���B"; break;
		case 10047:
			ret = "�v���g�R�� �t�@�~���̓A�h���X �t�@�~�����T�|�[�g���Ă��܂���B"; break;
		case 10048:
			ret = "�A�h���X�͊��Ɏg�p���ł��B"; break;
		case 10049:
			ret = "�v�����ꂽ�A�h���X�����蓖�Ă��܂���B"; break;
		case 10050:
			ret = "�l�b�g���[�N���_�E�����Ă��܂��B"; break;
		case 10051:
			ret = "ICMP �l�b�g���[�N�ɓ��B�ł��܂���B"; break;
		case 10052:
			ret = "�l�b�g���[�N�����Z�b�g���ꂽ���ߐؒf����܂����B"; break;
		case 10053:
			ret = "�\�t�g�E�F�A�ɂ���Đڑ������~����܂����B"; break;
		case 10054:
			ret = "�s�A�ɂ���Đڑ������Z�b�g����܂����B"; break;
		case 10055:
			ret = "�o�b�t�@�̈悪�T�|�[�g����Ă��܂���B"; break;
		case 10056:
			ret = "�\�P�b�g�͊��ɐڑ�����Ă��܂��B"; break;
		case 10057:
			ret = "�\�P�b�g���ڑ�����Ă��܂���B"; break;
		case 10058:
			ret = "�\�P�b�g�̃V���b�g�_�E����ɑ��M�ł��܂���B"; break;
		case 10060:
			ret = "�ڑ����^�C���A�E�g�ɂȂ�܂����B"; break;
		case 10061:
			ret = "�ڑ������ۂ���܂����B"; break;
		case 10064:
			ret = "�z�X�g���_�E�����Ă��܂��B"; break;
		case 10065:
			ret = "�z�X�g�ɓ��B���邽�߂̃��[�g������܂���B"; break;
		case 10067:
			ret = "�v���Z�X���������܂��B"; break;

		default:
			break;
		}
		return ret;
	}
}