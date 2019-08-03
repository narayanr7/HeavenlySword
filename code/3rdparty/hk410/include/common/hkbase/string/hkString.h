/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok).  Not for disclosure or distribution without Havok's
 * prior written consent.This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2006 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

#ifndef HKBASE_HKSTRING_H
#define HKBASE_HKSTRING_H

#define HK_INT_MAX int(unsigned(-1)>>1)

/// String and buffer functions normally found in libc.
class hkString
{
	public:

		HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR(HK_MEMORY_CLASS_STRING, hkString);
		struct Rep
		{
			HK_FORCE_INLINE char* getData();
			HK_FORCE_INLINE const char* getData() const;
			HK_FORCE_INLINE char* refCopy();
			HK_FORCE_INLINE int getSize() const;
			HK_FORCE_INLINE void unRef();
			void freeMemory();
			Rep* clone() const;
			static Rep* HK_CALL create(int slen);
			int m_length;
			int m_capacity;
			int	m_references;
		};

	public: // object methods

			/// Creates an empty string.
		hkString();

			/// Creates a new string as a copy from a null terminated character array.
		hkString(const char* s);

			/// Creates a new string as a copy from a buffer of length len.
			/// The copied string will automatically be null terminated.
		hkString(const char* b, int len);

			/// Creates a new string as a copy of an existing one.
		hkString(const hkString& s);

			/// Copy of an existing string.
		hkString& operator=(const hkString& s);

			/// Copy of an existing c string.
		hkString& operator=(const char* s);

			/// Destroys this string.
		~hkString();

			/// Read only access the i'th character.
		char operator[] (int i) const;

			/// Overwrite the current value. Arguments are the same as for ::sprintf.
		void printf(const char* format, ...); // member function, not HK_CALL
	
			/// Returns the first index of c given range, or -1 if not found.
		int indexOf (char c, int startIndex=0, int endIndex=HK_INT_MAX) const;

			/// Returns the last index of c, or -1 if not found.
		int lastIndexOf (char c, int startIndex=0, int endIndex=HK_INT_MAX) const;

			/// Read only access the internal buffer.
		const char* cString() const;

			// overload each comparison for char* to avoid creating temporary string objects.

			/// Returns <0,0,>0 if *this is lexicographically less than, equal to or greater than other.
		int compareTo(const hkString& other) const;

			/// Returns <0,0,>0 if *this is lexicographically less than, equal to or greater than other.
		int compareTo(const char* other) const;

			/// Returns <0,0,>0 if *this is lexicographically less than, equal to or greater than other, ignoring case.
		int compareToIgnoreCase(const hkString& other) const;

			/// Returns <0,0,>0 if *this is lexicographically less than, equal to or greater than other, ignoring case.
		int compareToIgnoreCase(const char* other) const;
	
			/// Convenience operator for use in map<>
		hkBool operator< (const hkString& s) const;

			/// Returns compareTo(s)==0
		hkBool operator== (const hkString& s) const;

			/// Returns compareTo(s)!=0
		hkBool operator!= (const hkString& s) const;

			/// Returns compareTo(s)==0
		hkBool operator== (const char* s) const;

			/// Returns compareTo(s)!=0
		hkBool operator!= (const char* s) const;

			/// Does this string begin with s?
		hkBool beginsWith(const hkString& s) const;

			/// Does this string begin with s?
		hkBool beginsWith(const char* s) const;

			/// Does this string end with s?
		hkBool endsWith(const hkString& s) const;

			/// Does this string end with s?
		hkBool endsWith(const char* s) const;

			/// Returns the concatenation of *this and other.
		hkString operator+ (const hkString& other) const;

			/// Returns the concatenation of *this and other.
		hkString operator+ (const char* other) const;

			/// Sets *this as the concatenation of *this and other.
		hkString& operator+= (const hkString& other);

			/// Sets *this as the concatenation of *this and other.
		hkString& operator+= (const char* other);


			/// Returns the number of characters in this string excluding the trailing NULL
		int getLength() const;

			/// Parameter to hkString::replace functions
		enum ReplaceType
		{
			REPLACE_ONE,
			REPLACE_ALL
		};

			/// Replaces all occurrences of 'from' with 'to'.
		hkString replace(char from, char to, ReplaceType=REPLACE_ALL) const;

			/// Replaces all occurrences of 'from' with 'to'.
		hkString replace(const hkString& from, const hkString& to, ReplaceType=REPLACE_ALL) const;

			/// Returns a copy of the string as lower case.
		hkString asUpperCase() const;

			/// Returns a copy of the string as upper case.
		hkString asLowerCase() const;

			/// Returns a copy of the substring from the index onward.
			/// The index begins at 0.
		hkString substr(int index, int maxChars=HK_INT_MAX) const;

	private:

		explicit hkString(Rep* r);
		Rep& getRep() const;
		char* m_string;
		static char s_emptyStringRep[ sizeof(int)+sizeof(int)+sizeof(int)+sizeof(char) ];
		static Rep& HK_CALL getEmptyStringRep();

