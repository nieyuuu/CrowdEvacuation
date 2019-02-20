#pragma once
#include "EvacuationScene.h"
#include "../RVO/RVOSimulator.h"
#include "common/BaseProduct.h"

//NOTE: FOR UNIT TEST
#ifdef _DEBUG
#define private public
#define protected public
#endif

class IEvacuationStrategy : public hiveOO::CBaseProduct
{
public:
	IEvacuationStrategy();
	virtual ~IEvacuationStrategy();

	virtual void run();
	virtual void init();
	void setEvacuationScene(CEvacuationScene* pScene) { m_pScene = pScene; }
	CEvacuationScene* getEvacuationScene() const { return m_pScene; }

private:
	virtual bool __isFinish();
	virtual void __constructRoadMap();
	virtual void __assignNavNode2Agent();
	virtual void __afterSimulationDoStep() = 0;

	void __constructEvacuationScene();
	void __updateVisualization();
	void __addPath2RoadMap(const std::vector<glm::vec2>& vPath);
	void __updateAgentVelocity();

protected:
	bool _isAllAgentReachExit();

	int m_EvacuationTimeCost = 0;
	CEvacuationScene* m_pScene = nullptr;
	std::unordered_map<glm::vec2, glm::vec2, HashFunc4Node> m_RoadMap;
};

bool __isVisited(const glm::vec2& vNode, const std::vector<glm::vec2>& vVisitedNodeSet);
std::pair<std::vector<glm::vec2>, float> __findShortestPathToExit(const glm::vec2& vNode, const std::vector<glm::vec2>& vExits, CSceneGraph* pGraph);
float __calAvgEvacuationTime4Agents(const std::vector<IAgent*>& vAgents);
float __calMaxEvacuationTime4Agents(const std::vector<IAgent*>& vAgents);