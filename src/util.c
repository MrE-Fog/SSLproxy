/*-
 * SSLsplit - transparent SSL/TLS interception
 * https://www.roe.ch/SSLsplit
 *
 * Copyright (c) 2009-2019, Daniel Roethlisberger <daniel@roe.ch>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <string.h>

/*
 * Various utility functions.
 */

/*
 * Returns a pointer to the first non-whitespace character in s.
 * Only space and tab characters are considered whitespace.
 */
char *
util_skipws(const char *s)
{
	return (char*) s + strspn(s, " \t");
}

/*
 * Returns the length of the first word in a given memory area.
 * Memory area may not be null-terminated, hence we cannot use string
 * manipulation functions.
 */
size_t
util_get_first_word_len(char *mem, size_t size)
{
	char *end;
	// @attention The detection order of ws chars is important: space, tab, cr, and nl
	if ((end = memchr(mem, ' ', size)) ||
			(end = memchr(mem, '\t', size)) ||
			(end = memchr(mem, '\r', size)) ||
			(end = memchr(mem, '\n', size)) ||
			(end = memchr(mem, '\0', size))) {
		return (size_t)(end - mem);
	}
	return size;
}

/* vim: set noet ft=c: */
