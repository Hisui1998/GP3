#include "DxLib.h"	// DxLibײ���؂��g�p
#include "ImageManager.h"


std::unique_ptr<ImageManager, ImageManager::ImageManagerDeleter> ImageManager::s_Instance(new ImageManager());

const VEC_INT & ImageManager::GetID(std::string f_name)
{
	// f_name�̉摜ID�͂���̂��H
	if (imageMap.find(f_name) == imageMap.end())
	{
		imageMap[f_name].resize(1);
		imageMap[f_name][0] = LoadGraph(f_name.c_str(), true);	// f_name�̉摜ID��ǂݍ��݁A�n���h�����쐬����
	}
	return imageMap[f_name]; // f_name�̉摜ID�������
}

const VEC_INT & ImageManager::GetID(std::string f_name, VECTOR2 divSize, VECTOR2 divCnt, VECTOR2 chipOffset)
{
	if (imageMap.find(f_name) == imageMap.end())
	{
		imageMap[f_name].resize(divCnt.x * divCnt.y);
		LoadDivGraph(f_name.c_str(), divCnt.x*divCnt.y, divCnt.x, divCnt.y, divSize.x, divSize.y, &imageMap[f_name][0], true);
	}
	return imageMap[f_name];	// f_name�̉摜ID�������
}

ImageManager::ImageManager()
{
}


ImageManager::~ImageManager()
{
}
