#include "stdafx.h"
#include "cCubePNT.h"


cCubePNT::cCubePNT()
{
}


cCubePNT::~cCubePNT()
{
}

void cCubePNT::Setup()
{
	{//내가한거
	 //ST_PNT_VERTEX v;
	 //std::vector<ST_PNT_VERTEX> temp;

	 //v.c = D3DCOLOR_XRGB(0, 255, 255);
	 //v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); temp.push_back(v);
	 //v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f); temp.push_back(v);
	 ////v.c = D3DCOLOR_XRGB(255, 255, 255);
	 //v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f);  temp.push_back(v);
	 //v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); temp.push_back(v);
	 ////v.c = D3DCOLOR_XRGB(100, 100, 100);
	 //v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); temp.push_back(v);
	 //v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);  temp.push_back(v);
	 ////v.c = D3DCOLOR_XRGB(30, 255, 30);
	 //v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f);   temp.push_back(v);
	 //v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f);  temp.push_back(v);

	 //{
	 //	m_vecVertex.push_back(temp[0]);
	 //	m_vecVertex.push_back(temp[1]);
	 //	m_vecVertex.push_back(temp[2]);
	 //	m_vecVertex.push_back(temp[0]);
	 //	m_vecVertex.push_back(temp[2]);
	 //	m_vecVertex.push_back(temp[3]);

	 //	m_vecVertex.push_back(temp[4]);
	 //	m_vecVertex.push_back(temp[6]);
	 //	m_vecVertex.push_back(temp[5]);
	 //	m_vecVertex.push_back(temp[4]);
	 //	m_vecVertex.push_back(temp[7]);
	 //	m_vecVertex.push_back(temp[6]);

	 //	m_vecVertex.push_back(temp[4]);
	 //	m_vecVertex.push_back(temp[5]);
	 //	m_vecVertex.push_back(temp[1]);
	 //	m_vecVertex.push_back(temp[4]);
	 //	m_vecVertex.push_back(temp[1]);
	 //	m_vecVertex.push_back(temp[0]);

	 //	m_vecVertex.push_back(temp[3]);
	 //	m_vecVertex.push_back(temp[2]);
	 //	m_vecVertex.push_back(temp[6]);
	 //	m_vecVertex.push_back(temp[3]);
	 //	m_vecVertex.push_back(temp[6]);
	 //	m_vecVertex.push_back(temp[7]);

	 //	m_vecVertex.push_back(temp[1]);
	 //	m_vecVertex.push_back(temp[5]);
	 //	m_vecVertex.push_back(temp[6]);
	 //	m_vecVertex.push_back(temp[1]);
	 //	m_vecVertex.push_back(temp[6]);
	 //	m_vecVertex.push_back(temp[2]);

	 //	m_vecVertex.push_back(temp[4]);
	 //	m_vecVertex.push_back(temp[0]);
	 //	m_vecVertex.push_back(temp[3]);
	 //	m_vecVertex.push_back(temp[4]);
	 //	m_vecVertex.push_back(temp[3]);
	 //	m_vecVertex.push_back(temp[7]);
	 //}
	 // : to dosometing
	}

	{
		std::vector<ST_PNT_VERTEX> vecVertex;

		vecVertex.resize(8);

		vecVertex[0].p.x = -0.5f;
		vecVertex[0].p.y = -0.5f;
		vecVertex[0].p.z = -0.5f;

		vecVertex[1].p.x = -0.5f;
		vecVertex[1].p.y = 0.5f;
		vecVertex[1].p.z = -0.5f;

		vecVertex[2].p.x = 0.5f;
		vecVertex[2].p.y = 0.5f;
		vecVertex[2].p.z = -0.5f;

		vecVertex[3].p.x = 0.5f;
		vecVertex[3].p.y = -0.5f;
		vecVertex[3].p.z = -0.5f;

		vecVertex[4].p.x = -0.5f;
		vecVertex[4].p.y = -0.5f;
		vecVertex[4].p.z = 0.5f;

		vecVertex[5].p.x = -0.5f;
		vecVertex[5].p.y = 0.5f;
		vecVertex[5].p.z = 0.5f;

		vecVertex[6].p.x = 0.5f;
		vecVertex[6].p.y = 0.5f;
		vecVertex[6].p.z = 0.5f;

		vecVertex[7].p.x = 0.5f;
		vecVertex[7].p.y = -0.5f;
		vecVertex[7].p.z = 0.5f;

		//
		std::vector<DWORD> vecIndex;

		vecIndex.push_back(0);
		vecIndex.push_back(1);
		vecIndex.push_back(2);

		vecIndex.push_back(0);
		vecIndex.push_back(2);
		vecIndex.push_back(3);

		vecIndex.push_back(4);
		vecIndex.push_back(6);
		vecIndex.push_back(5);

		vecIndex.push_back(4);
		vecIndex.push_back(7);
		vecIndex.push_back(6);

		vecIndex.push_back(4);
		vecIndex.push_back(5);
		vecIndex.push_back(1);

		vecIndex.push_back(4);
		vecIndex.push_back(1);
		vecIndex.push_back(0);

		vecIndex.push_back(3);
		vecIndex.push_back(2);
		vecIndex.push_back(6);

		vecIndex.push_back(3);
		vecIndex.push_back(6);
		vecIndex.push_back(7);

		vecIndex.push_back(1);
		vecIndex.push_back(5);
		vecIndex.push_back(6);

		vecIndex.push_back(1);
		vecIndex.push_back(6);
		vecIndex.push_back(2);

		vecIndex.push_back(0);
		vecIndex.push_back(7);
		vecIndex.push_back(4);

		vecIndex.push_back(0);
		vecIndex.push_back(3);
		vecIndex.push_back(7);

		m_vecVertex.resize(36);

		for (size_t i = 0; i < vecIndex.size(); i += 3)
		{
			m_vecVertex[i + 0] = vecVertex[vecIndex[i + 0]];
			m_vecVertex[i + 1] = vecVertex[vecIndex[i + 1]];
			m_vecVertex[i + 2] = vecVertex[vecIndex[i + 2]];
		}

		D3DXVECTOR3 u, v, n;
		for (int i = 0; i < 36; i += 3)
		{
			u = m_vecVertex[i + 1].p - m_vecVertex[i].p;
			v = m_vecVertex[i + 2].p - m_vecVertex[i].p;

			D3DXVec3Cross(&n, &u, &v);
			D3DXVec3Normalize(&n, &n);

			m_vecVertex[i + 0].n = n;
			m_vecVertex[i + 1].n = n;
			m_vecVertex[i + 2].n = n;
		}

	}
}

void cCubePNT::Update()
{
	// : to dosometing
}

void cCubePNT::Render()
{
	// : to dosometing

	//선생님 코드
	{
		g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex.size() / 3, &m_vecVertex[0], sizeof(ST_PNT_VERTEX));
	}
}
