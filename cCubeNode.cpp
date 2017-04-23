#include "stdafx.h"
#include "cCubeNode.h"


cCubeNode::cCubeNode()
	:m_vLocalPos(0, 0, 0)
	, m_fRotDeltaX(0.0f)
	, m_pParentWorldTM(NULL)//<<:�������߰�
	, m_isturn(false)
	
	//,m_isBreakTime(false)

	//>::
	//: to do someting
	//<<::
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
	//���� �Ѱ�
	//m_vecChild.push_back(pChild);
	//m_vecPNT.Setup();
	//: to do someting
	{//

		pChild->m_pParentWorldTM = &m_matWorldTM;
		pChild->m_isBreakTime = m_isBreakTime;
		m_vecChild.push_back(pChild);
	}
}

void cCubeNode::Destroy()
{
	//�������� �߰�
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

		//if (m_vecChild.size())
		//{
		//	//m_fRotDeltaX += 0.1f;
		//	
		//}


		//if (*m_isBreakTime)//���� �޽��� �Ұ��� �켱 ������ if�� ���� ����.
		//{
		//	switch (m_eCharater)
		//	{
		//	case M_BODY:
		//		break;
		//	case M_HEAD:
		//		//if()���� ���� false�̸� �����.
		//		m_fRotDeltaX += 0.1f;
		//		D3DXMatrixRotationY(&matRY, m_fRotDeltaX);
		//		break;
		//	case M_LHAND:

		//		if (m_fRotDeltaX < 1.0f && m_isturn == false)
		//		{
		//			m_fRotDeltaX += 0.05;
		//		}
		//		else
		//		{
		//			m_isturn = true;
		//			m_fRotDeltaX -= 0.05f;
		//			if (m_fRotDeltaX < -1.0)
		//				m_isturn = false;
		//		}
		//		D3DXMatrixRotationX(&matRY, m_fRotDeltaX);

		//		break;
		//	case M_RHAND:

		//		if (m_fRotDeltaX < 1.0f && m_isturn == true)
		//		{
		//			m_fRotDeltaX += 0.05;
		//		}
		//		else
		//		{
		//			m_isturn = false;
		//			m_fRotDeltaX -= 0.05f;
		//			if (m_fRotDeltaX < -1.0)
		//				m_isturn = true;
		//		}
		//		D3DXMatrixRotationX(&matRY, m_fRotDeltaX);
		//		break;
		//	case M_LFOOT:

		//		if (m_fRotDeltaX < 1.0f && m_isturn == true)
		//		{
		//			m_fRotDeltaX += 0.05;
		//		}
		//		else
		//		{
		//			m_isturn = false;
		//			m_fRotDeltaX -= 0.05f;
		//			if (m_fRotDeltaX < -1.0)
		//				m_isturn = true;
		//		}
		//		D3DXMatrixRotationX(&matRY, m_fRotDeltaX);
		//		break;
		//	case M_RFOOT:

		//		if (m_fRotDeltaX < 1.0f && m_isturn == false)
		//		{
		//			m_fRotDeltaX += 0.05;
		//		}
		//		else
		//		{
		//			m_isturn = true;
		//			m_fRotDeltaX -= 0.05f;
		//			if (m_fRotDeltaX < -1.0)
		//				m_isturn = false;
		//		}
		//		D3DXMatrixRotationX(&matRY, m_fRotDeltaX);
		//		break;
		//	}
		//}


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

void cCubeNode::Render()//���� ���� ����
{

	{//�����Ѱ�
	 //	if (m_vecVertex.size() > 0)
	 //	{

	 //		g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);//
	 //		g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);//
	 //		//for (int i = 0; i < m_vecChild.size(); i++)
	 //		//{
	 //		//	m_vecChild[0]->m_vecVertex.size();
	 //		//}
	 //		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex.size() / 3, &m_vecVertex[0], sizeof(ST_PNT_VERTEX));//
	 //	}
	 //	for (int i = 0; i < m_vecChild.size(); i++)
	 //	{
	 //		m_vecChild[i]->Render();
	 //	}
	}

	//�����Ѱ�
	{
		//for (int i = 0; i < m_vecChild.size(); i++)
		//{
		//	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);
		//	g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);
		//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecChild.size() / 3, &m_vecChild[0]->m_vecVertex[0], sizeof(ST_PNT_VERTEX));
		//}
		//: to do someting
	}

	
	{
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);
		cCubePNT::Render();
		for each(auto p in m_vecChild)
		{
			p->Render();
		}
	}
}
