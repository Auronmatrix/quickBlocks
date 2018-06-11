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
#include "basetypes.h"

namespace qblocks {

    //--------------------------------------------------------------------
#define NOPOS ((size_t)-1)

    //--------------------------------------------------------------------
    //#define NATIVE
#ifndef NATIVE
    class string_q {
    private:
        string_q  (long) {};
        string_q  (unsigned long) {};
        const string_q& operator=(long);

    protected:
        char  *m_Values;
        size_t m_nValues;
        size_t m_buffSize;

    public:
        string_q(void);
        string_q(const string_q& str);
        string_q(char ch, size_t reps=1);
        string_q(const char *str, size_t start=0, size_t len=NOPOS);
        ~string_q(void);

        void     clear    (void);
        size_t   length   (void) const;
        size_t   size     (void) const { return length(); }
        int      compare  (const char* s) const;
        int      compare  (size_t pos, size_t len, const char* s) const;
        int      compare  (size_t pos, size_t len, const char* s, size_t n) const;
        int      compare  (const string_q& str) const;
        int      compare  (size_t pos, size_t len, const string_q& str) const;
        int      compare  (size_t pos, size_t len, const string_q& str, size_t subpos, size_t sublen) const;
        void     reserve  (size_t n=0);
        void     resize   (size_t n) { resize(n, '\0'); }
        void     resize   (size_t n, char c);
        bool     empty    (void) const;
        size_t   find     (const string_q& str, size_t pos=0) const;
        size_t   find     (const char* s, size_t pos=0) const;
        size_t   find     (const char* s, size_t pos, size_t n) const;
        size_t   find     (char c, size_t pos=0) const;
        size_t   findI    (const string_q& str, size_t pos=0) const;
        string_q extract  (size_t first, size_t len) const;

        char          operator[](size_t index) const;
        char          operator[](int index) const { return at((size_t)index); };

        const char&   at        (size_t index) const;
        const char   *c_str     (void) const;
        const string  str       (void) const { return string(c_str()); };

              size_t  rfind     (char ch) const;

        friend bool   operator==(const string_q& str1, const string_q& str2);
        friend bool   operator==(const string_q& str1, const char *str2);
        friend bool   operator==(const char *str1, const string_q& str2);

        friend bool   operator!=(const string_q& str1, const string_q& str2);
        friend bool   operator!=(const string_q& str1, const char *str2);
        friend bool   operator!=(const char *str1, const string_q& str2);

        friend bool   operator< (const string_q& str1, const string_q& str2);
        friend bool   operator< (const string_q& str1, const char *str2);
        friend bool   operator< (const char *str1, const string_q& str2);

        friend bool   operator<=(const string_q& str1, const string_q& str2);
        friend bool   operator<=(const string_q& str1, const char *str2);
        friend bool   operator<=(const char *str1, const string_q& str2);

        friend bool   operator> (const string_q& str1, const string_q& str2);
        friend bool   operator> (const string_q& str1, const char *str2);
        friend bool   operator> (const char *str1, const string_q& str2);

        friend bool   operator>=(const string_q& str1, const string_q& str2);
        friend bool   operator>=(const string_q& str1, const char *str2);
        friend bool   operator>=(const char *str1, const string_q& str2);

        //----------------------------------------------------------------------------------------------------
        friend ostream& operator<<(ostream &os, const string_q& x) {
            os << x.m_Values;
            return os;
        }

        friend void replace       (string_q& target, const string_q& what, const string_q& with);
        friend void replaceAll    (string_q& target, const string_q& what, const string_q& with);
        friend void replaceAny    (string_q& target, const string_q& list, const string_q& with);
        friend void replaceReverse(string_q& target, const string_q& what, const string_q& with);
        friend void reverse       (string_q& target);

    protected:
        void    init      (void);
    };

    //--------------------------------------------------------------------
    inline bool operator==(const string_q& str1, const string_q& str2) {
        return str1.compare(str2.m_Values) == 0;
    }

    //--------------------------------------------------------------------
    inline bool operator==(const string_q& str1, const char *str2) {
        return str1.compare(str2) == 0;
    }

    //--------------------------------------------------------------------
    inline bool operator==(const char *str1, const string_q& str2) {
        return str2.compare(str1) == 0;
    }

    //--------------------------------------------------------------------
    inline bool operator!=(const string_q& str1, const string_q& str2) {
        return str1.compare(str2.m_Values) != 0;
    }

