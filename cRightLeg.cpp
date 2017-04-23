#include "stdafx.h"
#include "cRightLeg.h"


cRightLeg::cRightLeg()
{
}


cRightLeg::~cRightLeg()
{
}

void cRightLeg::Setup()
{
	//내가한거
	{
		/*	cCubeNode::Setup();
		for (int i = 0; i < m_vecVertex.size(); i++)
		{
		m_vecVertex[i].p = m_vecVertex[i].p + D3DXVECTOR3(0, 2, 0);
		D3DXVec3Scale(&m_vecVertex[i].p, &m_vecVertex[i].p, 0.27f);
		m_vecVertex[i].p.y *= 1.9f;
		m_vecVertex[i].p.x += 0.35f;
		}*/
	}
	//선생님이 한거
	{
		cCubeNode::Setup();
		m_eCharater = M_RFOOT;
		D3DXMATRIXA16 matS, matT, mat;
		D3DXMatrixScaling(&matS, 0.2f, 0.6f, 0.2f);
		D3DXMatrixTranslation(&matT, 0.1f, -0.3f, 0.0f);
		mat = matS*matT;
		for (size_t i = 0; i < m_vecVertex.size(); i++)
		{
			D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &mat);
		}
		m_vLocalPos.y = -0.3f;
	}
}

void cRightLeg::Update()
{
	

	if (*GetBreakTime() == true)
	{
		if (GetRotDeltaX() < 1.0f && m_isturn == false)
		{
			SetRotDeltaX(GetRotDeltaX() + 0.05);
		}
		else
		{
			m_isturn = true;
			SetRotDeltaX(GetRotDeltaX() - 0.05f);
			if (GetRotDeltaX() < -1.0)
				m_isturn = false;
		}
		D3DXMatrixRotationX(&m_matR, GetRotDeltaX());
	}
	else
	{
		SetRotDeltaX(0.0f);
		D3DXMatrixRotationX(&m_matR, GetRotDeltaX());
	}
	cCubeNode::Update();

}

