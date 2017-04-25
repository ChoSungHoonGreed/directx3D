#pragma once
#include"cCharacter.h"
class cCubeNode;

class cCubeMan : public cCharacter
{
public:
	cCubeMan();
	~cCubeMan();

public: // 각각의 객채를 가지고있고 노드에서 처리
	cCubeNode*			m_pRoot;
	D3DMATERIAL9		m_stMtl;

	LPDIRECT3DTEXTURE9	m_pTexture;
	

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
	void Set_Material();
};

