#include "stdafx.h"
#include "cRightArm.h"


cRightArm::cRightArm()
{
}


cRightArm::~cRightArm()
{
}

void cRightArm::Setup()
{
	//내가한거
	{
		/*cCubeNode::Setup();
		for (int i = 0; i < m_vecVertex.size(); i++)
		{
		m_vecVertex[i].p = m_vecVertex[i].p + D3DXVECTOR3(-5, 5, 0);
		D3DXVec3Scale(&m_vecVertex[i].p, &m_vecVertex[i].p, 0.25f);
		m_vecVertex[i].p.y *= 1.64f;
		m_vecVertex[i].p.x *= 0.7f;
		}*/
	}
	//선생님이 한거
	{
		cCubeNode::Setup();
		m_eCharater = M_RHAND;
		D3DXMATRIXA16 matS, matT, mat;
		D3DXMatrixScaling(&matS, 0.2f, 0.6f, 0.2f);
		D3DXMatrixTranslation(&matT, 0.3f, -0.3f, 0.0f);
		mat = matS*matT;
		for (size_t i = 0; i < m_vecVertex.size(); i++)
		{
			D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &mat);
		}
		m_vLocalPos.y = 0.3f;
	}
}

