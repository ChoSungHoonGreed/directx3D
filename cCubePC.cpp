#include "stdafx.h"
#include "cCubePC.h"


cCubePC::cCubePC()
	:m_vDirection(0, 0, 1)
	, m_vPosition(0, 1, 0)
	, m_fRotY(0.0f)

{
	D3DXMatrixIdentity(&m_matWorld);
}


cCubePC::~cCubePC()
{
}

void cCubePC::Setup()
{



	/* 선생님코드 시작
	ST_PC_VERTEX v;
	v.c = D3DCOLOR_XRGB(0, 255, 255);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); temp.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f); temp.push_back(v);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f);  temp.push_back(v);

	끝
	*/
	//ST_PC_VERTEX v;
	//std::vector<ST_PC_VERTEX> temp;

	////v.c = D3DCOLOR_XRGB(0, 255, 255);
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

}

void cCubePC::Update() // 선생님코드 업뎃에는 없음!
{

	//Move();
	//D3DXMATRIXA16  matX,matY;

	//D3DXMatrixRotationY(&matY, m_fRotY);
	//D3DXMatrixRotationX(&matX, m_fRotY);
	//
	////matR = matX * matY;


	//D3DXMATRIXA16 matS, matR, matT;
	//
	//
	//D3DXMatrixIdentity(&matS);
	//D3DXMatrixIdentity(&matR);
	//D3DXMatrixIdentity(&matT);
	//
	//D3DXMatrixTranslation(&matT,m_vPosition.x, m_vPosition.y, m_vPosition.z);
	//m_vDirection = D3DXVECTOR3(0, 0, 1);
	//D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matY);

	//m_matWorld = matR * matY *matT;//*matT;



	/*m_vDirection.x = 0;
	m_vDirection.y = 0;
	m_vDirection.z = 1;
	*/

	/*	if (m_vDirection.z < 2.0f)
	m_vDirection.z = 2.0f;*/




}
void cCubePC::Render() //선생님 
{
	//	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);//
	//	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);//
	//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex.size() / 3, &m_vecVertex[0], sizeof(ST_PC_VERTEX));//
}

void cCubePC::Move()
{
	/*if (GetKeyState('A') & 0x8000)
	{
	m_fRotY -= 0.1f;
	}
	else if (GetKeyState('D') & 0x8000)
	{
	m_fRotY += 0.1f;
	}
	if (GetKeyState('W') & 0x8000)
	{

	m_vPosition = m_vPosition + (m_vDirection * 0.1f);
	}
	else if (GetKeyState('S') & 0x8000)
	{
	m_vPosition = m_vPosition - (m_vDirection * 0.1f);
	}*/
}

D3DXVECTOR3 & cCubePC::GetPosition() //선생님
{

	return m_vPosition;
	// TODO: 여기에 반환 구문을 삽입합니다.
}
