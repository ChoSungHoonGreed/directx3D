#pragma once
#include "cCubePNT.h"
class cCubeNode :public cCubePNT
{
public:
	cCubeNode();

protected:
	D3DXVECTOR3			m_vLocalPos;	//현제의 위치
	D3DXMATRIXA16		m_matLocalTM;	//현제 트렌스메트릭스
	D3DXMATRIXA16		m_matWorldTM;	//트렌스 월드 메트릭스
	D3DXMATRIXA16		m_matR;
	MOVECHARACTER		m_eCharater;	//케릭터 부위 관련
	bool				m_isturn;
	bool				m_isrest;

	//cCubePNT			m_vecPNT;//<<::

	std::vector<cCubeNode*>	m_vecChild;	//나중에 찾을 것
										//	std::vector<*D3DXVECTOR3> m_vtemp;

										//std::vector<ST_PNT_VERTEX>		m_vecVertex;

	SYNTHESIZE(D3DXMATRIXA16*, m_pParentWorldTM, parentWorldTM);//겟셋만드는부분
	SYNTHESIZE(float, m_fRotDeltaX, RotDeltaX);
	SYNTHESIZE(bool*, m_isBreakTime, BreakTime);


public:
	virtual ~cCubeNode();

	virtual void AddChild(cCubeNode* pChild);//첨가 덧붙이기
	virtual void Destroy();



	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
};

