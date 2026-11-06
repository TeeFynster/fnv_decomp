#pragma once

#include <stdexcept>
#include <string>

class IdvFileError : public std::runtime_error
{
public:
    inline IdvFileError(const std::string& strMessage, bool bUseErrno = true);
};
