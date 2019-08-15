/**
 * @file
 *
 * @author CCHyper
 * @author OmniBlade
 *
 * @brief Straw interface for caching reads from other straws.
 *
 * @copyright Thyme is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#pragma once

#include "always.h"
#include "buffer.h"
#include "straw.h"

class CacheStraw : public Straw
{
public:
    CacheStraw(int length) : Straw(), m_buffer(length), m_index(0), m_length(0) {}
    CacheStraw(void *buffer, int length) : Straw(), m_buffer(buffer, length), m_index(0), m_length(0) {}
    CacheStraw(BufferClass &buffer) : Straw(), m_buffer(buffer), m_index(0), m_length(0) {}

    virtual ~CacheStraw() {}
    virtual int Get(void *source, int slen);

    bool Is_Valid() const { return m_buffer.Is_Valid(); }

protected:
    BufferClass m_buffer;
    int m_index;
    int m_length;
};
