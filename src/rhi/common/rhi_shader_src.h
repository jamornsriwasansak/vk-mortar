#pragma once

#include "pch/pch.h"

#include "core/file.h"
#include "rhi_enums.h"

namespace Rhi
{
template <typename ShaderStageEnum>
struct TShaderSrc
{
    std::filesystem::path    m_file_path = "";
    std::string              m_entry     = "";
    std::vector<std::string> m_defines;
    ShaderStageEnum          m_shader_stage;

    TShaderSrc() {}

    TShaderSrc(const ShaderStageEnum            shader_stage,
               const std::filesystem::path &    path    = "",
               const std::string &              entry   = "",
               const std::vector<std::string> & defines = {})
    : m_shader_stage(shader_stage), m_file_path(path), m_entry(entry), m_defines(defines)
    {
    }

    TShaderSrc &
    set_file_path(const std::filesystem::path & path)
    {
        m_file_path = path;
        return *this;
    }

    TShaderSrc &
    set_entry(const std::string & entry)
    {
        m_entry = entry;
        return *this;
    }

    std::string
    source() const
    {
        return File::LoadFile(m_file_path.c_str());
    }
};
} // namespace Rhi