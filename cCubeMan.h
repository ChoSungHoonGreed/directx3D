#pragma once
#include"cCharacter.h"
class cCubeNode;

class cCubeMen : public cCharacter
{
public:
	cCubeMen();
	~cCubeMen();

public: // ������ ��ä�� �������ְ� ��忡�� ó��
	cCubeNode*			m_pRoot;
	D3DMATERIAL9		m_stMtl;


	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
};
