#pragma once
#include "EvacuationScene.h"
#include "../RVO/RVOSimulator.h"

// ��Ⱥ�ڳ����е��˶�����ɢ�㷨
class IEvacuationStrategy
{
public:
	IEvacuationStrategy();
	virtual ~IEvacuationStrategy();

	virtual void run() = 0;

private:
	virtual void __init(const std::string& vSceneConfig, const std::string& vAgentConfig);
	void __initScene(const std::string& vSceneConfig);
	void __initAgents(const std::string& vAgentConfig);

protected:
	CEvacuationScene* m_pScene = nullptr;
};