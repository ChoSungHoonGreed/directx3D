#include "stdafx.h"
#include "cCubeMan.h"


#include "cHead.h"
#include "cBody.h"
#include "cLeftArm.h"
#include "cRightArm.h"
#include "cLeftLeg.h"
#include "cRightLeg.h"
cCubeMan::cCubeMan()
	:m_pRoot(NULL)
	//:>
{

}


cCubeMan::~cCubeMan()
{
	//:>
	//:>선생님
	if (m_pRoot)
		m_pRoot->Destroy();
	//SAFE_DELETE(m_pRoot);
}

void cCubeMan::Setup()
{

	{//내가한거
	 //m_pRoot = new cCubeNode; //엠피루트생성

	 ////머리
	 //cCubeHead* head = new cCubeHead;
	 //cCubeBody* body = new cCubeBody;
	 //cLeftArm* leftArm = new cLeftArm;
	 //cRightArm* rArm = new cRightArm;
	 //cCubeLeftLong* Llong = new cCubeLeftLong;
	 //cCubeRightLong* Rlong = new cCubeRightLong;



	 //rArm->Setup();

	 //head->Setup();
	 //body->Setup();
	 //leftArm->Setup();
	 //Llong->Setup();
	 //Rlong->Setup();

	 ////몸
	 //m_pRoot->AddChild(head);

	 //m_pRoot->AddChild(body);

	 //m_pRoot->AddChild(leftArm);
	 //m_pRoot->AddChild(rArm);

	 //m_pRoot->AddChild(Llong);
	 //m_pRoot->AddChild(Rlong);


	}

	{//선생님
		cCharacter::Setup();
		ZeroMemory(&m_stMtl, sizeof(D3DMATERIAL9));
		m_stMtl.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
		m_stMtl.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
		m_stMtl.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);

		cBody* pBody = new cBody;
		pBody->Setup();
		pBody->SetparentWorldTM(&m_matWorld);
		pBody->SetBreakTime(&m_isBreakTimechar);
		m_pRoot = pBody;

		cHead* phead = new cHead;
		phead->Setup();
		phead->SetBreakTime(&m_isBreakTimechar);
		m_pRoot->AddChild(phead);

		cLeftArm* plarm = new cLeftArm;
		plarm->Setup();
		plarm->SetBreakTime(&m_isBreakTimechar);
		m_pRoot->AddChild(plarm);

		cRightArm* prarm = new cRightArm;
		prarm->Setup();
		prarm->SetBreakTime(&m_isBreakTimechar);
		m_pRoot->AddChild(prarm);

		cLeftLeg* pllong = new cLeftLeg;
		pllong->Setup();
		pllong->SetBreakTime(&m_isBreakTimechar);
		m_pRoot->AddChild(pllong);

		cRightLeg* prlong = new cRightLeg;
		prlong->Setup();
		prlong->SetBreakTime(&m_isBreakTimechar);
		m_pRoot->AddChild(prlong);

	}

	//:>
}

void cCubeMan::Update()
{
	{//내가한거
	 /*	cCharacter::Update();

	 m_pRoot->SetparentWorldTM(&m_matWorld);
	 m_fRotY += 0.1f;
	 m_pRoot->SetRotDeltaX(m_fRotY);
	 m_pRoot->Update();*/
	}
	//선생님이 한거
	{
		cCharacter::Update();

		if (m_pRoot)
			m_pRoot->Update();
	}
	

	//:>
}

void cCubeMan::Render()
{
	//m_pRoot->Render();

	{
		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
		g_pD3DDevice->SetMaterial(&m_stMtl);

		cCharacter::Render();
		D3DXMATRIXA16 matWorld;
		D3DXMatrixIdentity(&matWorld);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
		if (m_pRoot)
			m_pRoot->Render();
	}
	//:>
}
