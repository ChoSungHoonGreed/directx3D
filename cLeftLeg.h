#pragma once
#include "cCubeNode.h"
class cLeftLeg :public cCubeNode
{
public:
	cLeftLeg();
	~cLeftLeg();

	virtual void Setup() override;
	virtual void Update() override;
	//void Update();

};

