#include "BaseStrategy.h"
#include "ConfigParser.h"
#include "SceneVis.h"

IEvacuationStrategy::IEvacuationStrategy()
{
}

IEvacuationStrategy::~IEvacuationStrategy()
{
	_SAFE_DELETE(m_pScene);
}

void IEvacuationStrategy::run()
{
	auto pSim = m_pScene->getSimulator();

	std::cout << "Evacuation Begin" << std::endl;

	do {
		m_EvacuationTimeCost++;
		__updateVisualization();
		__onPreDoStep();
 		pSim->doStep();
		__avoidStuckInObstacles();
		__onPostDoStep();
	} while (!__isFinish());

	std::cout << "Evacuation End" << std::endl;
	std::cout << "Evacuation time cost: " << m_EvacuationTimeCost << std::endl;
}

void IEvacuationStrategy::init()
{
	__constructEvacuationScene();
	__constructRoadMap();
	__assignNavNode2Agent();
}

void IEvacuationStrategy::__constructEvacuationScene()
{
	CSceneGraph* pGraph = new CSceneGraph();
	RVO::RVOSimulator* pSim = new RVO::RVOSimulator();

	CConfigParser::parseGraph("GraphConfig.xml", pGraph);
	CConfigParser::parseRVOSimulator("SimulatorConfig.xml", pSim);

	CEvacuationScene* pScene = new CEvacuationScene(pSim, pGraph);
	CConfigParser::parseScene("SceneConfig.xml", pScene);

	setEvacuationScene(pScene);
}

void IEvacuationStrategy::__updateVisualization()
{
	CSceneVis::getInstance()->displayScene(m_pScene);
}

void IEvacuationStrategy::__avoidStuckInObstacles()
{
	//TODO: ����Agent��ǽ
	//���������ٶȵķ���ǰ��һ�ξ���
}
