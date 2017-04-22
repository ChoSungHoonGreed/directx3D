#include "stdafx.h"
#include "cBody.h"


cBody::cBody()
{
}


cBody::~cBody()
{

}

void cBody::Setup()
{
	//내가한거
	{
		////cCubeNode::
		//cCubeNode::Setup();


		//for (int i = 0; i < m_vecVertex.size(); i++)
		//{
		//	m_vecVertex[i].p = m_vecVertex[i].p + D3DXVECTOR3(0, 4, 0);
		//	D3DXVec3Scale(&m_vecVertex[i].p, &m_vecVertex[i].p, 0.50f);
		//	m_vecVertex[i].p.x *= 1.5;
		//}
		////m_vecVertex[0].p = D3DXVECTOR3(0, 0, 0);//맨랜더

	}
	//선생님이 한거

	{
		cCubeNode::Setup();
		m_eCharater = M_BODY;

		D3DXMATRIXA16 matS, matT, mat;
		D3DXMatrixScaling(&matS, 0.4f, 0.6f, 0.2f);
		D3DXMatrixTranslation(&matT, 0.0f, 0.0f, 0.0f);
		mat = matS*matT;
		for (size_t i = 0; i < m_vecVertex.size(); i++)
		{
			D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &mat);
		}
	}
}

void cBody::Update()
{
	cCubeNode::Update();
}