    //--------------------------------------------------------------------
    inline bool operator!=(const string_q& str1, const char *str2) {
        return str1.compare(str2) != 0;
    }

    //--------------------------------------------------------------------
    inline bool operator!=(const char *str1, const string_q& str2) {
        return str2.compare(str1) != 0;
    }

    //--------------------------------------------------------------------
    inline bool operator<(const string_q& str1, const string_q& str2) {
        return str1.compare(str2.m_Values) < 0;
    }

    //--------------------------------------------------------------------
    inline bool operator<(const string_q& str1, const char *str2) {
        return str1.compare(str2) < 0;
    }

    //--------------------------------------------------------------------
    inline bool operator<(const char *str1, const string_q& str2) {
        return str2.compare(str1) > 0;
    }

    //--------------------------------------------------------------------
    inline bool operator>(const string_q& str1, const string_q& str2) {
        return str1.compare(str2.m_Values) > 0;
    }

    //--------------------------------------------------------------------
    inline bool operator>(const string_q& str1, const char *str2) {
        return str1.compare(str2) > 0;
    }

    //--------------------------------------------------------------------
    inline bool operator>(const char *str1, const string_q& str2) {
        return str2.compare(str1) < 0;
    }

    //--------------------------------------------------------------------
    inline bool operator<=(const string_q& str1, const string_q& str2) {
        return str1.compare(str2.m_Values) <= 0;
    }

    //--------------------------------------------------------------------
    inline bool operator<=(const string_q& str1, const char *str2) {
        return str1.compare(str2) <= 0;
    }

    //--------------------------------------------------------------------
    inline bool operator<=(const char *str1, const string_q& str2) {
        return str2.compare(str1) >= 0;
    }

    //--------------------------------------------------------------------
    inline bool operator>=(const string_q& str1, const string_q& str2) {
        return str1.compare(str2.m_Values) >= 0;
    }

    //--------------------------------------------------------------------
    inline bool operator>=(const string_q& str1, const char *str2) {
        return str1.compare(str2) >= 0;
    }

    //--------------------------------------------------------------------
    inline bool operator>=(const char *str1, const string_q& str2) {
        return str2.compare(str1) <= 0;
    }

    //--------------------------------------------------------------------
    inline string_q operator+(const string_q& str1, const string_q& str2) {
#if 1
        string s1 = str1.c_str();
        string s2 = str2.c_str();
        return (s1 + s2).c_str();
#else
        size_t newLen = str1.length() + str2.length();
        string_q ret;
        ret.reserve(newLen);
        memcpy(ret.m_Values, str1.m_Values, str1.length());
        memcpy(ret.m_Values + str1.length(), str2.m_Values, str2.length());
        ret.m_nValues = newLen;
        ret.m_Values[newLen] = '\0';
        return ret;
#endif
    }

    //--------------------------------------------------------------------
    inline bool operator%(const string_q& str1, const string_q& str2) {
        return !strcasecmp(str1.c_str(), str2.c_str());
    }

    //--------------------------------------------------------------------
    inline bool operator%(const string_q& str1, const char *str2) {
        return !strcasecmp(str1.c_str(), str2);
    }

    //--------------------------------------------------------------------
    inline bool operator%(const char *str1, const string_q& str2) {
        return !strcasecmp(str1, str2.c_str());
    }

    //--------------------------------------------------------------------
    inline bool operator%(const string_q& str1, char ch) {
        return !strcasecmp(str1.c_str(), string_q(ch).c_str());
    }

    //--------------------------------------------------------------------
    inline bool operator%(char ch, const string_q& str2) {
        return !strcasecmp(string_q(ch).c_str(), str2.c_str());
    }

#else
#define string_q std::string
#endif

    //--------------------------------------------------------------------
    extern size_t  countOf        (const string_q& haystack, char needle);
    extern bool    endsWith       (const string_q& haystack, const string_q& needle);
    extern bool    startsWith     (const string_q& haystack, const string_q& needle);
    extern bool    endsWithAny    (const string_q& haystack, const string_q& needle);
    extern bool    startsWithAny  (const string_q& haystack, const string_q& needle);
    extern bool    contains       (const string_q& haystack, const string_q& needle);
    extern bool    containsI      (const string_q& haystack, const string_q& needle);

    //--------------------------------------------------------------------
    extern string_q toLower       (const string_q& in);
    extern string_q toUpper       (const string_q& in);
    extern string_q toProper      (const string_q& in);

