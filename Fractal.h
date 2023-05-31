#pragma once
#include"structure.h"
#include"ImGuiManager.h"
#include<cmath>
#include<numbers>
#include<Novice.h>

class Fractal
{
public:
	Fractal();
	~Fractal();

	/// <summary>
	/// 曲線を引く処理
	/// </summary>
	/// <param name="startpos"></param>
	/// <param name="endPos"></param>
	/// <param name="count"></param>
	static void Draw(DoubleVector2  startpos, DoubleVector2  endPos,int count);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

private:
	DoubleVector2 StartPos;
	DoubleVector2 endPos;
	
	int count;

	
	const double PI = std::numbers::pi;
	

};


