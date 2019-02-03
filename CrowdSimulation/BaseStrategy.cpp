#include "BaseStrategy.h"
#include "ConfigParser.h"

IEvacuationStrategy::IEvacuationStrategy()
{
	__init();
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
		__onPreDoStep();
		pSim->doStep();
		__onPostDoStep();
	} while (!__isFinish());

	std::cout << "Evacuation End" << std::endl;
	std::cout << "Evacuation time cost: " << m_EvacuationTimeCost << std::endl;
}

void IEvacuationStrategy::__init()
{
	CSceneGraph* pGraph = new CSceneGraph();
	RVO::RVOSimulator* pSim = new RVO::RVOSimulator();

	CConfigParser::parseGraph("GraphConfig.xml", pGraph);
	CConfigParser::parseRVOSimulator("SimulatorConfig.xml", pSim);

	CEvacuationScene* pScene = new CEvacuationScene(pSim, pGraph);
	CConfigParser::parseScene("SceneConfig.xml", pScene);

	setEvacuationScene(pScene);
}