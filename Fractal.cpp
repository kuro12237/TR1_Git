#include "Fractal.h"

Fractal::Fractal()
{
	this->StartPos = { 240.0f,360.0f };
	this->endPos = { 1040.0f,360.0f};
	count = 0;
}

const double Sin60Degrees = std::sin(std::numbers::pi / 3);

const double cos60Degrees = std::cos(std::numbers::pi / 3);


void Fractal::Draw(DoubleVector2  startpos, DoubleVector2  endPos,int count)
{
	DoubleVector2 halfPosition;
	DoubleVector2 topPosition;
	DoubleVector2 twoThirdsPosition;

	if (count <= 0)
	{
		Novice::DrawLine(
			int(startpos.x), int(startpos.y),
			int(endPos.x), int(endPos.y),
			BLACK);
		return;
	}
	//1/3を求める
	halfPosition.x = (2*startpos.x + endPos.x) / 3;
	halfPosition.y = (2*startpos.y + endPos.y) / 3;

	//2/3を求める
	twoThirdsPosition.x = (startpos.x + 2*endPos.x) / 3;
	twoThirdsPosition.y = (startpos.y + 2*endPos.y) / 3;

	//頂点の座標を求める
	topPosition.x = halfPosition.x + (twoThirdsPosition.x - halfPosition.x)*cos60Degrees
		+ (twoThirdsPosition.y - halfPosition.y)*Sin60Degrees;
	
	topPosition.y = halfPosition.y - (twoThirdsPosition.x - halfPosition.x)*Sin60Degrees + 
		(twoThirdsPosition.y - halfPosition.y)*cos60Degrees;
	
	
	//一本目の表示
	Draw(startpos, halfPosition, count - 1);
	//1/3から頂点まで
	Draw(halfPosition, topPosition, count - 1);
	//頂点から2/3まで
	Draw(topPosition, twoThirdsPosition, count- 1);
	//2/3から終点まで
	Draw(twoThirdsPosition,endPos, count - 1);

	

}

void Fractal::Update()
{

	
	Draw(StartPos, endPos,count);

	//ImGui
	ImGui::Begin("Fractal");

	ImGui::InputInt("Count", &count);

	ImGui::End();
}
