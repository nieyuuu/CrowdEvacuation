#pragma once
#include "EvacuationScene.h"
#include "../RVO/RVOSimulator.h"

// ��Ⱥ�ڳ����е��˶�����ɢ�㷨
class IEvacuationStrategy
{
public:
	IEvacuationStrategy();
	virtual ~IEvacuationStrategy();

	virtual void run();

private:
	void __init();
	virtual bool __isFinish() = 0;
	virtual void __onPreDoStep() = 0;
	virtual void __onPostDoStep() = 0;

protected:
	CEvacuationScene* m_pScene = nullptr;
};