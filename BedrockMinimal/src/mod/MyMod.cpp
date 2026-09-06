#include "mod/MyMod.h"
namespace bedrock_minimal {
BedrockMinimalMod& BedrockMinimalMod::instance() {
    static BedrockMinimalMod mod;
    return mod;
}
BedrockMinimalMod::BedrockMinimalMod()
    : mSelf(*ll::mod::NativeMod::current()) {}
bool BedrockMinimalMod::load() {
    getSelf().getLogger().info("Bedrock Minimal loaded!");
    return true;
}
bool BedrockMinimalMod::enable() {
    getSelf().getLogger().info("Bedrock Minimal enabled!");
    return true;
}
bool BedrockMinimalMod::disable() {
    getSelf().getLogger().info("Bedrock Minimal disabled!");
    return true;
}
bool BedrockMinimalMod::unload() {
    getSelf().getLogger().info("Bedrock Minimal unloaded!");
    return true;
}
}
