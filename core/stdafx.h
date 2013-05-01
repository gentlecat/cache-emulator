/*
	stdafx.h : include file for standard system include files,
	or project specific include files that are used frequently, but
	are changed infrequently
*/

#pragma once

#include <stdio.h>

// Use tchar only while building by MS Visual Studio
// Not required if build by Qt Creator under Linux
#ifdef _MSC_VER
#include <tchar.h>
#endif

#include <iostream>
#include <bitset>

#define WORD 32	// Word size
