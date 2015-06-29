#pragma once

#include "../GameTool/GameHeadConfig.h"

// ��ȡ�ļ����ݽӿ�
typedef uint8* (*GetFileDataAPI)(const char* fileName, const char* mode, uint* dataSize);

class IOUtil
{
public:
	static GetFileDataAPI	s_GetFileDataAPI; // ���Ը��Ķ�ȡ�ļ��Ľӿ�
public:
	static uint8* GetFileData(const char* fileName, const char* mode, uint* dataSize);

protected:
	// Ĭ�ϵĻ�ȡ�ļ����ݽӿ�
	static uint8* DefaultGetFileDataAPI(const char* fileName, const char* mode, uint* dataSize);
};