#include "stdafx.h"
#include "cCubeNode.h"


cCubeNode::cCubeNode()
	:m_vLocalPos(0, 0, 0)
	, m_fRotDeltaX(0.0f)
	, m_pParentWorldTM(NULL)//<<:선생님추가
	, m_isturn(false)
	,m_isrest(true)


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

	//: to do someting
	{//

		pChild->m_pParentWorldTM = &m_matWorldTM;
		pChild->m_isBreakTime = m_isBreakTime;
		m_vecChild.push_back(pChild);
	}
}

void cCubeNode::Destroy()
{
	//선생님이 추가
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



		{
			//if (*m_isBreakTime)//이즈 펄스로 할거임 우선 무조껀 if문 들어가게 수정.
			//{
			//	switch (m_eCharater)
			//	{
			//	case M_BODY:
			//		break;
			//	case M_HEAD:
			//		//if()무슨 값이 false이면 흔들자.
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
		}//각 부위별 Update로 이동 완료.

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

void cCubeNode::Render()//렌더 렌더 렌더
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
