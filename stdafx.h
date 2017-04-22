// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
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
	D3DXVECTOR3 p;			//정점으로 포인트 3개를 하겠다
	D3DCOLOR	c;

	enum { FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE };
};

struct ST_PNT_VERTEX
{
	D3DXVECTOR3 p;			//정점으로 포인트 3개를 하겠다
	D3DXVECTOR3	n;
	D3DXVECTOR2 t;
	D3DCOLOR	c;
	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 };

};
//varType = 형태 varName = 변수이름 // funName = 함수이름
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
// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
