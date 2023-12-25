#include "Connector.h"

Connector::Connector(Statement* Src, Statement* Dst,Point Start,Point End):Start(Start),End(End)
//When a connector is created, it must have a source statement and a destination statement
//There are NO FREE connectors in the flowchart
{
	this->Select = false;
	SrcStat = Src;
	DstStat = Dst;
}

void Connector::setSrcStat(Statement *Src)
{	SrcStat = Src;	}

Statement* Connector::getSrcStat()
{	return SrcStat;	}

void Connector::setDstStat(Statement *Dst)
{	DstStat = Dst;	}

Statement* Connector::getDstStat()
{	return DstStat;	}


void Connector::setStartPoint(Point P)
{	Start = P;	}

Point Connector::getStartPoint()
{	return Start;	}

void Connector::setEndPoint(Point P)
{	End = P;	}

Point Connector::getEndPoint()
{	return End;	}

void Connector::Draw(Output* pOut) const
{
	///TODO: Call Output to draw a connector from SrcStat to DstStat on the output window
	pOut->DrawConnector1(Start,End,Select);
}

