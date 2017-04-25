#pragma once
class cCamera;
class cGrid;
class cPyramid;
class cCubeMan;
class cCubePNT;

class cMainGame
{
public:
	cMainGame();
	~cMainGame();

private:
	//LPDIRECT3D9				m_pD3D;
	//LPDIRECT3DDEVICE9		m_pD3DDevice;


	cCamera*		m_pCamera;
	cGrid*			m_pGrid;
	cPyramid*		m_pPyramid;
	cCubeMan*		m_pCubeMen;

	

public:
	void Setup();
	void Update();
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void Set_Light();
	void Set_Light100();
	void Set_Light200();

};

