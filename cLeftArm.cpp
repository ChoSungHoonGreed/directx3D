#include "stdafx.h"
#include "cLeftArm.h"


cLeftArm::cLeftArm()
{
}


cLeftArm::~cLeftArm()
{
}

void cLeftArm::Setup()
{

	{
		cCubeNode::Setup();
		m_eCharater = M_LHAND;
		D3DXMATRIXA16 matS, matT, mat;
		D3DXMatrixScaling(&matS, 0.2f, 0.6f, 0.2f);
		D3DXMatrixTranslation(&matT, -0.3f, -0.3f, 0.0f);
		mat = matS*matT;
		for (size_t i = 0; i < m_vecVertex.size(); i++)
		{
			D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &mat);
		}
		m_vLocalPos.y = 0.3f;
	}
}

void cLeftArm::Update()
{
	
	if (*GetBreakTime() == true)
	{
		if (GetRotDeltaX() < 1.0f && m_isturn == false)
		{
			SetRotDeltaX(GetRotDeltaX() + 0.05f);
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
