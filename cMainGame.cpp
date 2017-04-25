#include "stdafx.h"
#include "cMainGame.h"
#include "cDeviceManager.h"		/// << : 

// >> :
#include "cCubePC.h"
#include "cCamera.h"
#include "cGrid.h"
#include "cCubeMan.h"
// << :

cMainGame::cMainGame()
	: //m_pCubePC(NULL)
	m_pCubeMan(NULL)
	, m_pCamera(NULL)
	, m_pGrid(NULL)
	, m_pTexture(NULL)
{
}


cMainGame::~cMainGame()
{
	//SAFE_DELETE(m_pCubePC); 
	SAFE_DELETE(m_pCubeMan);
	SAFE_DELETE(m_pCamera);
	SAFE_DELETE(m_pGrid);
	SAFE_RELEASE(m_pTexture);
	g_pDeviceManager->Destroy();
}

// >> : 
void cMainGame::Setup()
{
	{
		D3DXCreateTextureFromFile(g_pD3DDevice, "srccodetex.png", &m_pTexture);
		ST_PT_VERTEX v;
		v.p = D3DXVECTOR3(0, 0, 0);
		v.t = D3DXVECTOR2(0, 1.0f);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(0, 1, 0);
		v.t = D3DXVECTOR2(0, 0.5f);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(1, 0, 0);
		v.t = D3DXVECTOR2(1, 1);
		m_vecVertex.push_back(v);
	}

	m_pCubeMan = new cCubeMan;
	m_pCubeMan->Setup();

	m_pCamera = new cCamera;
	m_pCamera->Setup(&m_pCubeMan->GetPosition());

	m_pGrid = new cGrid;
	m_pGrid->Setup();

	Set_Light();
	Set_Light100();
	Set_Light200();
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	//g_pD3DDevice->SetRenderState(, true);
}

void cMainGame::Update()
{
	if (m_pCubeMan)	m_pCubeMan->Update();

	if (m_pCamera) m_pCamera->Update();

}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(47, 121, 112),
		1.0f, 0);

	g_pD3DDevice->BeginScene();


	if (m_pGrid) m_pGrid->Render();
	if (m_pCubeMan) m_pCubeMan->Render();

	{
		//
		D3DXMATRIXA16 matWorld;
		D3DXMatrixIdentity(&matWorld);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		g_pD3DDevice->SetTexture(0, m_pTexture);
		g_pD3DDevice->SetFVF(ST_PT_VERTEX::FVF);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
			m_vecVertex.size() / 3,
			&m_vecVertex[0],
			sizeof(ST_PT_VERTEX));

		g_pD3DDevice->SetTexture(0, NULL);
	}
	g_pD3DDevice->EndScene();

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}
// << : 

void cMainGame::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
	{
		m_pCamera->WndProc(hwnd, message, wParam, lParam);
	}
}

void cMainGame::Set_Light()
{
	D3DLIGHT9 stLight;
	
		ZeroMemory(&stLight, sizeof(D3DLIGHT9));
		stLight.Type = D3DLIGHT_DIRECTIONAL;
		
		stLight.Ambient = D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f);
		stLight.Diffuse = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);
		stLight.Specular = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
		D3DXVECTOR3 vDir(1.0f, -1.0f, 1.0f);
		D3DXVec3Normalize(&vDir, &vDir);
		stLight.Direction = vDir;
		//stLight.
		g_pD3DDevice->SetLight(0, &stLight);
	

	g_pD3DDevice->LightEnable(0, true);
}

void cMainGame::Set_Light100()
{
	D3DLIGHT9 stLight;
	ZeroMemory(&stLight, sizeof(D3DLIGHT9));
	stLight.Type = D3DLIGHT_POINT;
	stLight.Ambient = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	stLight.Diffuse = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	stLight.Specular = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	//stLight.Direction = D3DXVECTOR3(0.0, 0.0, 1.0f);
	stLight.Position = D3DXVECTOR3(0.0f, 2.0f, 0.0f);
	stLight.Range = 5.0f;
	
	g_pD3DDevice->SetLight(1, &stLight);
	g_pD3DDevice->LightEnable(1, true);
}

void cMainGame::Set_Light200()
{
	D3DLIGHT9 stLight;
	ZeroMemory(&stLight, sizeof(D3DLIGHT9)); // ÈÄ·¹½¬
	stLight.Type = D3DLIGHT_SPOT;
	stLight.Position = D3DXVECTOR3(0.0f, 1.0f, 10.0f);
	stLight.Ambient = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	stLight.Diffuse = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
	stLight.Direction = D3DXVECTOR3(0.0f, 1.0f, 2.0f);
	stLight.Theta = D3DX_PI / 0.6f;
	stLight.Phi = D3DX_PI / 0.8f;
	stLight.Range = 1.0f;
	D3DXVECTOR3 vDir;
	D3DXVec3Normalize(&vDir, &vDir);
	g_pD3DDevice->SetLight(2, &stLight);
	g_pD3DDevice->LightEnable(2, true);

	
}