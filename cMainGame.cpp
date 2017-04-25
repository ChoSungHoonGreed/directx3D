#include "stdafx.h"
#include "cMainGame.h"
#include "cDeviceManager.h"				//<<::


//>>::

#include "cGrid.h"
#include "cCamera.h"
#include "cPyramid.h"
#include "cCubeMan.h"

//<<::
cMainGame::cMainGame()
	:
	m_pCamera(NULL)
	, m_pGrid(NULL)
	, m_pPyramid(NULL)
	, m_pCubeMen(NULL)
	
{
}


cMainGame::~cMainGame()
{
	SAFE_DELETE(m_pCamera);
	SAFE_DELETE(m_pGrid);
	SAFE_DELETE(m_pPyramid);
	SAFE_DELETE(m_pCubeMen);
	
	g_pDeviceManager->Destroy();
}

void cMainGame::Setup()
{
	m_pCubeMen = new cCubeMan;
	m_pCubeMen->Setup();

	m_pCamera = new cCamera;
	m_pCamera->Setup(&m_pCubeMen->GetPosition());

	m_pGrid = new cGrid;
	m_pGrid->Setup();

	m_pPyramid = new cPyramid;
	m_pPyramid->Setup();

	//Set_Light();
	//Set_Light100();
	Set_Light200();
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);

}

void cMainGame::Update()
{

	if (m_pCamera)m_pCamera->Update();
	if (m_pCubeMen)m_pCubeMen->Update();
}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 100, 255), 1.0f, 0);
	g_pD3DDevice->BeginScene();

	if (m_pGrid) m_pGrid->Render();
	if (m_pPyramid) m_pPyramid->Render();
	if (m_pCubeMen)m_pCubeMen->Render();

	g_pD3DDevice->EndScene();
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	m_pCamera->WndProc(hWnd, message, wParam, lParam);
}


void cMainGame::Set_Light()
{
	D3DLIGHT9 stLight;
	ZeroMemory(&stLight, sizeof(D3DLIGHT9));               
	stLight.Type = D3DLIGHT_DIRECTIONAL; 
	stLight.Ambient = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	stLight.Diffuse = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	stLight.Specular = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);

	D3DXVECTOR3 vDir(1.0f, -1.0f, 1.0f);
	D3DXVec3Normalize(&vDir, &vDir);
	stLight.Direction = vDir;
	g_pD3DDevice->SetLight(0, &stLight);
	g_pD3DDevice->LightEnable(0, true);

}

void cMainGame::Set_Light100()
{
	D3DLIGHT9 stLight;
	ZeroMemory(&stLight, sizeof(D3DLIGHT9));
	stLight.Type = D3DLIGHT_POINT;
	stLight.Position = D3DXVECTOR3(0.0f, 2.0f, -2.0f);
	stLight.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	stLight.Diffuse = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);
	stLight.Specular = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	stLight.Range = 5.0f;

	g_pD3DDevice->SetLight(1, &stLight);
	g_pD3DDevice->LightEnable(1, true);


}

void cMainGame::Set_Light200()
{
	
		D3DLIGHT9 stLight;
		ZeroMemory(&stLight, sizeof(D3DLIGHT9));
		stLight.Type = D3DLIGHT_SPOT;
		stLight.Position = D3DXVECTOR3(0.0f, 1.0f, 10.0f);
		stLight.Ambient = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
		stLight.Diffuse = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
		stLight.Direction = D3DXVECTOR3(0.0f, 1.0f, 2.0f);
		stLight.Theta = D3DX_PI / 0.6f;
		stLight.Phi = D3DX_PI / 0.8f;
		stLight.Range = 5.0f;
		D3DXVECTOR3 vDir;
		D3DXVec3Normalize(&vDir, &vDir);
		g_pD3DDevice->SetLight(2, &stLight);
		g_pD3DDevice->LightEnable(2, true);


}
