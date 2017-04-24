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

	{
		cCubeNode::Setup();
		m_eCharater = M_HEAD;

		D3DXMATRIXA16 matS, matT, mat;
		D3DXMatrixScaling(&matS, 0.4f, 0.4f, 0.4f);
		D3DXMatrixTranslation(&matT, 0.0f, 0.0f, 0.0f);
		mat = matS*matT;

		//x = 0.15625 , y = 0.03125
		m_vecVertex[0].t = D3DXVECTOR2(0.125, 0.25);	//0
		m_vecVertex[1].t = D3DXVECTOR2(0.125, 0.0);//1 250
		m_vecVertex[2].t = D3DXVECTOR2(0.250, 0.0);//2
		m_vecVertex[3].t = D3DXVECTOR2(0.125, 0.250);//0
		m_vecVertex[4].t = D3DXVECTOR2(0.250, 0.0);//2
		m_vecVertex[5].t = D3DXVECTOR2(0.250, 0.25);//3
		m_vecVertex[6].t = D3DXVECTOR2(0.125, 0.46875);	//0
		m_vecVertex[7].t = D3DXVECTOR2(0.250, 0.25);//1 0.023437
		m_vecVertex[8].t = D3DXVECTOR2(0.125, 0.25);//2
		m_vecVertex[9].t = D3DXVECTOR2(0.125, 0.46875);//0
		m_vecVertex[10].t = D3DXVECTOR2(0.250, 0.46875);//2
		m_vecVertex[11].t = D3DXVECTOR2(0.250, 0.25);//3

	
		m_vecVertex[12].t = D3DXVECTOR2(0.250, 0.46875);	//0
		m_vecVertex[13].t = D3DXVECTOR2(0.250, 0.250);//1 250
		m_vecVertex[14].t = D3DXVECTOR2(0.359375, 0.25);//2
		m_vecVertex[15].t = D3DXVECTOR2(0.250, 0.46875);//0
		m_vecVertex[16].t = D3DXVECTOR2(0.359375, 0.250);//2
		m_vecVertex[17].t = D3DXVECTOR2(0.359375, 0.46875);//3

	
		m_vecVertex[18].t = D3DXVECTOR2(0, 0.50);	//0
		m_vecVertex[19].t = D3DXVECTOR2(0, 0.25);//1 250
		m_vecVertex[20].t = D3DXVECTOR2(0.125, 0.25);//2
		m_vecVertex[21].t = D3DXVECTOR2(0.0, 0.50);//0
		m_vecVertex[22].t = D3DXVECTOR2(0.125, 0.25);//2
		m_vecVertex[23].t = D3DXVECTOR2(0.125, 0.50);//3




		/*	m_vecVertex[9].t	 = D3DXVECTOR2(0.125, 0.50);
			m_vecVertex[9 + 1].t = D3DXVECTOR2(0.250, 0.50);
			m_vecVertex[9+ 2].t = D3DXVECTOR2(0.25, 0.15f);	
			m_vecVertex[6 + 0].t = D3DXVECTOR2(0.125f, 0.50f);
			m_vecVertex[6 + 0].t = D3DXVECTOR2(0.250, 0.50f);
			m_vecVertex[6 + 0].t = D3DXVECTOR2(0.25, 0.28125);*/

	


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
	else if (*GetBreakTime() == false && m_isrest == false)
	{
		SetRotDeltaX(0.0f);
		D3DXMatrixRotationY(&m_matR, GetRotDeltaX());
		m_isrest = true;
	}
	if (m_isrest == true)
	{
		if (GetRotDeltaX() < 0.5f && m_isturn == false)
		{
			SetRotDeltaX(GetRotDeltaX() + 0.005f);
			
		}
		else
		{
			m_isturn = true;
			SetRotDeltaX(GetRotDeltaX() - 0.005f);
			if (GetRotDeltaX() < -0.5f)
				m_isturn = false;
		}
		D3DXMatrixRotationY(&m_matR, GetRotDeltaX());
		
	}
	
	cCubeNode::Update();
}