    //--------------------------------------------------------------------
//    extern string_q padRight      (const string_q& str, size_t len, char p=' ');
//    extern string_q padLeft       (const string_q& str, size_t len, char p=' ');
//    extern string_q padCenter     (const string_q& str, size_t len, char p=' ');

    //--------------------------------------------------------------------
    extern string_q trim          (const string_q& str, char c = ' ');
    extern string_q trimTrailing  (const string_q& str, char c = ' ');
    extern string_q trimLeading   (const string_q& str, char c = ' ');
    extern string_q trimWhitespace(const string_q& str, const string_q& add="");

    //--------------------------------------------------------------------
    class SFString : public string_q {
        SFString  (long) {};
        SFString  (unsigned long) {};
        const SFString& operator=(long);
    public:
        SFString  (void);
        SFString  (const SFString& str);
        SFString  (char ch, size_t reps=1);
        SFString  (const char *str, size_t start=0, size_t len=NOPOS);

        ~SFString (void);

        const SFString& operator=     (const SFString& str);
        const SFString& operator+=    (const SFString& str);
//        const SFString& operator+=    (char ch);
        const SFString& operator+=    (const char *str);

        friend SFString operator+(const SFString& str1, const SFString& str2);
        friend SFString operator+(const SFString& str1, const char *str2);

        SFString substr          (size_t first, size_t len) const;
        SFString substr          (size_t first) const;
        SFString Substitute      (const SFString& what, const SFString& with) const;
    };

    //---------------------------------------------------------------------------------------
    inline SFString operator+(const SFString& str1, const SFString& str2) {
        size_t newLen = str1.length() + str2.length();
        SFString ret;
        ret.reserve(newLen);
        memcpy(ret.m_Values, str1.m_Values, str1.length());
        memcpy(ret.m_Values+str1.length(), str2.m_Values, str2.length());
        ret.m_nValues = newLen;
        ret.m_Values[newLen] = '\0';
        return ret;
    }

    //---------------------------------------------------------------------------------------
    inline const SFString& SFString::operator+=(const SFString& add) {
        if (add.length())
            *this = (*this + add);
        return *this;
    }

    //--------------------------------------------------------------------
    inline const SFString& SFString::operator+=(const char *str) {
        return operator+=(SFString(str));
    }

//    //--------------------------------------------------------------------
//    inline const SFString& SFString::operator+=(char ch) {
//        return operator+=(SFString(ch));
//    }

    //--------------------------------------------------------------------
    inline SFString operator+(const SFString& str1, const char *str2) {
        return operator+(str1, SFString(str2));
    }

    //--------------------------------------------------------------------
    inline SFString operator+(const char *str1, const SFString& str2) {
        return operator+(SFString(str1), str2);
    }

    //--------------------------------------------------------------------
    inline SFString operator+(const SFString& str,  char ch) {
        return operator+(str, SFString(ch));
    }

    //--------------------------------------------------------------------
    extern SFString nextTokenClearReverse(SFString& str, char token);
    inline SFString nextTokenClear(SFString& line, char delim, bool doClear=true) {
        SFString ret;

        size_t find = line.find(delim);
        if (find!=NOPOS) {
            ret  = line.substr(0,find);
            line = line.substr(find+1);

        } else if (!line.empty()) {
            ret  = line;
            if (doClear)
                line = "";
        }
        return ret;
    }

    //--------------------------------------------------------------------
#define EMPTY SFString("")

    extern SFString snagFieldClear(      SFString& in, const SFString& tagName, const SFString& defVal="");
    extern SFString snagField     (const SFString& in, const SFString& tagName, const SFString& defVal="");

    //--------------------------------------------------------------------
    extern SFString toLower       (const SFString& in);
    extern SFString toUpper       (const SFString& in);
    extern SFString toProper      (const SFString& in);

    //--------------------------------------------------------------------
    extern SFString padRight      (const SFString& str, size_t len, char p=' ');
    extern SFString padLeft       (const SFString& str, size_t len, char p=' ');
    extern SFString padCenter     (const SFString& str, size_t len, char p=' ');

    //--------------------------------------------------------------------
    extern SFString trim          (const SFString& str, char c = ' ');
    extern SFString trimTrailing  (const SFString& str, char c = ' ');
    extern SFString trimLeading   (const SFString& str, char c = ' ');
    extern SFString trimWhitespace(const SFString& str, const SFString& add="");

}  // namespace qblocks
