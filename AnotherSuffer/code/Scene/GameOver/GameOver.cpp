#include "GameOver.h"
#include"../../KeyStatus/KeyStatus.h"
#include"../Title/Title.h"

GameOver::GameOver()
    :SceneBase(SceneTag.GAMEOVER)
{

}

GameOver::~GameOver()
{
    //�����Ȃ�
}

SceneBase* GameOver::UpdateScene(const float deltaTime)
{
    if (KeyStatus::KeyStateDecision(KEY_INPUT_SPACE, (ONINPUT | NOWONINPUT)))
    {
        return new Title;
    }
    return  this;
}

void GameOver::DrawScene()
{

}