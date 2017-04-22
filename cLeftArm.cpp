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

	deltaX = cCubeNode::GetRotDeltaX();
	//내가한거
	{
		/*cCubeNode::Setup();
		for (int i = 0; i < m_vecVertex.size(); i++)
		{
		m_vecVertex[i].p = m_vecVertex[i].p + D3DXVECTOR3(5, 5, 0);
		D3DXVec3Scale(&m_vecVertex[i].p, &m_vecVertex[i].p, 0.25f);
		m_vecVertex[i].p.y *= 1.64f;
		m_vecVertex[i].p.x *= 0.7f;
		}*/
	}
	//선생님이 한거
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
	

	D3DXMATRIXA16   matRY, matT;
	
	D3DXMatrixIdentity(&matT);
	D3DXMatrixIdentity(&matRY);

	D3DXMatrixTranslation(&matT, m_vLocalPos.x, m_vLocalPos.y, m_vLocalPos.z);

	if (deltaX < 1.0f && m_isturn == false)
	{
		deltaX += 0.05f;
	}
	else
	{
		m_isturn = true;
		deltaX -= 0.05f;

		if (deltaX < -1.0)
			m_isturn = false;
	}
	D3DXMatrixRotationX(&m_matR, deltaX);
	cCubeNode::Update();

}
