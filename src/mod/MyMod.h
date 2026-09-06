#pragma once
#include <pl/Mod.hpp>
namespace bedrock_minimal {
class BedrockMinimalMod {
public:
    static BedrockMinimalMod& instance();
    BedrockMinimalMod();
    ll::mod::NativeMod& getSelf() const { return mSelf; }
    bool load();
    bool enable();
    bool disable();
    bool unload();
private:
    ll::mod::NativeMod& mSelf;
};
}
