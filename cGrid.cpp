#include "stdafx.h"
#include "cGrid.h"


cGrid::cGrid()
{
	/* 선생님코드

	ST_PC_VERTEX v1;
	v1.c = D3DCOLOR_XRGB(255, 0, 0);
	v1.p = D3DXVECTOR3(0, 2, 0); m_vecVertex.push_back(v1);
	v1.p = D3DXVECTOR3(0, -2, 0); m_vecVertex.push_back(v1);

	선생님끝
	*/
	//선그리고  센터 


	/////////////////////////////

	ST_PC_VERTEX v;
	v.c = D3DCOLOR_XRGB(0, 0, 0);

	int nNumTile = 10;
	float fInterval = 1.0f;
	float fMax = nNumTile * fInterval;
	float fMin = -nNumTile * fInterval;

	for (int i = 1; i <= nNumTile; i++)
	{
		v.p = D3DXVECTOR3(fMin, 0, i * fInterval); m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(fMax, 0, i * fInterval); m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(fMin, 0, -i * fInterval); m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(fMax, 0, -i * fInterval); m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(i * fInterval, 0, fMin); m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(i * fInterval, 0, fMax); m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(-i * fInterval, 0, fMin); m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(-i * fInterval, 0, fMax); m_vecVertex.push_back(v);
	}

	v.p = D3DXVECTOR3(0, 0, fMin); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0, 0, fMax); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(fMin, 0, 0); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(fMax, 0, 0); m_vecVertex.push_back(v);

	ST_PC_VERTEX v1;
	v1.c = D3DCOLOR_XRGB(255, 0, 0);
	v1.p = D3DXVECTOR3(5, 0, 0); m_vecVertex.push_back(v1);
	v1.p = D3DXVECTOR3(-5, 0, 0); m_vecVertex.push_back(v1);
	// X  Y   Z

	v1.c = D3DCOLOR_XRGB(0, 255, 0);
	v1.p = D3DXVECTOR3(0, 5, 0); m_vecVertex.push_back(v1);
	v1.p = D3DXVECTOR3(0, -5, 0); m_vecVertex.push_back(v1);

	v1.c = D3DCOLOR_XRGB(0, 0, 255);
	v1.p = D3DXVECTOR3(0, 0, 5); m_vecVertex.push_back(v1);
	v1.p = D3DXVECTOR3(0, 0, -5); m_vecVertex.push_back(v1);

}


cGrid::~cGrid()
{
}

void cGrid::Setup()
{
}

void cGrid::Render()//선생님
{
	D3DXMATRIXA16 mat;
	D3DXMatrixIdentity(&mat);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &mat);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);

	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, m_vecVertex.size() / 2, &m_vecVertex[0], sizeof(ST_PC_VERTEX));

}
