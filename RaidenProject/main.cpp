/********************************************************************
**	第1章　自分でゲームを作っていこう
**	　雷電プロジェクト
********************************************************************/
#include "DxLib.h"
#include"AdstractScene.h"
#include"SceneManager.h"

/***********************************************
 * プログラムの開始
 ***********************************************/
int	g_Key; //入力キー

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) {

    // タイトルを test に変更
    SetMainWindowText("雷電プロジェクト");

    ChangeWindowMode(TRUE);		// ウィンドウモードで起動

    SetGraphMode(1280, 720, 16); //ウィンドウサイズを設定

    if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

    SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

    SceneManager sceneMng();

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {  //sceneMng.Update() != nullptr

        // 入力キー取得   
        g_Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

        ClearDrawScreen();		// 画面の初期化

        ScreenFlip();			// 裏画面の内容を表画面に反映
    }

    DxLib_End();	// DXライブラリ使用の終了処理

    return 0;	// ソフトの終了
}