#include "SegmentApproximator.h"
#include"pch.h"

CSegmentApproximator::CSegmentApproximator(void)
{
}

CSegmentApproximator::~CSegmentApproximator(void)
{
}


vector<list<CPoint2D>>& CSegmentApproximator::getSegmentsApproxVector()
{
	return segmentsApprox;
}

void CSegmentApproximator::approx(const list<CPoint2D>>& segments, double maxDistance)
{
    CPoint2D p;

    segmentsApprox = segments;

    douglasPeuckerRecursive(segmentsApprox, segmentsApprox.begin(), --(segmentsApprox.end()), maxDistance);

}

void CSegmentApproximator::douglasPeuckerRecursive(list<CPoint2D>& segment, std::list<CPoint2D>::iterator startItr, std::list<CPoint2D>::iterator endItr, double maxDistance)
{
	if (segment.size() < 3) return;
	if (distance(startItr, endItr) == 2) return;
	CPoint2D pStart; CPoint2D pEnd;
	pStart.setX(startItr->getX()); pStart.setY(startItr->getY());
	
	pEnd.setX(endItr->getX()); pEnd.setY(endItr->getY());

	double dist=0.0, maxDist=0.0;
	std::list<CPoint2D>::iterator maxItr, itr;

	for(itr = startItr; itr != endItr; itr++)
	{
		CLine2D line = CLine2D(pStart, pEnd);
		// calc distance
		dist = itr->distanceTo(line);
		if (dist>maxDist){
			maxDist=dist;
			maxItr=itr;
		}
	}
	
	if(maxDist<=maxDistance){

		segment.erase((++startItr), endItr);
		return;
	}

	douglasPeuckerRecursive(segment, startItr, maxItr, maxDistance);
	douglasPeuckerRecursive(segment, maxItr, endItr, maxDistance);
}

double CSegmentApproximator::calcDist(int xS, int yS, int xE, int yE, int x, int y)
{
    double bx, by, rv_sq, dist;

    int rvx = xS - xE;
    int rvy = yS - yE;

    rv_sq = (rvx * rvx) + (rvy * rvy);

    bx = x - xS;
    by = y - yS;

    dist = abs((bx * rvy - by * rvx)) / sqrt(rv_sq);

    return dist;

}