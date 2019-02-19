#pragma once
#include "BaseStrategy.h"
#include "Intersection.h"

class CCDFPredictionStrategy : public IEvacuationStrategy
{
public:
	CCDFPredictionStrategy();
	~CCDFPredictionStrategy();

private:
	void init() override;
	bool __isFinish() override;
	void __afterSimulationDoStep() override;
	void __constructRoadMap() override;
	void __assignNavNode2Agent() override;

	void __add2RoadMap(const std::vector<glm::vec2>& vShortestPath);
	void __initIntersections();
	void __updateIntersections();
	void __updateAgentsNavigation();

private:
	std::unordered_map<glm::vec2, glm::vec2, HashFunc4Node> m_RoadMap;
	std::unordered_map<glm::vec2, CIntersection*, HashFunc4Node> m_Intersections;
};

float __CDF2Factor(float vCDF);

/*
- ���㵱ǰʱ��·�ڵ�CDF
- ����δ��ĳ��ʱ��·�ڵ�CDF
- ���ݱ����˵��ƶ��ٶȼ���ߵ�Ȩ��
- ��������֮�����·����ͨ��ʱ��
- ����ߵ���Ⱥƽ���ƶ��ٶ�
- ��CDFӳ���ϵ��
- ����Agent��δ��ĳ��ʱ�̵�λ��
*/

