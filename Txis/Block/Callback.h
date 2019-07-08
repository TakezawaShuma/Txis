#pragma once

#include "Game\NetworkPart\Data.h"

/// <summary>
/// ��M�p�R�[���o�b�N�N���X
/// </summary>
class IReception
{
public:
	virtual int Reception(char* _data) = 0;
};

/// <summary>
/// �V�[���؂�ւ��p�R�[���o�b�N�N���X
/// </summary>
class ISceneChange
{
public:
	virtual void ChangeScene(Data::Scenes::SCENETYPE _scene) = 0;
};