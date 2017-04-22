#pragma once
#include "cCubeNode.h"
class cLeftArm : public cCubeNode
{
public:
	cLeftArm();
	~cLeftArm();

	float deltaX;

	virtual void Setup() override;
	virtual void Update() override;

};

