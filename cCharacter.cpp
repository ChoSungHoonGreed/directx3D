#include "stdafx.h"
#include "cCharacter.h"

//키입력 후 위치 변환 할거임.
cCharacter::cCharacter()
//>:불값하나 추가하자.
	:m_vDirection(0, 0, 1)
	, m_vPosition(0, 0, 0)
	, m_fRotY(0.0f)
	, m_isBreakTimechar(false)
{

	D3DXMatrixIdentity(&m_matWorld);
}


cCharacter::~cCharacter()
{
}

void cCharacter::Setup()
{
}

void cCharacter::Update()
{

	{
		RECT rc;
		GetClientRect(g_hWnd, &rc);


		D3DXMATRIXA16 matR, matRX;
		D3DXMatrixRotationY(&matR, m_fRotY);


		m_vDirection = D3DXVECTOR3(0, 0, 1);
		D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);

		D3DXMATRIXA16 matTranslation; //matT
		D3DXMatrixTranslation(&matTranslation, m_vPosition.x, m_vPosition.y, m_vPosition.z);

		m_matWorld = matR * matTranslation;
	}


	m_isBreakTimechar = false;

	if (GetKeyState('W') & 0x8000)
	{
		m_vPosition = m_vPosition + (m_vDirection*0.1f);
		m_isBreakTimechar = true;

	}

	else if (GetKeyState('S') & 0x8000)
	{
		m_isBreakTimechar = true;
		m_vPosition = m_vPosition - (m_vDirection * 0.01f);
	}


	if (GetKeyState('A') & 0x8000)
	{
		m_isBreakTimechar = true;
		m_fRotY -= 0.1f;
	}

	else if (GetKeyState('D') & 0x8000)
	{
		m_isBreakTimechar = true;
		m_fRotY += 0.1f;
	}






	//to be someting
}

void cCharacter::Render()
{
}

D3DXVECTOR3 & cCharacter::GetPosition()
{
	//to be someting
	// TODO: 여기에 반환 구문을 삽입합니다.
	return m_vPosition;
}