	public: // static methods

			/// Return the upper case of character c
		static char HK_CALL toUpper( char c );
			/// Return the lower case of character c
		static char HK_CALL toLower( char c );

			/// Equivalent to sprintf except at most n characters are written.
		static int HK_CALL snprintf(char* buf, int n, const char* fmt, ...);
			/// Equivalent to snprintf, but with a va_list of arguments.
		static int HK_CALL vsnprintf(char* buf, int len, const char* fmt, hk_va_list hkargs);
			/// Printf formatting to a string buffer.
		static int HK_CALL sprintf(char* buf, const char* fmt, ...);

			/// Returns <=1,0,>=1 if s1 is lexicographically less than, equal to or greater than s2.
		static int HK_CALL strCmp(const char* s1, const char* s2 );
			/// Returns <=1,0,>=1 if s1 is lexicographically less than, equal to or greater than s2. Comparison is done using at most the first n characters.
		static int HK_CALL strNcmp(const char* s1, const char* s2, int n);
			/// Returns <=1,0,>=1 if s1 is lexicographically less than, equal to or greater than s2, ignoring case.
		static int HK_CALL strCasecmp(const char* s1, const char* s2 );
			/// Returns <=1,0,>=1 if s1 is lexicographically less than, equal to or greater than s2, ignoring case. Comparison is done using at most the first n characters.
		static int HK_CALL strNcasecmp(const char* s1, const char* s2, int n);
			/// Copy null terminated src into dst. dst must be large enough to hold src.
		static void HK_CALL strCpy(char* dst, const char* src);
			/// Copy at most n characters of null terminated src into dst. dst must be large enough to hold src.
		static void HK_CALL strNcpy(char* dst, const char* src, int n);
			/// Return the length of null terminated string src.
		static int HK_CALL strLen(const char* src);

			/// Return an integer representing the string (signed, undefined for invalid input)
		static int HK_CALL atoi(const char* in);

			/// Return a hkReal representing the string.
		static hkReal HK_CALL atof(const char* in); 

			/// Return the first occurrence of needle in haystack or null if not found.
		static const char* HK_CALL strStr(const char* haystack, const char* needle);

			/// Return the first occurrence of needle in haystack or null if not found.
		static const char* HK_CALL strChr(const char* haystack, int needle);
			/// Return the last occurrence of needle in haystack or null if not found.
		static const char* HK_CALL strRchr(const char* haystack, int needle);

			/// Return a copy of string src. This copy is allocated using hkAllocate<char> and therefore it should be deallocated using hkDeallocate<char>
		static char* HK_CALL strDup(const char* src);
			/// Return a copy of at most maxlen characters of src.
		static char* HK_CALL strNdup(const char* src, int maxlen);
			/// Change src to lower case in place.
		static char* HK_CALL strLwr(char* src);
			/// Change src to upper case in place.
		static char* HK_CALL strUpr(char* src);

			/// Copy n bytes of src into dst.
		static void HK_CALL memCpy(void* dst, const void* src, int n);
			/// Copy n quad words of src into dst.
		static HK_FORCE_INLINE void HK_CALL memCpy4(void* dst, const void* src, int numWords);
			/// Copy n quad words of src into dst.
		static HK_FORCE_INLINE void HK_CALL memCpy16(void* dst, const void* src, int numQuads);
			/// Copy n bytes of src into dst, possibly overlapping.
		static void HK_CALL memMove(void* dst, const void* src, int n);
			/// Set n bytes of dst to c.
		static void HK_CALL memSet(void* dst, const int c, int n);
			/// Returns <=1,0,>=1 if n bytes of buf1 is less than, equal to or greater than those of buf2.
		static int HK_CALL memCmp(const void* buf1, const void* buf2, int n);

};

#if defined(HK_PLATFORM_WIN32) || defined(HK_PLATFORM_XBOX) || defined(HK_PLATFORM_XBOX360)
#	define HK_PRINTF_FORMAT_INT64 "%I64i"
#	define HK_PRINTF_FORMAT_UINT64 "%I64u"
#else
#	define HK_PRINTF_FORMAT_INT64 "%lli"
#	define HK_PRINTF_FORMAT_UINT64 "%llu"
#endif

#if HK_POINTER_SIZE==4
#	define HK_PRINTF_FORMAT_ULONG "%u"
#else
#	define HK_PRINTF_FORMAT_ULONG HK_PRINTF_FORMAT_UINT64
#endif

#undef HK_INT_MAX

#include <hkbase/string/hkString.inl>

#endif // HKBASE_HKSTRING_H

/*
* Havok SDK - PUBLIC RELEASE, BUILD(#20060902)
*
* Confidential Information of Havok.  (C) Copyright 1999-2006 
* Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok
* Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership
* rights, and intellectual property rights in the Havok software remain in
* Havok and/or its suppliers.
*
* Use of this software for evaluation purposes is subject to and indicates 
* acceptance of the End User licence Agreement for this product. A copy of 
* the license is included with this software and is also available from salesteam@havok.com.
*
*/