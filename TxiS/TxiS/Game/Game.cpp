//
// Game.cpp
//

// ���� ---------------------
#include <CommonStates.h>
// --------------------------
// ���L ---------------------
#include "../pch.h"
#include "SimpleMath.h"
#include "../Debug.h"
// --------------------------
// �`�� ---------------------
#include "SpriteBatch.h"
#include "WICTextureLoader.h"
#include "DDSTextureLoader.h"
#include "DrawManager.h"
// --------------------------
// �Q�[�� -------------------
#include "Game.h"
#include "InputManager.h"
#include "Effects\EffectManager.h"
// --------------------------

extern void ExitGame();

using Microsoft::WRL::ComPtr;

Game::Game() :m_deviceResources(), m_gameScene(nullptr)
{
    m_deviceResources = std::make_unique<DX::DeviceResources>();
    m_deviceResources->RegisterDeviceNotify(this);
}

/// <summary>
/// ����������
///	Direct3D�ɕK�v�ȃ��\�[�X�̊m��
/// </summary>
/// <param name="window"></param>
/// <param name="width"></param>
/// <param name="height"></param>
void Game::Initialize(HWND window, int width, int height)
{

    m_deviceResources->CreateDeviceResources();
    CreateDeviceDependentResources();

	// �E�B���h�E�֌W
    m_deviceResources->SetWindow(window, width, height);
    m_deviceResources->CreateWindowSizeDependentResources();
    CreateWindowSizeDependentResources();

	// DrawManager������
	System::DrawManager::GetInstance().Initialize(m_deviceResources->GetD3DDevice(), m_deviceResources->GetD3DDeviceContext());

	// Debug�̏�����
	Debug::GetInstance().Initialize(m_deviceResources->GetD3DDevice(), m_deviceResources->GetD3DDeviceContext());

	// �Q�[���V�[���̍쐬��������
	m_gameScene = std::make_unique<GameScene>(m_effectManager.get());
	m_gameScene->Start();


    // TODO: Change the timer settings if you want something other than the default variable timestep mode.
    // e.g. for 60 FPS fixed timestep update logic, call:
    /*
    m_timer.SetFixedTimeStep(true);
    m_timer.SetTargetElapsedSeconds(1.0 / 60);
    */
}

/// <summary>
/// �I������
/// </summary>
void Game::END()
{
}

#pragma region Frame Update
/// <summary>
/// �Q�[�����[�v�̎��s
/// </summary>
void Game::Tick()
{
    m_timer.Tick([&]()
    {
        Update(m_timer);
    });

    Render();
}

// Updates the world.
void Game::Update(DX::StepTimer const& timer)
{
    float elapsedTime = float(timer.GetElapsedSeconds());

    // TODO: Add your game logic here.
    elapsedTime;

	// ���̓N���X�̍X�V
	System::InputManager::GetInstance().Update();

	m_gameScene->Update();
}
#pragma endregion

#pragma region Frame Render
// Draws the scene.
void Game::Render()
{
    // Don't try to render anything before the first Update.
    if (m_timer.GetFrameCount() == 0)
    {
        return;
    }

    Clear();

    m_deviceResources->PIXBeginEvent(L"Render");
    auto context = m_deviceResources->GetD3DDeviceContext();

    // TODO: Add your rendering code here.
    context;

	// �Q�[���̕`��
	m_gameScene->DrawBegin();
	m_gameScene->Draw();
	m_gameScene->DrawEnd();



    m_deviceResources->PIXEndEvent();

    // Show the new frame.
    m_deviceResources->Present();
}

