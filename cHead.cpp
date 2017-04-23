#include "stdafx.h"
#include "cHead.h"


cHead::cHead()
{
}


cHead::~cHead()
{
}

void cHead::Setup()
{
	//내가한거
	{
		//	cCubeNode::Setup();

		//	for (int i = 0; i < m_vecVertex.size(); i++)
		//	{
		//		//m_vecVertex[i].p.y = 2.0f;
		//		m_vecVertex[i].p = m_vecVertex[i].p + D3DXVECTOR3(0, 11, 0);
		//		//m_vecVertex[i].p.x = 2.20f;
		//		//m_vecVertex[i].p.z = 2.0f;
		//		//m_vecVertex[i].p.x -= 3.0f;

		//		D3DXVec3Scale(&m_vecVertex[i].p, &m_vecVertex[i].p, 0.25f);
		//		//D3DXVec3Scale(&m_vecVertex[i].p, &m_vecVertex[i].p, 0.25f);
		//		//m_vecVertex[i].p.x = 2.0f;
		//		//m_vecVertex[i].p.z = 2.0f;
		//	}
	}
	//선생님이 한거
	{
		cCubeNode::Setup();
		m_eCharater = M_HEAD;

		D3DXMATRIXA16 matS, matT, mat;
		D3DXMatrixScaling(&matS, 0.4f, 0.4f, 0.4f);
		D3DXMatrixTranslation(&matT, 0.0f, 0.0f, 0.0f);
		mat = matS*matT;
		for (size_t i = 0; i < m_vecVertex.size(); i++)
		{
			D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &mat);
		}
		// << body를 기준으로 했으니 head의 포지션은 조금 올려주자
		m_vLocalPos.y = 0.5f;
	}
}

void cHead::Update()
{
	
	if (*GetBreakTime() == true)
	{
		m_isrest = false;
		SetRotDeltaX(GetRotDeltaX() + 0.1f);
		D3DXMatrixRotationX(&m_matR, GetRotDeltaX());
		
	}
	//else
	//{
	//	m_isrest = true;
	//	if (GetRotDeltaX() < 1.0f && m_isrest == true)
	//	{
	//		SetRotDeltaX(GetRotDeltaX() + 0.01f);
	//		
	//	}
	//	else
	//	{
	//		m_isrest = false;
	//		SetRotDeltaX(GetRotDeltaX() - 0.01f);
	//		if (GetRotDeltaX() < -1.0f)
	//			m_isrest = true;
	//	}
	//	D3DXMatrixRotationY(&m_matR, GetRotDeltaX());
	//	
	//}
	
	cCubeNode::Update();
}

