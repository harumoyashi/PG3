#include "DxLib.h"
#include "Enemy.h"

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "LE2A_01_アイカワ_ハルヒコ";

// ウィンドウ横幅
const int WIN_WIDTH = 600;

// ウィンドウ縦幅
const int WIN_HEIGHT = 400;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み

	// ゲームループで使う変数の宣言
	Enemy* enemys;
	const int maxEnemy = 10;
	enemys = new Enemy[maxEnemy];

	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char prev[256] = { 0 };

	// ゲームループ
	while (true) {
		for (int i = 0; i < 256; i++) {
			prev[i] = keys[i];
		}
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//
		// 更新処理
		if (keys[KEY_INPUT_RETURN] == 1 && prev[KEY_INPUT_RETURN] == 0)
		{
			if (enemys->GetIsAlive())
			{
				enemys->SetIsAlive(false);
			}
			else
			{
				enemys->SetIsAlive(true);
			}
		}

		// 描画処理

		// 背景描画

		// 文字描画
		for (int i = 0; i < maxEnemy; i++)
		{
			DrawFormatString(0, i * 20, 0xffffff, "enemy[%d]:isAlive = %d", i, enemys[i].GetIsAlive());
		}

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_F5) == 1) {
			break;
		}
	}
	delete[] enemys;

	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}