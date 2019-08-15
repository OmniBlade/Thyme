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
#include "cachestraw.h"
#include <algorithm>
#include <cstring>

using std::memmove;

int CacheStraw::Get(void *source, int slen)
{
    int total = 0;

    if (!m_buffer.Get_Buffer() || !source || slen <= 0) {
        return total;
    }

    while (slen > 0) {
        if (m_length > 0) {
            // How much data to read into destination buffer?
            int readlen = std::min(slen, m_length);

            // Move from our cache buffer to destination
            memmove(source, (m_buffer.Get_Buffer() + m_index), readlen);

            // move our buffer positions and increase the total by the read amount
            m_index += readlen;
            total += readlen;
            source = static_cast<char *>(source) + readlen;

            // decrement the amount of data we have left in the cache and slen
            // left to fill in destination
            m_length -= readlen;
            slen -= readlen;
        }

        // If we have read requested amount to destination, exit loop
        if (!slen) {
            break;
        }

        // Read some more data from linked straw
        m_length = Straw::Get(m_buffer.Get_Buffer(), m_buffer.Get_Size());
        m_index = 0;

        // If we didn't get any more data, exit the loop
        if (!m_length) {
            break;
        }
    }

    return total;
}
