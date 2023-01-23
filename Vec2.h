#pragma once

class Vec2
{
public:
    // メンバ変数
    float x; // x成分
    float y; // y成分

public:
    // コンストラクタ
    Vec2();                            // 零ベクトルとして生成
    Vec2(float x, float y);            // x,y成分を指定しての生成

    // メンバ関数
    float Length() const;                // ノルム(長さ)を求める
    Vec2& Normalize();                // 正規化
    float Dot(const Vec2& v) const;    // 内積を求める
    float Cross(const Vec2& v) const;// 外積を求める

    // 単項演算子オーバーロード
    Vec2 operator+() const;
    Vec2 operator-() const;

    // 代入演算子オーバーロード
    Vec2& operator+=(const Vec2& v);
    Vec2& operator-=(const Vec2& v);
    Vec2& operator*=(float s);
    Vec2& operator/=(float s);
};

// 2項演算子オーバーロード
// ※いろんな引数のパターンに対応するため、以下のように準備している
const Vec2 operator+(const Vec2& v1, const Vec2& v2);
const Vec2 operator-(const Vec2& v1, const Vec2& v2);
const Vec2 operator*(const Vec2& v, float s);
const Vec2 operator*(float s, const Vec2& v);
const Vec2 operator/(const Vec2& v, float s);