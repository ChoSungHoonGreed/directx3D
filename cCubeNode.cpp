#include "stdafx.h"
#include "cCubeNode.h"


cCubeNode::cCubeNode()
	:m_vLocalPos(0, 0, 0)
	, m_fRotDeltaX(0.0f)
	, m_pParentWorldTM(NULL)//<<:¼±»ý´ÔÃß°¡
	, m_isturn(false)
	,m_isrest(true)
{
	D3DXMatrixIdentity(&m_matWorldTM);
	D3DXMatrixIdentity(&m_matLocalTM);
	D3DXMatrixIdentity(&m_matR);
}


cCubeNode::~cCubeNode()
{
	//: to do someting

}

void cCubeNode::AddChild(cCubeNode * pChild)
{
		pChild->m_pParentWorldTM = &m_matWorldTM;
		pChild->m_isBreakTime = m_isBreakTime;
		m_vecChild.push_back(pChild);
}

void cCubeNode::Destroy()
{
	//¼±»ý´ÔÀÌ Ãß°¡
	{
		for each(auto p in m_vecChild)
		{
			p->Destroy();
		}
		delete this;
	}
}

void cCubeNode::Setup()
{
	cCubePNT::Setup();

	//: to do someting
}

void cCubeNode::Update()
{
	{
		cCubePNT::Update();

		D3DXMATRIXA16 matR, matRY, matT;
		D3DXMatrixIdentity(&matR);
		D3DXMatrixIdentity(&matT);
		D3DXMatrixIdentity(&matRY);

		D3DXMatrixTranslation(&matT, m_vLocalPos.x, m_vLocalPos.y, m_vLocalPos.z);

		m_matLocalTM = matR * m_matR * matT; // srt
		m_matWorldTM = m_matLocalTM;

		if (m_pParentWorldTM)
		{
			m_matWorldTM *= *m_pParentWorldTM;
		}

		for each(auto p in m_vecChild)
		{
			p->Update();
		}
	}
	//: to do someting
}

void cCubeNode::Render()//·»´õ ·»´õ ·»´õ
{
	
	{
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);
		cCubePNT::Render();
		for each(auto p in m_vecChild)
		{
			p->Render();
		}
	}
}
