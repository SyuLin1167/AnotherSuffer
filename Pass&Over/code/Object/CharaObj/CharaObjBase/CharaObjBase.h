#pragma once

/*CharaObjBase�N���X*/
class CharaObjBase:public ObjBase
{
public:
    CharaObjBase();
    ~CharaObjBase();

protected:
    void Update(const float& deltaTime)override;

};

