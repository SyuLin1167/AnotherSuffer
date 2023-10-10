#pragma once
#include<tuple>

#include"../AssetBase/AssetBase.h"


/*Soundクラス*/
class Sound final:public AssetBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Sound();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Sound();


    /// <summary>
    /// ハンドル削除処理
    /// </summary>
    virtual void DeleteHandle() override;
private:
    /// <summary>
    /// ハンドル追加処理
    /// </summary>
    /// <param name="fileName">:ファイル名</param>
    void AddHandle(std::string fileName)override;

    /// <summary>
    /// サウンドパラメーター
    /// </summary>
    struct SoundParam
    {
        SoundParam();

        int volume;
        
    }soundParam;

    std::tuple<int, SoundParam> soundData;
};

