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
	{//내가한거
	 //	D3DXMATRIXA16 matR, matY, matT;

	 //	D3DXMatrixRotationY(&matR, m_fRotY);//각도 돌려준다

	 //	D3DXMatrixIdentity(&matT);//정규화 시켜주고 
	 //	//D3DXMatrixIdentity(&matR);

	 //	//어느부분이 로테이션 어느부분이 트렌스레이션 위치이동 T는 그 위치를 저장

	 //	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);

	 //	m_vDirection = D3DXVECTOR3(0, 0, 1);

	 //	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);

	 //	//srt// s = 스케일//


	 //	m_matWorld = matR  * matT;
	}
	//선생님
	{
		RECT rc;
		GetClientRect(g_hWnd, &rc);


		D3DXMATRIXA16 matR, matRX;
		D3DXMatrixRotationY(&matR, m_fRotY);
		//D3DXMatrixRotationX(&matRX, m_fRotY);


		m_vDirection = D3DXVECTOR3(0, 0, 1);
		D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);

		D3DXMATRIXA16 matTranslation; //matT
		D3DXMatrixTranslation(&matTranslation, m_vPosition.x, m_vPosition.y, m_vPosition.z);

		m_matWorld = matR * matTranslation;
	}
	/*if (GetKeyState('A') & 0x8000 && GetKeyState('W') & 0x8000 && GetKeyState('S') & 0x8000 && GetKeyState('D') & 0x8000)
	{
	m_isBreakTimechar = false;
	}*/

	m_isBreakTimechar = false;

	if (GetKeyState('W') & 0x8000)
	{
		m_vPosition = m_vPosition + (m_vDirection*0.1f);
		m_isBreakTimechar = true;

		//m_fRotY *= 0.1f;
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
