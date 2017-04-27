#pragma once
class cCubePNT
{
public:
	cCubePNT();
protected:
	std::vector<ST_PNT_VERTEX> m_vecVertex;
	std::vector<ST_TARGET_POINT>m_vecTarPointPTN;
public:
	virtual ~cCubePNT();
	virtual void Setup();
	virtual void Update();
	virtual void Render();
};

