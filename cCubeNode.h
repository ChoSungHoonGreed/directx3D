#pragma once
#include "cCubePNT.h"
class cCubeNode :public cCubePNT
{
public:
	cCubeNode();

protected:
	D3DXVECTOR3			m_vLocalPos;	//������ ��ġ
	D3DXMATRIXA16		m_matLocalTM;	//���� Ʈ������Ʈ����
	D3DXMATRIXA16		m_matWorldTM;	//Ʈ���� ���� ��Ʈ����
	D3DXMATRIXA16		m_matR;
	MOVECHARACTER		m_eCharater;	//�ɸ��� ���� ����
	bool				m_isturn;
	bool				m_isrest;

	//cCubePNT			m_vecPNT;//<<::

	std::vector<cCubeNode*>	m_vecChild;	//���߿� ã�� ��
										//	std::vector<*D3DXVECTOR3> m_vtemp;

										//std::vector<ST_PNT_VERTEX>		m_vecVertex;

	SYNTHESIZE(D3DXMATRIXA16*, m_pParentWorldTM, parentWorldTM);//�ټ¸���ºκ�
	SYNTHESIZE(float, m_fRotDeltaX, RotDeltaX);
	SYNTHESIZE(bool*, m_isBreakTime, BreakTime);


public:
	virtual ~cCubeNode();

	virtual void AddChild(cCubeNode* pChild);//÷�� �����̱�
	virtual void Destroy();



	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
};

