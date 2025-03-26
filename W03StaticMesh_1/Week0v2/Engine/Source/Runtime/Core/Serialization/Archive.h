#pragma once
#include "HAL/PlatformType.h"


class FArchive {
public:
    virtual ~FArchive() = default;
    
    virtual void Serialize(void* Data, int64 Size) = 0;
    virtual bool IsLoading() const = 0;
    virtual bool IsSaving() const = 0;
    
    // 플랫폼 엔디안 처리
    virtual void SetByteSwapping(bool bInSwap) { bSwapBytes = bInSwap; }
    
protected:
    bool bSwapBytes = false;
};

