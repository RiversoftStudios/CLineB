/* SPDX-License-Identifier: GPL-3.0-or-later
 * SPDX-FileCopyrightText: Copyright (C) 2026 Riversoft Studios */

#if !defined(_CLineB___CLINEB_COMPILERS_H__)
#define _CLineB___CLINEB_COMPILERS_H__

#if defined(__GNUC__) || defined(__clang__)
#define ATTRIBUTE_NORETURN __attribute__((noreturn))
#elif defined(_MSC_VER)
#define ATTRIBUTE_NORETURN __declspec(noreturn)
#elif __STDC_VERSION__ >= 202311L
#define ATTRIBUTE_NORETURN [[noreturn]]
#elif __STDC_VERSION__ >= 201112L
#define ATTRIBUTE_NORETURN _Noreturn
#else
#define ATTRIBUTE_NORETURN
#endif

#if defined(__GNUC__) || defined(__clang__)
#define ATTRIBUTE_PACKED __attribute__((packed))
#else
#define ATTRIBUTE_PACKED
#endif

#if defined(__GNUC__) || defined(__clang__)
#define ATTRIBUTE_ALIGNED(x) __attribute__((aligned(x)))
#elif defined(_MSC_VER)
#define ATTRIBUTE_ALIGNED(x) __declspec(align(x))
#elif __STDC_VERSION__ >= 202311L
#define ATTRIBUTE_ALIGNED(x) alignas(x)
#elif __STDC_VERSION__ >= 201112L
#define ATTRIBUTE_ALIGNED(x) _Alignas(x)
#else
#define ATTRIBUTE_ALIGNED(x)
#endif

#if defined(__GNUC__) || defined(__clang__)
#define ATTRIBUTE_MALLOC(freefunc, arg) __attribute__((malloc(freefunc, arg)))
#else
#define ATTRIBUTE_MALLOC(freefunc, arg)
#endif

#endif
