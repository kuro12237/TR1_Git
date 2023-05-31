#include "Dig.h"

Dig::Dig()
{
	Map.BlockSize = 16;
	Map.Resource= BLACK;
}
int CallCount = 0;

void Dig::Initialize()
{

	
	if (!StartFlag)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			for (int x = 0; x < MAP_WIDTH; x++)
			{
				Map.m[y][x] = Wall;

			}
		}
		
		CallCount = 0;
			
		StartPosition = { 1,1 };
		Map.m[StartPosition.y][StartPosition.x]=Load;
		StartFlag = true;
			
	}
}

void Dig::Run(int_Position& StartPosition, MapTip& map)
{

	for (int i = 0; i < 8; ++i)
	{

		unsigned int RandIndex = rand() % 4;

		int_Position dig = { 0,0 };

		switch (RandIndex)
		{

		case UP:  // 上方向
			dig.y = -2;
			break;

		case DOWN:  // 下方向
			dig.y = 2;
			break;

		case LEFT:  // 左方向
			dig.x = -2;
			break;

		case RIGHT:  // 右方向
			dig.x = 2;
			break;

		}

		int_Position AnsDigPos = { 0,0 };

		AnsDigPos.x = StartPosition.x + dig.x;
		AnsDigPos.y = StartPosition.y + dig.y;


		if (AnsDigPos.x >= 0 && AnsDigPos.x < MAP_HEIGHT
			&&
			AnsDigPos.y >= 0 && AnsDigPos.y < MAP_WIDTH
			)
		{
			if (map.m[AnsDigPos.y][AnsDigPos.x] == Wall)
			{
				int_Position NewPos = { 0,0 };

				NewPos.x = (StartPosition.x + AnsDigPos.x) / 2;
				NewPos.y = (StartPosition.y + AnsDigPos.y) / 2;

				map.m[NewPos.y][NewPos.x] = Load;
				map.m[AnsDigPos.y][AnsDigPos.x] = Load;

				Run(AnsDigPos, map);

			}
		}
	}
	CallCount++;
}


void Dig::Update(int_Position StartPosition_)
{
	if (StartFlag)
	{
 
		Run(StartPosition_, Map);
	}
	StartFlag = false;

}

void Dig::SetStartFlag(bool StartFlag_)
{
	StartFlag = StartFlag_;
}

void Dig::Draw()
{



	for (int width = 0; width < MAP_WIDTH; width++)
	{
		for (int height = 0; height < MAP_HEIGHT; height++)
		{
			if (Map.m[width][height] == Wall)
			{
				Novice::DrawBox(
					Map.BlockSize * height,
					Map.BlockSize * width,
					Map.BlockSize, Map.BlockSize, 0.0f,
					Map.Resource, kFillModeSolid);
			}
		}

	}

	ImGui::Begin("Dig");
	ImGui::Text("MapTipSize"); 
	ImGui::Text("Width:: %d",MAP_WIDTH);
	ImGui::Text("Height::%d",MAP_HEIGHT);

	ImGui::Text("\nBlockProperty");
	
	ImGui::InputInt("BlockSize",&Map.BlockSize);


	ImGui::Text("\nCallRunFanc::%d", CallCount);

	ImGui::End();

}


