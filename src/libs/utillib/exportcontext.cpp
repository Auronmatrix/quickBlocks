/*-------------------------------------------------------------------------------------------
 * QuickBlocks - Decentralized, useful, and detailed data from Ethereum blockchains
 * Copyright (c) 2018 Great Hill Corporation (http://quickblocks.io)
 *
 * This program is free software: you may redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version. This program is
 * distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details. You should have received a copy of the GNU General
 * Public License along with this program. If not, see http://www.gnu.org/licenses/.
 *-------------------------------------------------------------------------------------------*/
#include "basetypes.h"

#include "exportcontext.h"
#include "conversions.h"

namespace qblocks {

    //-------------------------------------------------------------
    CExportContext::CExportContext(void) : tCh('\t') {
        nTabs = 0;
    }

    //-------------------------------------------------------------
    CExportContext& CExportContext::operator<<(bool b) {
        ostringstream os;
        os << b;
        Output(os.str().c_str());
        return *this;
    }

    //-------------------------------------------------------------
    CExportContext& CExportContext::operator<<(char c) {
        ostringstream os;
        os << c;
        Output(os.str().c_str());
        return *this;
    }

    //-------------------------------------------------------------
    CExportContext& CExportContext::operator<<(int64_t dw) {
        ostringstream os;
        os << dw;
        Output(os.str().c_str());
        return *this;
    }

    //-------------------------------------------------------------
    CExportContext& CExportContext::operator<<(uint64_t ul) {
        ostringstream os;
        os << ul;
        Output(os.str().c_str());
        return *this;
    }

    //-------------------------------------------------------------
    CExportContext& CExportContext::operator<<(uint32_t sz) {
        ostringstream os;
        os << sz;
        Output(os.str().c_str());
        return *this;
    }

    //-------------------------------------------------------------
    CExportContext& CExportContext::operator<<(int i) {
        ostringstream os;
        os << i;
        Output(os.str().c_str());
        return *this;
    }

    //-------------------------------------------------------------
    CExportContext& CExportContext::operator<<(float f) {
        string_q val = double2Str(f);
        Output(val);
        return *this;
    }

    //-------------------------------------------------------------
    CExportContext& CExportContext::operator<<(double f) {
        string_q val = double2Str(f);
        Output(val);
        return *this;
    }

    //-------------------------------------------------------------
    CExportContext& CExportContext::operator<<(const char *str) {
        Output(str);
        return *this;
    }

    //-------------------------------------------------------------
    CExportContext& CExportContext::operator<<(const string_q& str) {
        if (str.length() >= 3 && extract(str, 0, 2) == "`%" && str.at(2) != '%')
            fmt = extract(str, 1);
        else if (str == "%")
            fmt = "";
        else
            Output(str);
        return *this;
    }

    //-------------------------------------------------------------
    void CStringExportContext::setOutput(void *output) {
        // should not happen
        ASSERT(0);
    }

    void CStringExportContext::Output(const string_q& sss) {
        str += sss;
    }
}  // namespace qblocks