// Helper method to clear the back buffers.
void Game::Clear()
{
    m_deviceResources->PIXBeginEvent(L"Clear");

    // Clear the views.
    auto context = m_deviceResources->GetD3DDeviceContext();
    auto renderTarget = m_deviceResources->GetRenderTargetView();
    auto depthStencil = m_deviceResources->GetDepthStencilView();

    context->ClearRenderTargetView(renderTarget, DirectX::Colors::CornflowerBlue);
    context->ClearDepthStencilView(depthStencil, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
    context->OMSetRenderTargets(1, &renderTarget, depthStencil);

    // �r���[�|�[�g�̐ݒ�
    auto viewport = m_deviceResources->GetScreenViewport();
    context->RSSetViewports(1, &viewport);

    m_deviceResources->PIXEndEvent();
}
#pragma endregion

#pragma region Message Handlers
// Message handlers
/// <summary>
/// �Q�[�����A�N�e�B�u�E�B���h�E�ɂȂ����
/// </summary>
void Game::OnActivated()
{
    // TODO: Game is becoming active window.

}

/// <summary>
/// �Q�[�����o�b�N�O���E���h�ɂȂ����
/// ��A�N�e�B�u����
/// </summary>
void Game::OnDeactivated()
{
    // TODO: Game is becoming background window.
}

/// <summary>
/// �Q�[������~���Ă��邩�ŏ�������Ă���
/// </summary>
void Game::OnSuspending()
{
    // TODO: Game is being power-suspended (or minimized).
}

/// <summary>
/// �Q�[�����ĊJ����Ă���
/// </summary>
void Game::OnResuming()
{
    m_timer.ResetElapsedTime();

    // TODO: Game is being power-resumed (or returning from minimize).
}


/// <summary>
/// �E�B���h�E�̈ړ�
/// </summary>
void Game::OnWindowMoved()
{
    auto r = m_deviceResources->GetOutputSize();
    m_deviceResources->WindowSizeChanged(r.right, r.bottom);
}

/// <summary>
/// �E�B���h�E�T�C�Y�̕ύX( �� , �c )
/// </summary>
/// <param name="width"></param>
/// <param name="height"></param>
void Game::OnWindowSizeChanged(int width, int height)
{
    if (!m_deviceResources->WindowSizeChanged(width, height))
        return;

    CreateWindowSizeDependentResources();

    // TODO: Game window is being resized.
}

// Properties
// �v���p�e�B�ݒ�

/// <summary>
/// �Q�[���E�B���h�E�̃f�t�H���g�T�C�Y�̐ݒ�
/// </summary>
/// <param name="width"></param>
/// <param name="height"></param>
void Game::GetDefaultSize(int& width, int& height) const
{
    // TODO: Change to desired default window size (note minimum size is 320x200).
    width = 800;
    height = 800;
}
#pragma endregion

#pragma region Direct3D Resources
// �f�o�C�X�Ɉˑ����郊�\�[�X

/// <summary>
/// �f�o�C�X�ˑ��̃I�u�W�F�N�g�̏�����
/// </summary>
void Game::CreateDeviceDependentResources()
{
    auto device = m_deviceResources->GetD3DDevice();
	auto context = m_deviceResources->GetD3DDeviceContext();

    // TODO: Initialize device dependent objects here (independent of window size).
    device;

	// �X�v���C�g�o�b�`�̍쐬
	m_SpriteBatch = std::make_unique<DirectX::SpriteBatch>(context);


	// �J�����A�r���[�v���W�F�N�V�����̍쐬
	RECT outputSize = m_deviceResources->GetOutputSize();
	UINT backBufferWidth = std::max<UINT>(outputSize.right - outputSize.left, 1);
	UINT backBufferHeight = std::max<UINT>(outputSize.bottom - outputSize.top, 1);
	DirectX::SimpleMath::Vector3 camera = DirectX::SimpleMath::Vector3(0, 0, -5);
	DirectX::SimpleMath::Matrix view = DirectX::SimpleMath::Matrix::CreateLookAt(camera, DirectX::SimpleMath::Vector3::Zero, DirectX::SimpleMath::Vector3::UnitY);
	DirectX::SimpleMath::Matrix proj = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(DirectX::XM_PI / 4.f,
		float(backBufferWidth) / float(backBufferHeight), 0.1f, 1000.f);

	// �G�t�F�N�g�̍쐬
	m_effectManager = std::make_unique<System::EffectManager>();
	m_effectManager->Create(m_deviceResources.get(), 1);
	m_effectManager->Initialize(0, DirectX::SimpleMath::Vector3(0, 0, 0), DirectX::SimpleMath::Vector3(0, 0, 0));
	m_effectManager->SetRenderState(camera, view, proj);
}

// Allocate all memory resources that change on a window SizeChanged event.

// �E�B���h�E�̃T�C�Y�ύX�C�x���g�ŕω�����S�Ẵ��������\�[�X�����蓖�Ă�

/// <summary>
/// �E�B���h�E�T�C�Y�ˑ��̃I�u�W�F�N�g������������
/// </summary>
void Game::CreateWindowSizeDependentResources()
{
    // TODO: Initialize windows-size dependent objects here.
}

/// <summary>
/// Direct3D�̃��\�[�X�̃N���[���A�b�v
/// </summary>
void Game::OnDeviceLost()
{
	// TODO: Add Direct3D resource cleanup here.
	if (m_effectManager != nullptr) {
		m_effectManager->Lost();
	}
}

/// <summary>
/// �f�o�C�X�̕���
/// </summary>
void Game::OnDeviceRestored()
{
    CreateDeviceDependentResources();

    CreateWindowSizeDependentResources();
}
#pragma endregion


