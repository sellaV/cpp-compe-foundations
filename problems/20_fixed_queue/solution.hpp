#pragma once

class FixedQueue {
int data_[8]{};
int head_=0,count_=0;
public:
    bool push(int value) {if(count_==8)return false;data_[(head_+count_)%8]=value;++count_;return true;}
    bool pop(int& output) {if(count_==0)return false;output=data_[head_];head_=(head_+1)%8;--count_;return true;}
    int size() const {return count_;}
};
