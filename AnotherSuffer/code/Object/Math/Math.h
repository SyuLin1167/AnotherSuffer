#pragma once
#include<DxLib.h>

namespace math
{
    /// <summary>
    /// 角度からラジアンへの変換
    /// </summary>
    /// <param name="degre">:角度</param>
    /// <returns>変換後のラジアン角</returns>
    template <typename T> float DegToRad(T degre)
    {
        return degre * DX_PI_F / 180.0f;
    }

    /// <summary>
    /// ラジアンから角度への変換
    /// </summary>
    /// <param name="rad">:</param>
    /// <returns>変換後の角度</returns>
    template <typename T> float RadToDeg(T rad)
    {
        return rad * 180.0f / DX_PI_F;
    }

    /// <summary>
    /// ベクトルの相似判定
    /// </summary>
    /// <param name="lhs">:左辺ベクトル</param>
    /// <param name="rhs">:右辺ベクトル</param>
    /// <returns>ベクトルの一致:true|不一致:false</returns>
    bool operator==(const VECTOR& lhs, const VECTOR& rhs);
};