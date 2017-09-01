//2015004011

#include <iostream>
#include "minimal_fighter.h"

MinimalFighter::MinimalFighter()
{
    this->mHp=0;
    this->mPower=0;
    this->mStatus=Invalid;
}

MinimalFighter::MinimalFighter(int _hp,int _power)
{
    this->mHp=_hp;
    this->mPower = _power;
    if(this->mHp >0)
    {
        this->mStatus = Alive;
    }
    else
    {
        this->mStatus = Dead;
    }
    
}

int MinimalFighter::hp() const
{
    return this->mHp;
}

int MinimalFighter::power() const
{
    return this->mPower;
}

FighterStatus MinimalFighter::status() const
{
    return this->mStatus;
}

void MinimalFighter::setHp(int _hp)
{
    this->mHp=_hp;
    if(_hp>0) mStatus = Alive;
    else mStatus = Dead; ////////
}

void MinimalFighter::hit(MinimalFighter *_enemy)
{
    
    int ehp = _enemy->hp();
    int epower = _enemy->power();
    if(this->mHp<=0 || ehp<=0) return;

    setHp(mHp - epower);
    _enemy->setHp(ehp - mPower);
    /*
    this->mHp -= epower;
    ehp -= this->mPower;
    
    _enemy->setHp(ehp);
    if(ehp<=0) _enemy->mStatus =Dead;
    if(this->mHp<=0) this->mStatus =Dead;
    */
}

void MinimalFighter::attack(MinimalFighter *_enemy)
{
    if(this->mHp<=0) return;
    /*int ehp = _enemy->hp();
    ehp -= this->mPower;
    */
    _enemy->setHp(_enemy->mHp - mPower);
    this->mPower = 0;
    // if(ehp<=0) _enemy->mStatus =Dead;d
}

void MinimalFighter::fight(MinimalFighter *_enemy)
{
    int ehp = _enemy->hp();
    int epower = _enemy->power();
    if(this->mHp<=0 || ehp<=0) return;

    while(_enemy->mHp>0 && this->mHp>0)
    {
        hit(_enemy);
        // this->mHp -= epower;
        // ehp -= this->mPower;
    }
    // if(ehp<=0) _enemy->mStatus =Dead;
    // if(this->mHp<=0) this->mStatus =Dead;
}