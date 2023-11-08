#pragma once
#include <assert.h>
#include <ImGuiManager.h>
#include "Vector3.h"
#include "Matrix4x4.h"

Vector3 Add(const Vector3 v1, const Vector3& v2);


Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);


// �X�P�[�����O�s���錾
Matrix4x4 matScale(const Vector3 scale);


Matrix4x4 matRotX(float rotation);


Matrix4x4 matRotY(float rotation);

Matrix4x4 matRotZ(float rotation);

Matrix4x4 matRotXYZ(float rotationX, float rotationY, float rotationZ);

    // ���s�ړ��s���錾
 Matrix4x4 matTrans(const Vector3 translation);





Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate);