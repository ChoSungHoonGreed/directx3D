#pragma once

class cPyramid;

class cGrid
{
public:
	cGrid();
	~cGrid();

private:
	std::vector<ST_PC_VERTEX>	m_vecVertex;
	std::vector<cPyramid*>		m_vecPyramid;
	std::vector<ST_TARGET_POINT>m_vecTarPoint;

public:
	void Setup(int nNumHalfTile = 15, float fInterval = 1.0f);
	void Render();
};

