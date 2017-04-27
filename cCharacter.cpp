#include "stdafx.h"
#include "cCharacter.h"


cCharacter::cCharacter()
// : to do someting
	: m_fRotY(0.0f),
	m_vDirection(0, 0, 1),
	m_vPosition(-8, 0, 0)
{
	D3DXMatrixIdentity(&m_matWorld);
}


cCharacter::~cCharacter()
{
}

void cCharacter::Setup()
{
	cCubePNT::Setup();

	


}
void cCharacter::Update()
{
	// : to do someting
	if (GetKeyState('A') & 0x8000)
	{
		m_fRotY -= 0.05f;
	}
	if (GetKeyState('D') & 0x8000)
	{
		m_fRotY += 0.05f;
	}

	if (GetKeyState('W') & 0x8000)
	{
		m_vPosition = m_vPosition + (m_vDirection * 0.1);
	}
	if (GetKeyState('S') & 0x8000)
	{
		m_vPosition = m_vPosition - (m_vDirection * 0.1f);
	}

	/*
	if (m_vPosition.x <= m_vecTarPointPTN[1].p.x)
	{
		m_vPosition = m_vPosition + (m_vDirection * 0.1);
	}*/
	//if (m_vPosition.x >= m_vecTarPointPTN[0].p.x && m_vPosition.z >= m_vecTarPointPTN[0].p.z){m_fRotY = 120.0f;}
	//else if (m_vPosition.x <= m_vecTarPointPTN[3].p.x && m_vPosition.z >= m_vecTarPointPTN[3].p.z) { m_fRotY = -120.0f; }
	//else if (m_vPosition.x >= m_vecTarPointPTN[7].p.x && m_vPosition.z >= m_vecTarPointPTN[7].p.z) { m_fRotY = 120.0f; }
	//else if (m_vPosition.x <= m_vecTarPointPTN[11].p.x && m_vPosition.z >= m_vecTarPointPTN[11].p.z) { m_fRotY = 120.0f; }

	//if (GetKeyState('Q') & 0x8001)
	//{
	//	m_vPosition = m_vPosition + (m_vDirection * 0.1f);
	//	m_fRotY -= 0.0148592;
	//}

	RECT rc;
	GetClientRect(g_hWnd, &rc);
	
	D3DXMATRIXA16 matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);
	m_vDirection = D3DXVECTOR3(0, 0, 1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	m_matWorld = matR * matT;

}
void cCharacter::Render()
{

}
D3DXVECTOR3 & cCharacter::GetPosition()
{
	// : to do someting
	return m_vPosition;
}
