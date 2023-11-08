#include "Player.h"
#include <assert.h>
#include <ImGuiManager.h>
#include "MATHEX.h"



void Player::Initialize(Model* model, uint32_t textureHandle) {
	
	
	assert(model);
	textureHandle_ = textureHandle;

	worldtransform_.rotation_ = {0.0f, 0.0f, 0.0f};
	
	worldtransform_.scale_ = {2.0f, 2.0f, 2.0f};

	worldtransform_.translation_ = {0.0f, 2.0f, 0.0f};

	worldtransform_.Initialize();
	input_ = Input::GetInstance();




}

void Player::Update()
{

	Vector3 move = {0, 0, 0};

	const float kCharacterSpeed = 0.2f;
	// �����������ňړ��x�N�g����ύX

	if (input_->PushKey(DIK_LEFT)) {
		move.x -= kCharacterSpeed;
	} else if (input_->PushKey(DIK_RIGHT)) {
		move.x += kCharacterSpeed;
	}

	if (input_->PushKey(DIK_UP)) {
		move.y += kCharacterSpeed;
	} else if (input_->PushKey(DIK_DOWN)) {
		move.y -= kCharacterSpeed;
	}

	// ��]����[���W�A��/frane]
	const float kRotspeed = 0.02f;

	// �����������ňړ��x�N�g����ύX

	if (input_->PushKey(DIK_A)) {
		worldtransform_.rotation_.y -= kRotspeed;
	}
	if (input_->PushKey(DIK_D)) {
		worldtransform_.rotation_.y += kRotspeed;
	}


	
	XINPUT_STATE joyState;
	if (Input::GetInstance()->GetJoystickState(0, joyState)) {

		// ����
		const float speed = 0.3f;

		// �ړ���
		move = {
		    (float)joyState.Gamepad.sThumbLX / SHRT_MAX * kCharacterSpeed, 0.0f,
		    (float)joyState.Gamepad.sThumbLY / SHRT_MAX * kCharacterSpeed};

		Normalize(move);
		Multiply2(speed, move);

		worldtransform_.translation_ = Add(worldtransform_.translation_, move);
	}

	worldtransform_.UpdateMatrix();
	 

}

void Player::Draw(ViewProjection& viewprojection) 
{
	model_->Draw(worldtransform_, viewprojection, textureHandle_);


}
