#pragma once

class Vec2
{
public:
    // �����o�ϐ�
    float x; // x����
    float y; // y����

public:
    // �R���X�g���N�^
    Vec2();                            // ��x�N�g���Ƃ��Đ���
    Vec2(float x, float y);            // x,y�������w�肵�Ă̐���

    // �����o�֐�
    float Length() const;                // �m����(����)�����߂�
    Vec2& Normalize();                // ���K��
    float Dot(const Vec2& v) const;    // ���ς����߂�
    float Cross(const Vec2& v) const;// �O�ς����߂�

    // �P�����Z�q�I�[�o�[���[�h
    Vec2 operator+() const;
    Vec2 operator-() const;

    // ������Z�q�I�[�o�[���[�h
    Vec2& operator+=(const Vec2& v);
    Vec2& operator-=(const Vec2& v);
    Vec2& operator*=(float s);
    Vec2& operator/=(float s);
};

// 2�����Z�q�I�[�o�[���[�h
// �������Ȉ����̃p�^�[���ɑΉ����邽�߁A�ȉ��̂悤�ɏ������Ă���
const Vec2 operator+(const Vec2& v1, const Vec2& v2);
const Vec2 operator-(const Vec2& v1, const Vec2& v2);
const Vec2 operator*(const Vec2& v, float s);
const Vec2 operator*(float s, const Vec2& v);
const Vec2 operator/(const Vec2& v, float s);