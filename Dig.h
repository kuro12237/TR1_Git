#pragma once
#include"structure.h"
#include<Novice.h>
#include<time.h>
#include<stdlib.h>
#include "ImGuiManager.h"

class Dig
{
public:
	Dig();
	~Dig();



	/// <summary>
	/// マップチップの初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update(int_Position StartPosition);

	/// <summary>
	/// 穴掘り関数
	/// </summary>
	/// <param name="StartPosition"></param>
	static void Run(int_Position& StartPosition, MapTip& map);
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// StartFlagのSetter
	/// </summary>
	/// <param name="StartFlag"></param>
	void SetStartFlag(bool StartFlag);

private:

	MapTip Map = {};
	bool StartFlag = false;
	int_Position StartPosition;
	

	
};

