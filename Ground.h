#pragma once
#include <Model.h>
#include <WorldTransform.h>

class Ground
{
public:
	void Initialize(Model* model);

	void Update();

	void Draw(ViewProjection& viewProjection);

private:

	//���[���h�ύX�f�[�^
	WorldTransform worldtransform_;

	//���f��
	Model* model_ = nullptr;

	ViewProjection* viewprojection_;



};
