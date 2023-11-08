#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include "player.h"

GameScene::GameScene()
{



}

GameScene::~GameScene() 
{



}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	groundmodel_.reset(Model::CreateFromOBJ("ground", true));
	textureHandle_ = TextureManager::Load("sample.png");

	worldtransform_.Initialize();
	viewprojection_.Initialize();

	model_.reset(Model::Create());

	player_ = std::make_unique<Player>();

	ground_ = std::make_unique<Ground>();

	player_->Initialize(model_.get(), textureHandle_);

	ground_->Initialize(groundmodel_.get());

}

void GameScene::Update() 
{

	player_->Update();

	ground_->Update();

	viewprojection_.UpdateMatrix();

}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	player_->Draw(viewprojection_);

	ground_->Draw(viewprojection_);

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
