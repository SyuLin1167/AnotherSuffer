#pragma once

/*CharaObjBaseƒNƒ‰ƒX*/
class CharaObjBase:public ObjBase
{
public:
    CharaObjBase();
    ~CharaObjBase();

protected:
    void Update(const float& deltaTime)override;

};

