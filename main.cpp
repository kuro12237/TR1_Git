#include <Novice.h>
#include <structure.h>
#include <time.h>
#include"Dig.h"
#include"Fractal.h"

const char kWindowTitle[] = "LE2B_14_サカキバラ_イブキ";



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Dig *dig = new Dig();
	Fractal* fractal = new Fractal();
	

	srand(static_cast<unsigned int>(time(NULL)));

	MODE mode = DIG;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		int_Position StartPosition = {1,1};
		///
		/// ↓更新処理ここから
		///

		switch (mode)
		{
		case DIG:

			if (keys[DIK_2])
			{
				//初期化
				dig->Initialize();
			}

			if (keys[DIK_1])
			{
				dig->Update(StartPosition);
			}

			//MODE切り替え
			if (keys[DIK_SPACE]&&preKeys[DIK_SPACE]==0)
			{
				mode = FRACTAL;
			}

			break;

		case FRACTAL:

			fractal->Update();



			//MoDE切り替え
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
			{
				mode = DIG;
			}



			break;
		default:
			break;
		}

		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		Novice::ScreenPrintf(800, 20, "ModeChange::Space");

		switch (mode)
		{
		case DIG:
		
			Novice::ScreenPrintf(800, 0, "DigMode");
			
			dig->Draw();

			break;
		case FRACTAL:
			Novice::ScreenPrintf(800, 0, "Fractalmode");
			
			break;
		default:
			break;
		}

	
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
