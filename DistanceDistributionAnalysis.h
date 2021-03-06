#pragma once
#include <map>
#include <list>
#include "JointDistributionAnalysis.h"
class DistanceDistributionAnalysis :
	public JointDistributionAnalysis
{
public:
	DistanceDistributionAnalysis();
	~DistanceDistributionAnalysis();
private:
	virtual void updateImpl();
	virtual bool selectDistribution(const Node* n, int& selection) const;
	virtual void collectSample(
		std::vector<float>& samplesX,
		std::vector<float>& samplesY,
		std::vector<float>& sampleWeights) const;
	std::map<int, std::list<float>> distances;
	float mMaxDistance;
	void annotateDistances(const Forest* f);
	virtual bool serialiseAdditional(picojson::value& v) const;
	virtual bool deserialiseAdditional(const picojson::value& v);

	virtual bool preferredBinBoundariesX(float& minX, float& maxX) { minX = 0.f; maxX = 180.f; return true; }
	virtual bool preferredBinBoundariesY(float& minY, float& maxY) { minY = 0.f; maxY = mMaxDistance; return true; }
};

