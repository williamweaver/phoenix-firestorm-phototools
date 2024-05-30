/*
 * @file fsworldmapmessage.h
 */

#ifndef FS_WORLDMAPMESSAGE_H
#define FS_WORLDMAPMESSAGE_H

#include <cstdint>
#include <functional>
#include <string>
class LLMessageSystem;
class LLUUID;
bool hypergrid_sendExactNamedRegionRequest(
    std::string const& region_name,
    std::function<void(uint64_t region_handle, const std::string& url, const LLUUID& snapshot_id, bool teleport)> const& callback,
    std::string const& callback_url,
    bool teleport);
bool hypergrid_processExactNamedRegionResponse(LLMessageSystem* msg, uint32_t agent_flags);

#endif // FS_WORLDMAPMESSAGE_H
