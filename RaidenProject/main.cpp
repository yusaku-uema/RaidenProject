/********************************************************************
**	第1章　自分でゲームを作っていこう
**	　雷電プロジェクト
********************************************************************/
#include "DxLib.h"
#include"AdstractScene.h"
#include"SceneManager.h"
#include"Title.h"

/***********************************************
 * 変数
 ***********************************************/
bool Forcedtermination = false; //強制終了フラグ

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

    SceneManager sceneMng(new Title()); 

    while (ProcessMessage() == 0 && Forcedtermination != true && sceneMng.Update() != nullptr) {
        // ゲームパットのBACKボタン押されたら強制終了
        if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_7) { 
            Forcedtermination = true; //フラグをTrueに
        }

        ClearDrawScreen();		// 画面の初期化

        sceneMng.Draw();

        ScreenFlip();			// 裏画面の内容を表画面に反映

    }

    DxLib_End();	// DXライブラリ使用の終了処理

    return 0;	// ソフトの終了
}