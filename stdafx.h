// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <assert.h>


#include <d3dx9.h>
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")

extern HWND g_hWnd;
#define SAFE_RELEASE(p) {if(p)p->Release(); p = NULL;}
#define SAFE_DELETE(p) {if(p)delete p; p = NULL;}

#define SINGLETONE(class_name) \
private: \
class_name(void) ; \
~class_name(void); \
public: \
static class_name* GetInstance()\
{ \
static class_name instance; \
return &instance; \
}

struct ST_PC_VERTEX
{
	D3DXVECTOR3 p;			//�������� ����Ʈ 3���� �ϰڴ�
	D3DCOLOR	c;

	enum { FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE };
};

struct ST_PNT_VERTEX
{
	D3DXVECTOR3 p;			//�������� ����Ʈ 3���� �ϰڴ�
	D3DXVECTOR3	n;
	D3DXVECTOR2 t;
	D3DCOLOR	c;
	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 };

};
//varType = ���� varName = �����̸� // funName = �Լ��̸�
#define SYNTHESIZE(varType, varName, funName)\
private: varType varName;\
public: inline varType Get##funName(void) const { return varName; }\
public: inline void Set##funName(varType var) { varName = var; }

#include "cDeviceManager.h"

enum MOVECHARACTER
{
	M_BODY
	, M_HEAD
	, M_LHAND
	, M_RHAND
	, M_LFOOT
	, M_RFOOT

};
// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
