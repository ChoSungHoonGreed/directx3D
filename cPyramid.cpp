#include "stdafx.h"
#include "cPyramid.h"


cPyramid::cPyramid()
{
}


cPyramid::~cPyramid()
{
}

void cPyramid::Setup()
{
	ST_PC_VERTEX v;

	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(-0.1f, 2.0f, -0.1f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, 2.0f, 0.1f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 2.0f, 0.1f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-0.1f, 2.0f, -0.1f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 2.0f, 0.1f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 2.0f, -0.1f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, 2.0f, -0.1f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 2.0f, -0.1f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 2.0f, 0.1f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, 2.0f, 0.1f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, 2.0f, 0.1f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, 2.0f, -0.1f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 2.0f, -0.1f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 2.0f, 0.1f); m_vecVertex.push_back(v);

	//x��
	v.c = D3DCOLOR_XRGB(0, 0, 255);
	v.p = D3DXVECTOR3(2.0f, -0.1f, -0.1f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, 0.1f, -0.1f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, 0.1f, 0.1f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(2.0f, -0.1f, -0.1f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, 0.1f, 0.1f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, -0.1f, 0.1f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, 0.1f, -0.1f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, -0.1f, -0.1f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, -0.1f, 0.1f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, 0.1f, 0.1f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, 0.1f, 0.1f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, 0.1f, -0.1f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, -0.1f, -0.1f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(2.0f, -0.1f, 0.1f); m_vecVertex.push_back(v);

	//z��
	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = D3DXVECTOR3(-0.1f, -0.1f, 2.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 0.1f, 2.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, 0.1f, 2.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-0.1f, -0.1f, 2.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, -0.1f, 2.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 0.1f, 2.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, -0.1f, 2.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, 0.1f, 2.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 0.1f, 2.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, -0.1f, 2.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, 0.1f, 2.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, 0.1f, 2.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.1f, -0.1f, 2.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-0.1f, -0.1f, 2.0f); m_vecVertex.push_back(v);
}


void cPyramid::Render()
{
	D3DXMATRIXA16 mat;
	D3DXMatrixIdentity(&mat);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &mat);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex.size() / 3, &m_vecVertex[0], sizeof(ST_PC_VERTEX));
}
