#pragma once
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
/*
 * This file was generated with makeClass. Edit only those parts of the code inside
 * of 'EXISTING_CODE' tags.
 */
#include <vector>
#include "transferfrom.h"

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
class QFromTransferFrom : public QTransferFrom {
public:
    SFAddress whop;
    SFAddress werp;

public:
    QFromTransferFrom(void);
    QFromTransferFrom(const QFromTransferFrom& fr);
    virtual ~QFromTransferFrom(void);
    QFromTransferFrom& operator=(const QFromTransferFrom& fr);

    DECLARE_NODE(QFromTransferFrom);

    // EXISTING_CODE
    // EXISTING_CODE
    friend bool operator<(const QFromTransferFrom& v1, const QFromTransferFrom& v2);
    friend ostream& operator<<(ostream& os, const QFromTransferFrom& item);

protected:
    void clear(void);
    void initialize(void);
    void duplicate(const QFromTransferFrom& fr);
    bool readBackLevel(SFArchive& archive) override;

    // EXISTING_CODE
    // EXISTING_CODE
};

//--------------------------------------------------------------------------
inline QFromTransferFrom::QFromTransferFrom(void) {
    initialize();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline QFromTransferFrom::QFromTransferFrom(const QFromTransferFrom& fr) {
    // EXISTING_CODE
    // EXISTING_CODE
    duplicate(fr);
}

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
inline QFromTransferFrom::~QFromTransferFrom(void) {
    clear();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void QFromTransferFrom::clear(void) {
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void QFromTransferFrom::initialize(void) {
    QTransferFrom::initialize();

    whop = "";
    werp = "";

    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void QFromTransferFrom::duplicate(const QFromTransferFrom& fr) {
    clear();
    QTransferFrom::duplicate(fr);

    whop = fr.whop;
    werp = fr.werp;

    // EXISTING_CODE
    // EXISTING_CODE
    finishParse();
}

//--------------------------------------------------------------------------
inline QFromTransferFrom& QFromTransferFrom::operator=(const QFromTransferFrom& fr) {
    duplicate(fr);
    // EXISTING_CODE
    // EXISTING_CODE
    return *this;
}

//-------------------------------------------------------------------------
inline bool operator<(const QFromTransferFrom& v1, const QFromTransferFrom& v2) {
    // EXISTING_CODE
    // EXISTING_CODE
    // No default sort defined in class definition, assume already sorted
    return true;
}

//---------------------------------------------------------------------------
typedef vector<QFromTransferFrom> QFromTransferFromArray;
extern SFArchive& operator>>(SFArchive& archive, QFromTransferFromArray& array);
extern SFArchive& operator<<(SFArchive& archive, const QFromTransferFromArray& array);

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE

